#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	ll ans=(ll)n*(n+1)/2;
	unordered_map<int, ll> mp{{0, 1}};
	for(int i=0, px=0, ai; i<n; ++i) {
		cin >> ai, px^=ai;
		if(px>>(k-1)&1)
			px^=(1<<k)-1;
		++mp[px];
	}
	for(auto it=mp.begin(); it!=mp.end(); ++it) {
		ll a=it->second/2, b=it->second-a;
		ans-=a*(a-1)/2+b*(b-1)/2;
	}
	cout << ans;
}