#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		string s;
		cin >> s;
		s = " " + s;
		vector<int>psa(n+1);
		for(int i = 1; i<=n; i++){
			psa[i] = psa[i-1];
			psa[i]+=(s[i]=='B');
		}
		int mx = 0;
		for(int i = k; i<=n; i++){
			mx = max(mx,psa[i]-psa[i-k]);
		}
		cout << k-mx << "\n";
	}
	return 0;
}