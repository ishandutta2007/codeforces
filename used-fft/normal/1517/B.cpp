#include <bits/stdc++.h>
using namespace std;
#define int long long

const int D = 2050;

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--){
		int n, m; cin >> n >> m;
		int a[n][m];
		vector<array<int, 3>> b;
		for(int i=0; i<n; ++i){
			for(int j=0; j<m; ++j){
				cin >> a[i][j];
			}
			sort(a[i], a[i]+m);
			for(int j=0; j<m; ++j){
				b.push_back({a[i][j], i, j});
			}
		}
		sort(b.begin(), b.end());

		int p[n]; fill(p, p+n, m);
		int add[n]; fill(add, add+n, 0LL);

		vector<int> ans[n];
		for(auto &i : b){
			if(p[i[1]] <= i[2]) continue;
			ans[i[1]].push_back(i[0]);
			for(int j=0; j<n; ++j){
				if(j == i[1]) continue;
				--p[j];
				ans[j].push_back(a[j][p[j]]);
			}
		}
		for(int i=0; i<n; ++i){
			for(int j=0; j<m; ++j){
				cout << ans[i][j] << ' ';
			}
			cout << '\n';
		}
	}
}