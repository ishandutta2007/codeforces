#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

using pll = pair<ll,ll>; 
const ll mod = (ll)1e9+7; 

const int maxn = 100007; 

int n; 
vi e[maxn]; 
ll U[maxn], D[maxn]; 
pair<ll,int> tree[maxn]; 

ll getmul(ll a, ll k) {
	if (k == 0) return 1; 
	ll ret = getmul(a, k/2); 
	ret = (ret * ret) % mod; 
	if (k & 1) ret = (ret * a) % mod; 
	return ret; 
}

ll inv(ll x) {
	return getmul(x, mod-2); 
}

#define fors(i) for (auto i : e[x]) if (i!=p) 
void dfsD(int x, int p) {
	tree[x] = {1,0}; 
	fors(i) {
		dfsD(i,x); 
		(tree[x].fir *= D[i]) %= mod; 
		tree[x].sec++; 
	}
	D[x] = tree[x].fir; 
	if (tree[x].sec > 0) (D[x] *= 2) %= mod; 
}

ll ans = 0; 
void dfsU(int x, int p) {
	if (p) {
		(tree[x].fir *= U[x]) %= mod; 
		tree[x].sec++; 
	}
	ans = (ans + tree[x].fir) % mod; 
	if (tree[x].sec > 0) ans = (ans + tree[x].fir) % mod; 
	fors(i) {
		U[i] = tree[x].fir * inv(D[i]) % mod; 
		if (tree[x].sec - 1 > 0) (U[i] *= 2) %= mod; 
		dfsU(i, x); 
	}
}

int main() {
	scanf( "%d", &n ); 
	for (int i = 1; i < n; ++i) {
		int a, b; 
		scanf( "%d%d", &a, &b ); 
		e[a].pb(b); 
		e[b].pb(a); 
	}
	dfsD(1, 0); 
	dfsU(1, 0); 
	cout<<ans<<endl; 
}