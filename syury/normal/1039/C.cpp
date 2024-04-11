#include<bits/stdc++.h>
#include<bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define F(i, l, r) for(int i = (l); i < (r); i++)
#define E(i, l, r) for(int i = (l); i <= (r); i++)
#define DF(i, l, r) for(int i = (l); i >= (r); i--)
#define I(x, a) for(auto x : (a))
#define mp make_pair
#define X first
#define Y second
#define clean(x) memset((x), 0, sizeof(x))
#define ret return
#define cont continue
#define brk break
#define ins insert
#define all(x) (x).begin(),(x).end()
#define sync ios_base::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define y1 fjfg
#define tm shjfhg

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)5e5 + 5;
const int mod = (int)1e9 + 7;

ll pw[N];
int p[N];
int tm[N];
vector<pii> edges[N];
ll c[N];
int n, m, k;
int comps, gt = 0;
ll ans = 0;

int find_set(int v){
	if(tm[v] < gt){
		tm[v] = gt;
		return p[v] = v;
	}
	else return v == p[v] ? v : p[v] = find_set(p[v]);
}

void unite(int v, int u){
	v = find_set(v);
	u = find_set(u);
	if(v == u)
		return;
	--comps;
	p[v] = u;
}

signed main() {
	sync;
	pw[0] = 1;
	F(i, 1, N)
		pw[i] = pw[i - 1] * 2 % mod;
	cin >> n >> m >> k;
	F(i, 0, n)cin >> c[i];
	map<ll, int> id;
	int cid = 0;
	F(i, 0, m){
		int v, u;
		cin >> v >> u;
		--v; --u;
		ll x = c[v]^c[u];
		if(!id.count(x))
			id[x] = cid++;
		int p = id[x];
		edges[p].pb({v, u});
	}
	ans = pw[n] * 1ll * (pw[k] - cid);
	F(i, 0, cid){
		++gt;
		comps = n;
		I(e, edges[i])
			unite(e.X, e.Y);
		ans += pw[comps];
		ans %= mod;
	}
	cout << (ans + mod)%mod;
	return 0;
}