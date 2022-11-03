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

int n, a, r, m; 
vector<int> h;
vector<int> sum;

int f(int cnta, int cntb) {
    if(cnta > cntb) {
        return m * cntb + a * (cnta - cntb);
    } else {
        return m * cnta + r * (cntb - cnta);
    }
}

void solve() {
	cin >> n >> a >> r >> m;
    h.resize(n);
    sum.assign(n + 1, 0);
    rep(i, n) {
        cin >> h[i];
    }
    sort(all(h));
    rep(i, n) {
        sum[i + 1] = sum[i] + h[i];
    }
    int ans = INF;
    // all remove
    int res = 0;
    rep(i, n) {
        res += h[i] * r;
    }
    chmin(ans, res);
    //
    //all add
    res = 0;
    rep(i, n) {
        res += (h[n - 1] - h[i]) * a;
    }
    chmin(ans, res);
    //
    //
    rep(i, n - 1) {
        int coa = i + 1, cor = n - (i + 1);
        int suma = coa * h[i] - sum[i + 1];
        int sumr = (sum[n] - sum[i + 1]) - cor * h[i + 1];
        int sa = h[i + 1] - h[i];
        if(a + r <= m) {
            chmin(ans, a * suma + r * sumr + min(coa * sa * a, cor * sa * r));
        } else {
            int x = (sumr + sa * cor - suma) / n;
            chmin(ans, f(suma, sumr + cor * sa));
            chmin(ans, f(suma + coa * sa, sumr));
            if(0 <= x && x <= sa) {
                chmin(ans, f(suma + coa * x, sumr + cor * (sa - x)));
            }
            if(0 <= x + 1 && x + 1 <= sa) {
                chmin(ans, f(suma + coa * (x + 1), sumr + cor * (sa - x - 1)));
            }
        }
    }
    //
    cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	//GCJ
	// int t; cin >> t;
	// rep(i, t) {
	// 	cout << "Case #" << i + 1 << ": ";
	// 	solve();
	// }
	solve();
    return 0;
}