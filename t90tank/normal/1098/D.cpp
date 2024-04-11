#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
using pii = pair<ll,ll>; 
using db = double; 
using vi = vector<ll>; 
#define fir first
#define sec second
#define pb push_back
#define lowbit(x) ((x)&(-(x))) 

const ll maxn = 500000; 
const ll oo = 1000000007; 

struct node {
	ll left, right, sum; 
};

multiset<ll> S; 
node e[10000000]; 
ll tot = 0; 
ll tree = 0; 

void add(ll &T, ll l, ll r, ll x, ll f) {
	if (T == 0) T = ++tot; 
	e[T].sum += x*f; 
	if (l == r) return; 
	ll m = (l+r)/2; 
	if (x <= m) add(e[T].left, l, m, x, f); 
	else add(e[T].right, m+1, r, x, f); 
}

ll cnt(ll T, ll l, ll r, ll a, ll b) {
	if (T == 0) return 0; 
	if (a <= l && b >= r) return e[T].sum;  
	ll m = (l+r)/2; 
	ll ret = 0; 
	if (a <= m) ret += cnt(e[T].left, l, m, a, b); 
	if (b > m) ret += cnt(e[T].right, m+1, r, a, b); 
	return ret; 
}

int main() {
	ll q; 
	scanf( "%lld", &q ); 
	while (q--) {
		char op[10]; 
		ll x; 
		scanf( "%s%lld", op, &x ); 
		if (op[0] == '+') {
			add(tree, 1, oo, x, 1); 
			S.insert(x); 
		}
		else {
			add(tree, 1, oo, x, -1); 
			S.erase(S.find(x)); 
		}
		ll ans = 0; 
		if (S.size() <= 1) {
			puts( "0" ); 
			continue; 
		}
		ll nows = *S.begin(); 
		while (1) {
			auto t = S.lower_bound(nows*2); 
			if (t == S.end()) break; 
			ll nexts = cnt(tree, 1, oo, 1, (*t)-1); 
			if (nexts * 2 < (*t)) ans++; 
			nows = nexts + (*t); 
		//	cout<<nows<<endl; 
		}
		printf( "%lld\n", ll(S.size())-1-ans ); 
	}
}