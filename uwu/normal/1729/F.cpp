#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n = s.size();
		vector<int>a(n+1);
		vector<int>psa(n+1);
		for(int i = 1; i<=n; i++){
			a[i] = s[i-1]-'0';
			psa[i] = psa[i-1]+a[i];
		}
		int w,m;
		cin >> w >> m;
		vector<vector<int>>dp(9);
		for(int i = w; i<=n; i++){
			int v = psa[i]-psa[i-w];
			dp[v%9].push_back(i-w+1);
		}
		while(m--){
			int l,r,k;
			cin >> l >> r >> k;
			int val = psa[r]-psa[l-1];
			pair<int,int>ans = {(int)1e9,(int)1e9};
			bool f = false;
			for(int i = 0; i<9; i++){
				for(int j = 0; j<9; j++){
					if((i*val+j)%9==k){
						if(i==j&&dp[i].size()>=2){
							ans = min(ans,make_pair(dp[i][0],dp[i][1]));
							f = true;
						}
						if(i!=j&&dp[i].size()&&dp[j].size()){
							ans = min(ans,make_pair(dp[i][0],dp[j][0]));
							f = true;
						}
					}
				}
			}
			if(f){
				cout << ans.first << " " << ans.second << "\n";
			}
			else{
				cout << "-1 -1\n";
			}
		}
	}
	return 0;
}