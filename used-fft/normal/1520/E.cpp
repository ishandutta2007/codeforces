#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--){
		int n; cin >> n;
		string s; cin >> s;
		int curr = 0;
		vector<int> a;
		for(int i=0; i<n; ++i){
			if(s[i] == '*'){
				a.push_back(i-curr);
				++curr;
			}
		}
		int prev = 0;
		sort(a.begin(), a.end());
		n = a.size();
		int sum = accumulate(a.begin(), a.end(), 0LL);
		int ans = 1e18;
		for(int i=0; i<n; ++i){
			sum -= a[i];
			ans = min(ans, a[i] * i - prev + sum - a[i] * (n - i - 1));
			prev += a[i];
		}
		if(!curr) ans = 0;
		cout << ans << '\n';
	}
}