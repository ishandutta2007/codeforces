#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

const int ms = 100100;

int a[ms], p[ms];
int ans[ms];

int main() {
	int n, h;
	std::cin >> n >> h;
	for(int i = 0; i < n; i++) {
		scanf("%d", a + i);
		p[i] = i;
	}
	
	if(n < 5) {
		int val = 1e9;
		for(int i = 0; i < (1 << n); i++) {
			int mn = 1e9, mx = -1e9;
			for(int j = 0; j < n; j++) {
				for(int k = j + 1; k < n; k++) {
					int cur = a[j] + a[k];
					if(((i >> j) ^ (i >> k)) % 2 == 1) {
						cur += h;
					}
					mn = std::min(mn, cur);
					mx = std::max(mx, cur);
				}
			}
			if(mx - mn < val) {
				for(int j = 0; j < n; j++) {
					ans[j] = (i >> j) % 2 + 1;
				}
				val = mx - mn;
			}
		}
	} else {
		std::sort(p, p + n, [](int l, int r) -> bool {return a[l] < a[r];});
		for(int i = 0; i < n; i++) {
			ans[i] = 1;
		}
		int val = (a[p[n-1]]+a[p[n-2]]) - (a[p[1]] + a[p[0]]);
		int idx = -1;
		if(std::max(a[p[0]] + a[p[n-1]] + h, a[p[n-2]] + a[p[n-1]]) - std::min(a[p[0]] + a[p[1]] + h, a[p[1]] + a[p[2]]) < val) {
			idx = 0;
			val = std::max(ans[p[0]] + ans[p[n-1]] + h, ans[p[n-2]] + ans[p[n-1]]) - (ans[p[0]] + ans[p[1]] + h);
			ans[p[0]] = 2;
		}
	}
	int mx = -1e9, mn = 1e9;
	std::vector<int> parts[2];
	for(int i = 0; i < n; i++) {
		parts[ans[i] - 1].push_back(a[i]);
	}
	std::sort(parts[0].begin(), parts[0].end());
	std::sort(parts[1].begin(), parts[1].end());
	std::vector<int> vals[2];
	for(int i = 0; i < 2; i++) {
		if(parts[i].size() > 4) {
			vals[i].push_back(parts[i][0]);
			vals[i].push_back(parts[i][1]);
			vals[i].push_back(parts[i][parts[i].size()-1]);
			vals[i].push_back(parts[i][parts[i].size()-2]);
		} else {
			vals[i] = parts[i];
		}
		for(int j = 0; j < vals[i].size(); j++) {
			for(int k = j + 1; k < vals[i].size(); k++) {
				mx = std::max(mx, vals[0][j] + vals[0][k]);
				mn = std::min(mn, vals[0][j] + vals[0][k]);	
			}
		}
	}
	for(int i = 0; i < vals[0].size(); i++) {
		for(int j = 0; j < vals[1].size(); j++) {
			mx = std::max(mx, vals[0][i] + vals[1][j] + h);
			mn = std::min(mn, vals[0][i] + vals[1][j] + h);	
		}
	}
	std::cout << std::max(0, mx - mn) << std::endl;
	for(int i = 0; i < n; i++) {
		printf("%d%c", ans[i], i + 1 == n ? '\n' : ' ');
	}
}