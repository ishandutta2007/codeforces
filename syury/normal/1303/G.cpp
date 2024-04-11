//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

const int N = (int)2e5 + 5;

int n;
vector<int> gr[N];
int a[N];
ll ans = 0;
int sz[N];
int d[N];
bool used[N];
ll path[N];
ll car[N], rcar[N];
ll csum[N];
int ptr = 0;
pair<ll, ll> lines[N];
pair<ll, ll> qs[N];

void calc_sz(int v, int p){
    sz[v] = 1;
    for(int u: gr[v]){
        if(u == p || used[u])
            continue;
        calc_sz(u, v);
        sz[v] += sz[u];
    }
}

void add_subtree(int v, int p = -1){
    car[v] = path[v] + (p == -1 ? 0 : car[p]);
    rcar[v] += (1 + d[v]) * 1ll * a[v];
    qs[ptr] = {d[v], car[v]};
    lines[ptr] = {csum[v], rcar[v]};
    ++ptr;
    for(int u: gr[v]){
        if(used[u] || u == p)
            continue;
        path[u] = path[v] + a[u];
        d[u] = d[v] + 1;
        rcar[u] = rcar[v];
        csum[u] = csum[v] + a[u];
        add_subtree(u, v);
    }
}

void centroid(int v){
    calc_sz(v, -1);
    int half = sz[v]>>1;
    int prv = -1;
    while(1){
        int msz = 0, mx = -1;
        for(int u: gr[v]){
            if(used[u])continue;
            if(u != prv){
                if(msz < sz[u]){msz = sz[u]; mx = u;}
            }
        }
        prv = v;
        if(msz <= half)
            break;
        v = mx;
    }
    used[v] = 1;
    ans = max(ans, (ll)a[v]);
    for(int kek = 0; kek < 2; kek++){
        LineContainer hull;
        hull.add(a[v], a[v]);
        for(int u: gr[v]){
            if(used[u])
                continue;
            ptr = 0;
            d[u] = 1;
            path[u] = a[u];
            csum[u] = a[u] + a[v];
            rcar[u] = a[v];
            add_subtree(u);
            for(int i = 0; i < ptr; i++){
                ll cu = hull.query(qs[i].X) + qs[i].Y;
                ans = max(ans, cu);
            }
            for(int i = 0; i < ptr; i++){
                hull.add(lines[i].X, lines[i].Y);
                ans = max(ans, lines[i].Y);
            }
        }
        reverse(all(gr[v]));
    }
    for(int u: gr[v])
        if(!used[u])
            centroid(u);
}

void solve(){
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int v, u;
        cin >> v >> u;
        --v; --u;
        gr[v].push_back(u);
        gr[u].push_back(v);
    }
    for(int i = 0; i < n; i++)
        cin >> a[i];
    centroid(0);
    cout << ans << endl;
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(16);
    int T = 1;
    while(T--)
        solve();
    return 0;
}