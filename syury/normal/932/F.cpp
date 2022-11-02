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

const int N = (int)1e5 + 5;

int n;
vector<int> gr[N];
int a[N], b[N];
LineContainer hull[N];
vector<pair<ll, ll> > raw[N];
ll dp[N];

void dfs(int v, int p = -1){
    dp[v] = (ll)2e18;
    int big = -1;
    for(int u: gr[v]){
        if(u == p)
            continue;
        dfs(u, v);
        dp[v] = min(dp[v], -hull[u].query(a[v]));
        if(big == -1 || raw[u].size() > raw[big].size())
            big = u;
    }
    if(big == -1){
        dp[v] = 0;
    }
    else{
        raw[v].swap(raw[big]);
        hull[v].swap(hull[big]);
        for(int u: gr[v]){
            if(u != p && u != big){
                for(auto [k, b]: raw[u]){
                    raw[v].emplace_back(k, b);
                    hull[v].add(k, b);
                }
            }
        }
    }
    raw[v].emplace_back(-b[v], -dp[v]);
    hull[v].add(-b[v], -dp[v]);
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    for(int i = 0; i < n - 1; i++){
        int v, u;
        cin >> v >> u;
        --v; --u;
        gr[v].push_back(u);
        gr[u].push_back(v);
    }
    dfs(0);
    for(int i = 0; i < n; i++)
        cout << dp[i] << ' ';
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