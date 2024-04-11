#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
using pii = pair<int,int>;
#define pb push_back
#define fir first
#define sec second
const ll oo = 0x3f3f3f3f3f3f3f3f; 

int n; 
int a[200000]; 
multiset<pii> S; 
int dt[200000]; 

int main() {
	scanf( "%d", &n ); 
	for (int i = 0; i < n; ++i) {
		scanf( "%d", &a[i] ); 
		S.insert({a[i],i}); 
	}
	ll r = 0, x = 0; 
	while (!S.empty()) {
		auto u = S.begin(); 
		auto nxt = S.lower_bound({u->fir,x}); 
		if (nxt == S.end() || nxt->fir != u->fir) {
			nxt = S.begin(); 
			r++; 
		}
		dt[nxt->sec] = r; 
		x = nxt->sec; 
		S.erase(nxt); 
	}
	ll ans = (r+1)*n; 
	for (int i = 0; i < n; ++i) 
		ans -= r-dt[i]; 
	cout<<ans<<endl; 
}