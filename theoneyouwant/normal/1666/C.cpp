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


 
signed main()
{
    
	#ifdef LOCAL
    freopen("stuff.in", "r", stdin);
    //freopen("stuff.out", "w", stdout);
    #endif
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	vector <pll> v(3);
    vll xs(3), ys(3);
    rep(i, 0, 3) {
        cin >> v[i].ff >> v[i].ss;
        xs[i] = v[i].ff;
        ys[i] = v[i].ss;
    }
    sort(all(xs));
    sort(all(ys));
    // cout << ys[0] << " " << ys[2] << ln;
    vector <pair <pll, pll>> res;
    if(ys[0] != ys[2])
        res.push_back({{xs[1], ys[0]}, {xs[1], ys[2]}});

    rep(i, 0, 3) 
        if(v[i].ff != xs[1]) {
            res.push_back({{xs[1], v[i].ss}, v[i]});
        }
    cout << sz(res) << ln;
    rep(i, 0, sz(res)) {
        cout << res[i].ff.ff << " " << res[i].ff.ss << " " << res[i].ss.ff << " " << res[i].ss.ss << ln;
    }
 
 
    
 
    return 0;
}