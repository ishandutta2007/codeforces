#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>

typedef std::pair<int, int> ii;
typedef std::pair<int, ii> i3;
typedef long long ll;

const int ms = 1001000;

int size[ms];
int c = 0;
int buffer[ms * 22];
int cost[ms];
int *tree[ms];
int temp[2][ms];
ll ans[ms];
ll sum[ms];
std::vector<i3> qries[ms];

int main() {
	int n, m;
	std::cin >> n >> m;
	for(int i = 2; i <= n; i++) {
		scanf("%i", cost + i);
	}
	for(int i = n; i > 0; i--) {
		//std::cout << "building " << i << ":";
		if(i + i > n) {
			size[i] = 1;
			tree[i] = &buffer[c];
			c++;
		} else if(i + i + 1 > n) {
			size[i] = 2;
			tree[i] = &buffer[c];
			c += 2;
			tree[i][1] = cost[i + i];
		} else {
			size[i] = 1 + size[i + i] + size[i + i + 1];
			for(int j = 0; j < size[i + i]; j++) {
				temp[0][j] = tree[i + i][j] + cost[i + i];
			}
			for(int j = 0; j < size[i + i + 1]; j++) {
				temp[1][j] = tree[i + i + 1][j] + cost[i + i + 1];
			}
			tree[i] = &buffer[c];
			c += size[i];
			std::merge(temp[0], temp[0] + size[i + i], temp[1], temp[1] + size[i + i + 1], tree[i] + 1);
		}
		/*for(int j = 0; j < size[i]; j++) {
			std::cout << ' ' << tree[i][j];
		}
		std::cout << '\n';*/
	}
	//std::cout << "got here\n";
	for(int i = 0; i < m; i++) {
		int on, want;
		scanf("%i %i", &on, &want);
		ll ori = want;
		while(on && want > 0) {
			int r = std::upper_bound(tree[on], tree[on] + size[on], want) - tree[on];
			want -= cost[on];
			int l = 0;
			if(on > 1) {
				l = std::upper_bound(tree[on], tree[on] + size[on], want - cost[on]) - tree[on];
			}
			//std::cout << "on " << on << ", got (" << l << ", " << r << "), wanted was " << want + cost[on] << "\n";
			qries[on].emplace_back(i, ii(l, r));
			ans[i] += (ll) (want + cost[on]) * (r - l);
			ans[i] += (ll) 2 * l * cost[on];
			on /= 2;
		}
		//std::cout << "got " << ans[i] / ori << ", ans is " << ans[i] << "\n";
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < size[i]; j++) {
			sum[j + 1] = sum[j] + tree[i][j];
		}
		for(auto seg : qries[i]) {
			//std::cout << i << ": qry (" << seg.first << ", " << seg.second.first << ", " << seg.second.second << ") got " << sum[seg.second.second] - sum[seg.second.first] << '\n';
			ans[seg.first] -= sum[seg.second.second] - sum[seg.second.first];
		}
	}
	for(int i = 0; i < m; i++) {
		printf("%lli\n", ans[i]);
	}
}