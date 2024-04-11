#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int t, n, m, k, x[N], a, b, c, d, h, sz;
long long ans[N];

vector <int> C[N], D[N], H[N];

#define ll long long
#define pii pair <int, int> 

map < int , int> Map[N];

int main() {
	for(cin >> t; t --;) {
		scanf("%d%d%d", &n, &m, &k);
		for(int i = 1; i <= n; ++ i) scanf("%d", &x[i]);
		sz = 0;
		for(int i = 1; i <= k * 2 + 5; ++ i) {
			C[i].clear(); D[i].clear(); H[i].clear();
			ans[i] = -1e18;
		}
		for(int i = 1; i <= n; ++ i) Map[i].clear();
		if(!Map[1][1]) Map[1][1] = ++ sz;
 		for(int i = 1; i <= k; ++ i) {
			scanf("%d%d%d%d%d", &a, &b, &c, &d, &h);
			if(!Map[a][b]) Map[a][b] = ++ sz;
			if(!Map[c][d]) Map[c][d] = ++ sz;
			C[Map[a][b]].push_back(Map[c][d]);
			H[Map[a][b]].push_back(h);
		}
		if(!Map[n][m]) Map[n][m] = ++ sz;
		ans[Map[1][1]] = 0;
		for(int i = 1; i <= n; ++ i) {
			vector <int> All, id;
			for(auto V : Map[i]) All.push_back(V.first), id.push_back(V.second);
			ll L = -1e18, R = -1e18;
			for(int j = All.size() - 1;  j >= 0; -- j) {
				// (j, ans[j])
				int it = id[j];
				L = max(L, ans[it] - 1LL * All[j] * x[i]);
				ans[it] = max(ans[it], L + 1LL * All[j] * x[i]);
			}
			for(int j = 0; j < All.size(); ++ j) {
				int it = id[j];
				R = max(R, ans[it] + 1LL * All[j] * x[i]);
				ans[it] = max(ans[it], R - 1LL * All[j] * x[i]);
			}
			for(int j = 0; j < All.size(); ++ j) {
				// (j, ans[j])
				int it = id[j];
				if(ans[it] < -1e16) continue;
				for(int a = 0; a < (int)C[it].size(); ++ a) {
					int i2 = C[it][a], h = H[it][a];
					ans[i2] = max(ans[i2], ans[it] + h);
				}
			}
		}
		
		if(ans[Map[n][m]] < -1e16) {
			puts("NO ESCAPE");
			continue;
		} else {
			cout << -ans[Map[n][m]] << endl;
		}
	}
}