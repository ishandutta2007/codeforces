#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
void solve(){
	ll n, m;
	cin >> n >> m;
	ll s = 2 * (n-1 + m-1);
	set<ll> factors;
	for(ll a = 1; a * a <= s; a++){
		if(s % a == 0){
			factors.insert(a);
			factors.insert(s / a);
		}
	}
	set<ll> gs;
	for(int i = 0; i < 16; i++){
		vector<ll> d = {n-2, m-2, n-2, m-2};
		for(int j = 0; j < 4; j++){
			if(i & (1 << j)){
				d[j]++;
			} else {
				d[(j+1) % 4]++;
			}
		}
		ll g = d[0];
		for(ll x : d) g = gcd(g, x);
		gs.insert(g);
	}
	vector<ll> ans;
	for(ll f : factors){
		for(ll g : gs){
			if(g % f == 0){
				ans.push_back(f);
				break;
			}
		}
	}
	cout << ans.size();
	for(ll x : ans){
		cout << " " << x;
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}