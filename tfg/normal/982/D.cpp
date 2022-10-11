#include <iostream>
#include <vector>
#include <utility>
#include <cstdio>
#include <algorithm>

typedef std::pair<int, int> ii;

const int ms = 100100;

int cur_ans = 0;
int par[ms], size[ms];
int get_par(int x) {
	if(x == par[x]) return par[x];
	else return par[x] = get_par(par[x]);
}

int freq[ms];
int tot_freq;

void add(int x) {
	if(freq[x] == 0) {
		tot_freq++;
	}
	freq[x]++;
}

void rem(int x) {
	if(freq[x] == 1) {
		tot_freq--;
	}
	freq[x]--;
}

void make_union(int a, int b) {
	if(par[a] == 0 || par[b] == 0) return;
	a = get_par(a);
	b = get_par(b);
	if(a == b) return;
	rem(size[a]);
	rem(size[b]);
	size[a] += size[b];
	add(size[a]);
	par[b] = a;
	cur_ans--;
}

std::vector<ii> events;

int main() {
	int ans[] = {-1, -1};
	int n;
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		int val;
		scanf("%d", &val);
		events.push_back(ii(val, i));
	}
	std::sort(events.begin(), events.end());
	for(auto e : events) {
		cur_ans++;
		par[e.second] = e.second;
		size[e.second] = 1;
		add(1);
		make_union(e.second, e.second + 1);
		make_union(e.second, e.second - 1);
		//std::cout << "including until (" << e.first << ", " << e.second << ") has answer " << cur_ans << std::endl;
		if(cur_ans > ans[0] && tot_freq == 1) {
			ans[0] = cur_ans;
			ans[1] = e.first + 1;
		}
	}
	std::cout << ans[1] << std::endl;
}