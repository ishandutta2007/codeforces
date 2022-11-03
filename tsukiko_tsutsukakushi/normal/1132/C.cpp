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

//#define int long long
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

void solve() {
	int n, q; cin >> n >> q;
    vector<int> l(q), r(q);
    rep(i, q) {
        scanf("%d %d", &l[i], &r[i]);
        -- l[i];
    }
    int ans = 0;
    rep(i, q) {
        vector<int> p(n + 1, 0);
        vector<int> x(n + 1, 0);
        rep(j, q) {
            if(j == i) continue;
            p[l[j]] ++;
            p[r[j]] --;
        }
        rep(j, n) {
            p[j + 1] += p[j];
        }
        rep(j, n + 1) {
            //cerr << p[j] << " ";
            if(p[j] == 1) {
                x[j] ++;
            }
        }
        //cerr << endl;
        vector<int> sx(n + 2, 0);
        rep(j, n) {
            sx[j + 1] = sx[j] + x[j];
            //cerr << sx[j] << " ";
        }
        //cerr << endl;
        int res = 0;
        rep(j, n + 1) {
            if(p[j] > 0) {
                ++ res;
            }
        }
        //cerr << res << endl;
        rep(j, q) {
            if(i == j) continue;
            chmax(ans, res - (sx[r[j]] - sx[l[j]]));
        }
    }
    cout << ans << endl;
}

signed main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}