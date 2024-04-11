#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;
 
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define repb(i, a, b) for(int i = (a); i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
//#define int ll
#define ln '\n'
//#define pb push_back
#define mp make_pair
#define ff first
#define ss second
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef unsigned long long ull;
typedef long double ld;
const int S = int(2e5)+10;
const ll INF = ll(1e18)+7;
const ll MOD = ll(1e9)+7;
const double eps = 1e-7;
const double PI = 3.141592653589793238;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T> void print(T &v) { trav(x, v) cout << x << " "; cout << ln; }
template <typename T> void read(T &v) { trav(x, v) cin >> x; }

template<class T>
struct SubMatrix {
	vector<vector<T>> p;
	SubMatrix(vector<vector<T>>& v) {
		int R = sz(v), C = sz(v[0]);
		p.assign(R+1, vector<T>(C+1));
		rep(r,0,R) rep(c,0,C)
			p[r+1][c+1] = v[r][c] + p[r][c+1] + p[r+1][c] - p[r][c];
	}
	T sum(int u, int l, int d, int r) {
		return p[d][r] - p[d][l] - p[u][r] + p[u][l];
	}
};

int n;

void assign(vi &par, vector <vi> &rt, int i, int j) {
    int k = rt[i][j];
    if(k > i) {
        par[rt[i][k-1]] = k;
        assign(par, rt, i, k-1);
    }
    if(k < j) {
        par[rt[k+1][j]] = k;
        assign(par, rt, k+1, j);
    }
}
 
signed main()
{
    
	#ifdef LOCAL
    freopen("stuff.in", "r", stdin);
    //freopen("stuff.out", "w", stdout);
    #endif
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;

    vector <vll> dp(n, vll(n, ll(1e18)));
    vector <vi> rt(n, vi(n));
    vi par(n);
    vector <vll> c(n, vll(n));

    rep(i, 0, n)
        rep(j, 0, n)
            cin >> c[i][j];
    SubMatrix<ll> sub(c);
    rep(i, 0, n) {
        rt[i][i] = i;
        dp[i][i] = 0;
    }
    rep(l, 1, n)
        rep(i, 0, n - l) {
            int j = i+l;
            rep(k, i, j+1) {
                ll tot = 0;
                tot += sub.sum(i, 0, k, i);
                tot += sub.sum(i, k, k, n);
                tot += sub.sum(k+1, 0, j+1, k+1);
                tot += sub.sum(k+1, j+1, j+1, n);
                ll val = (k > i ? dp[i][k-1] : 0) + tot + (k < j ? dp[k+1][j] : 0);
                if(val < dp[i][j]) {
                    dp[i][j] = val;
                    rt[i][j] = k;
                }
            }
        }

    assign(par, rt, 0, n-1);
    par[rt[0][n-1]] = -1;
    //cout << dp[0][n-1]<<ln;
    rep(i, 0, n)
        cout << par[i]+1 << " ";
    cout << ln;
    
 
    
 
    
 
    return 0;
}