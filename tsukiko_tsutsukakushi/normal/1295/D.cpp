/**
 *    author:  otera    
**/
#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<deque>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

#define int long long
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
typedef long double ld;
const int inf=1e9+7;
const ll INF=1LL<<60 ;
const ll mod=1e9+7 ;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<int, int> P;
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define pb push_back
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

vector<ll> pf(ll x) {
    vector<ll> res;
    for(ll i = 2; i * i <= x; ++i) {
        if(x % i != 0) continue;
        while(x % i == 0) {
            x /= i;
        }
        res.pb(i);
    }
    if(x != 1) res.pb(x);
    return res;
}

void solve() {
	ll a, m; cin >> a >> m;
    ll d = gcd(a, m);
    m /= d, a /= d;
    vector<ll> p = pf(m);
    cerr << p.size() << endl;
    ll ans = 0;
    for(int bit = 0; bit < (1<<((int)p.size())); ++bit) {
        int cnt = __builtin_popcount(bit);
        ll f = 1LL;
        rep(i, (int)p.size()) {
            if(bit & (1<<i)) {
                f *= p[i];
            }
        }
        if(cnt % 2 == 0) {
            ans += (a + m - 1) / f - (a - 1) / f;
        } else {
            ans -= (a + m - 1) / f - (a - 1) / f;
        }
    }
    cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	int t; cin >> t; rep(i, t)solve();
	//solve();
    return 0;
}