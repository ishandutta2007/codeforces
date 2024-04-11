#include <iostream>
#include <algorithm>

typedef long long ll;

const int ms = 100100;

int par[ms];
ll size[ms];
int p[ms];

int get_par(int x) {
	if(x == par[x]) {
		return x;
	} else {
		return par[x] = get_par(par[x]);
	}
}

void make_union(int a, int b) {
	a = get_par(a);
	b = get_par(b);
	if(a == b) {
		return;
	}
	//std::cout << "uniting (" << a << ", " << b << ")\n";
	size[a] += size[b];
	par[b] = par[a];
}

int main() {
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		par[i] = i;
		size[i] = 1;
	}
	for(int i = 0; i < n; i++) {
		std::cin >> p[i];
		make_union(i, p[i] - 1);
	}
	ll cur_ans = 0;
	ll ans = 0;
	ll cur_max = 0;
	for(int i = 0; i < n; i++) {
		if(i == get_par(i)) {
			cur_ans += size[i] * size[i];
		}
	}
	ans = cur_ans;
	//std::cout << "got " << ans << "\n";
	for(int i = 0; i < n; i++) {
		if(i == get_par(i)) {
			ans = std::max(ans, cur_ans + cur_max * size[i] * 2);
			cur_max = std::max(cur_max, size[i]);
		}
	}
	std::cout << ans << '\n';
}