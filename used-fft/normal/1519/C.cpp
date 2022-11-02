#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	cin.tie(0)->sync_with_stdio(0);

	int T; cin >> T;
	while(T--){
		int n; cin >> n;
		int u[n], s[n];
		vector<int> a[n];
		for(int &i : u) cin >> i, --i;
		for(int &i : s) cin >> i;

		for(int i=0; i<n; ++i) a[u[i]].push_back(s[i]);

		for(int i=0; i<n; ++i) sort(a[i].rbegin(), a[i].rend());

		for(int i=0; i<n; ++i){
			s[i] = a[i].size();
			for(int j=1; j<s[i]; ++j) a[i][j] += a[i][j-1];
		}

		vector<int> ans(n, 0);

		for(int i=0; i<n; ++i){
			for(int j=1; j<=s[i]; ++j){
				int k = s[i] % j;
				k = s[i] - 1 - k;
				if(k>=0) ans[j-1] += a[i][k];
			}
		}

		for(int i : ans) cout << i << ' ';
		cout << '\n';
	}
}