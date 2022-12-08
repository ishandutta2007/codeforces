#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
using pii = pair<int,int>; 
using db = double; 
using vi = vector<int>; 
#define fir first
#define sec second
#define pb push_back
#define lowbit(x) ((x)&(-(x))) 

int n, N; 
ll s; 
ll a[200000]; 
vi q[200000]; 

int main() {
	cin>>n>>s; 
	if (ll(n)*ll(n+1) / 2 < s) {
		puts( "No" ); 
		return 0; 
	}
	int l = 0, r = n; 
	while (l+1 < r) {
		int m = (l+r) / 2;
		ll ss = 0, tot = n; 
		for (ll i = 0,num = 1; tot > 0; i++,num*=m) {
			int tmp = min(tot,num);
			ss += tmp*ll(i+1); 
			tot -= tmp; 
		}
		if (ss <= s) r = m; 
		else l = m; 
	}
	if (r == n) {
		puts( "No" ); 
		return 0; 
	}
	puts( "Yes" ); 
	ll ss = 0, tot = n; 
	N = 0;
	int dep = 0;  
	for (ll i = 0,num = 1; tot > 0; i++,num*=r) {
		ll tmp = min(tot,num);
		ss += tmp*ll(i+1); 
		tot -= tmp; 
		for (ll j = 1; j <= tmp; ++j) {
			a[++N] = i+1; 
			q[i+1].pb(N); 
		}
		dep = i+1; 
	}
	s -= ss;
	ll maxdep = dep + 1; 
	while (s > 0) {
		while (dep > 0 && q[dep].size() == 1) dep--; 
		int tmp = q[dep].back();  q[dep].pop_back(); 
		ll add = min(s, ll(maxdep-dep)); 
		s -= add; 
		q[dep+add].pb(tmp); 
		maxdep = max(dep+add+1,maxdep); 
	}
	int now = 1, d = 0; 
	for (ll i = 2; i < maxdep; ++i) {
		ll c = 0, d = 0; 
		for (auto j : q[i]) {
			printf( "%d ", now-d); 
			c++; 
			if (c == r) {
				q[i-1].pop_back(); 
				c = 0; 
				d++; 
			}
		}
		now += q[i].size(); 
	}
	puts( "" ); 
}