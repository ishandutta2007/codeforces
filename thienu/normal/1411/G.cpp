#include <bits/stdc++.h>

using namespace std;

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset

using ll = long long;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const ll MOD = 998244353;

ll mul(ll a, ll b){
    return a * b % MOD;
}

ll add(ll a, ll b){
    return (a + b) % MOD;
}

ll sub(ll a, ll b){
    return (a - b + MOD) % MOD;
}

ll normalize(ll x){
    return ((x % MOD) + MOD) % MOD;
}

ll binexp(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1) ans = mul(ans, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ans;
}

ll inv(ll x){
    return binexp(x, MOD - 2);
}

// kactl
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
int solveLinear(vvll& A, vll& b, vll& x) {
	int n = sz(A), m = sz(x), rank = 0, br, bc;
	if (n) assert(sz(A[0]) == m);
	vi col(m); iota(all(col), 0);

	rep(i,0,n) {
		ll v, bv = 0;
		rep(r,i,n) rep(c,i,m)
			if ((v = A[r][c]) > bv)
				br = r, bc = c, bv = v;
		if (bv == 0) {
			// rep(j,i,n) if (fabs(b[j]) > eps) return -1;
			break;
		}
		swap(A[i], A[br]);
		swap(b[i], b[br]);
		swap(col[i], col[bc]);
		rep(j,0,n) swap(A[j][i], A[j][bc]);
		bv = inv(A[i][i]);
		rep(j,i+1,n) {
			ll fac = mul(A[j][i], bv);
			b[j] = sub(b[j], mul(fac, b[i]));
			rep(k,i+1,m) A[j][k] = sub(A[j][k], mul(fac,A[i][k]));
		}
		rank++;
	}

	x.assign(m, 0);
	for (int i = rank; i--;) {
		b[i] = mul(b[i], inv(A[i][i]));
		x[col[i]] = b[i];
		rep(j,0,i) b[j] = sub(b[j], mul(A[j][i], b[i]));
	}
	return rank; // (multiple solutions if rank < m)
}

const int B = 512;

void dfs(int u, vvi &adj, vi &vis, vi &grundy){
    if(vis[u]) return;
    vis[u] = 1;
    set<int> s;
    for(int v : adj[u]){
        dfs(v, adj, vis, grundy);
        s.insert(grundy[v]);
    }
    int mex = 0;
    while(s.find(mex) != s.end()){
        mex++;
    }
    debug(u, s, mex);
    grundy[u] = mex;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vvi adj(n);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
    }
    vi grundy(n);
    vi vis(n);
    for(int i = 0; i < n; i++){
        if(vis[i]) continue;
        dfs(i, adj, vis, grundy);
    }

    debug(grundy);

    ll p = inv(n+1);

    vvll A(B, vll(B));
    vll b(B);
    for(int i = 0; i < B; i++){
        A[i][i] = normalize(-1);
        for(int j = 0; j < n; j++){
            A[i][i^grundy[j]] = add(A[i][i^grundy[j]], p);
        }
        if(i != 0){
            b[i] = normalize(-p);
        }
    }
    vll x(B);
    solveLinear(A, b, x);
    debug(x);
    cout << x[0] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}