#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ll n ,k;
	cin >> n >> k;
	vector<ll> v(n);
	for(int i =0; i<n; i++){
		cin >> v[i];
	}
	ll ans=0;
	ll point = v[k-1];
	for(int i =0; i <n; i++) {
		if(v[i]&&v[i]>=point) 
			++ans;
	}
	cout << ans;
}