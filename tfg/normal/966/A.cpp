#include <iostream>
#include <cstdio>
#include <set>
#include <cstdlib>

int main() {
	int n, m;
	std::cin >> n >> m;
	int freq[2];
	int v;
	std::cin >> freq[0] >> freq[1] >> v;
	std::set<int> up[2];
	//std::cout << n << ' ' << m << ' ' << freq[0] << ' ' << freq[1] << ' ' << v << std::endl;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < freq[i]; j++) {
			int x;
			scanf("%d", &x);
			up[i].insert(x);
		}
	}
	int q;
	std::cin >> q;
	while(q--) {
		//std::cout << "wtf\n";
		int r1, c1, r2, c2;
		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		int ans = 1e9;
		if(r1 == r2) {
			ans = abs(c1 - c2);
		} else {
			int cost = abs(r1 - r2);
			int t = 0;
			auto it = up[t].lower_bound(c1);
			if(it != up[t].end()) {
				ans = std::min(ans, cost + abs(c1 - *it) + abs(*it - c2));
			}
			if(it != up[t].begin()) {
				it--;
				ans = std::min(ans, cost + abs(c1 - *it) + abs(*it - c2));
			}
			cost = (cost + v - 1) / v;
			t = 1;
			it = up[t].lower_bound(c1);
			if(it != up[t].end()) {
				ans = std::min(ans, cost + abs(c1 - *it) + abs(*it - c2));
			}
			if(it != up[t].begin()) {
				it--;
				ans = std::min(ans, cost + abs(c1 - *it) + abs(*it - c2));
			}
		}
		printf("%d\n", ans);
	}
}