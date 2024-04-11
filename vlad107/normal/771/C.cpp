#include <functional>
#include <iostream>
#include <cmath>
#include <vector>
#include <memory.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

int main() {
  	int n, k;
	scanf("%d%d", &n, &k);
	vector<vector<int>> g(n);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x; --y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	vector<vector<pair<int, long long>>> f(n, vector<pair<int, long long>>(k + 1));
	long long ans = 0;
	function<void(int, int, int)> dfs = [&](int x, int px, int dep) {
	  	f[x][dep%k] = {1, dep};	
		for (int y: g[x]) {
			if (y != px) {
				dfs(y, x, dep + 1);
				for (int rx = 0; rx < k; rx++) if (f[x][rx].first != 0) {
				  	for (int ry = 0; ry < k; ry++) if (f[y][ry].first != 0) {
						int rem = (rx + ry - ((2 * dep) % k) + k) % k;
					  	//cerr << x << " " << y << " " << rx << " " << ry << ": " << rem << endl;
						long long cost = f[x][rx].first * 1LL * f[y][ry].second + 
						  				 f[x][rx].second * 1LL * f[y][ry].first;
						cost -= 2LL * dep * f[x][rx].first * f[y][ry].first;
						if (rem != 0) {
							cost += (k - rem) * 1LL * f[x][rx].first * f[y][ry].first;
						}
						ans += cost / k;
					}
				}
				for (int j = 0; j < k; j++) {
					f[x][j] = {f[y][j].first + f[x][j].first, f[y][j].second + f[x][j].second};
				}
			}
		}
	};
	dfs(0, -1, 0);
	cout << ans << endl;
}