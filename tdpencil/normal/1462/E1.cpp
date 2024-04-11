#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		ll arr[n];
		vector<ll> freq(n+3,0);
	   for(int i = 0; i < n;++i){
		   cin >> arr[i];
		   ++freq[arr[i]];
	   }
	   ll ans = 0;
	   for(int i = 1; i <= n;++i){
		   ll x = freq[i],y = freq[i+1],z = freq[i+2];
		   ans += x*y*z + ((x-1)*x*(x-2))/6LL + ((x-1)*x)/2LL * y + x * ((y-1)*y)/2LL + x * ((z-1)*z)/2LL + ((x-1)*x)/2LL * z;
	   }
	   cout << ans << "\n";
	}
}