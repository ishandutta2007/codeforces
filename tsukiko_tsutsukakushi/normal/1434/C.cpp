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
#include<unordered_set>
#include<utility>
#include<cassert>
#include<array>
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
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll a, b, c, d; 

ll num(ll x) {
    ll ret = (x + 1) * a;
    if(x * d - c >= 0) {
        ll j = (x * d - c) / d;
        ret -= (j + 1) * b * c;
        // cerr << ret << " ";
        if(x - j - 1 > 0) {
            ll co = x - j - 1;
            // cerr << b * d * (x - j - 1) * (x - j) / 2 << endl;
            ret -= b * d * (x - j - 1) * (x - j) / 2;
        }
        // cerr << ret << endl;
    } else {
        if(x - 1 >= 0) {
            ret -= b * x * x * d;
            ret += b * d * x * (x - 1) / 2;
        }
    }
    return ret;
}

bool check(ll x) {
    return num(x - 1) < num(x);
}

void solve() {
	cin >> a >> b >> c >> d;
    if(a > b * c) {
        cout << -1 << endl;
        return;
    }
    if(c + 1 <= d) {
        cout << a << endl;
        return;
    }
    // cerr << num(2) << endl;
    ll ok = 0, ng = 1e7;
    while(ng - ok > 1) {
        ll mid = (ok + ng) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    cout << num(ok) << endl;
    // cerr << num(0) << " " << num(1) << " " << num(2) << " " << num(3) << " " << num(4) << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	int t; cin >> t; rep(i, t)solve();
	//solve();
    return 0;
}