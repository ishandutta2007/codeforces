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

int extgcd(int a, int b, int &x, int &y) {
    int d = a;
    if(b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1, y = 0;
    }
    return d;
}

void solve() {
	int n; cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    if(n == 1) {
        cout << "1 1" << endl << -a[0] << endl <<  "1 1" << endl << 0 << endl << "1 1" << endl << 0 << endl;
        return;
    }
    int m = n - 1, l = 1;
    vector<int> f(n, -1), s(n, -1);
    rep(i, m) {
        int x, y;
        int d = extgcd(n, m, x, y);
        f[i] = n / d * x * (-a[i]);
        s[i] = m / d * y * (-a[i]);
    }
    for(int i = m; i < n; ++ i) {
        int x, y;
        int d = extgcd(n, l, x, y);
        f[i] = n / d * x * (-a[i]);
        s[i] = l / d * y * (-a[i]);
    }
    cout << 1 << " " << n << endl;
    rep(i, n) cout << f[i] << " ";
    cout << endl;
    cout << 1 << " " << m << endl;
    rep(i, m) cout << s[i] << " ";
    cout << endl;
    cout << m + 1 << " " << n << endl;
    for(int i = m; i < n; ++ i) cout << s[i] << " ";
    cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}