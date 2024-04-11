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

void solve() {
	int n, m, k; cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);
    vector<int> asum(n + 1, 0), bsum(m + 1, 0);
    rep(i, n) {
        cin >> a[i];
        asum[i + 1] = asum[i] + a[i];
    }
    rep(i, m) {
        cin >> b[i];
        bsum[i + 1] = bsum[i] + b[i];
    }
    int ans = 0;
    for(int i = 1; i * i <= k; ++i) {
        if(k % i == 0) {
            int j = k / i;
            //i * (k / i)
            int re1 = 0, re2 = 0;
            for(int x = 0; x + i <= n; ++x) {
                if(asum[x + i] - asum[x] == i) {
                    ++re1;
                }
            }
            for(int x = 0; x + j <= m; ++x) {
                if(bsum[x + j] - bsum[x] == j) {
                    ++re2;
                }
            }
            ans += re1 * re2;
            if(j == i) continue;
            //(k / i) * i
            re1 = 0, re2 = 0;
            for(int x = 0; x + j <= n; ++x) {
                if(asum[x + j] - asum[x] == j) {
                    ++re1;
                }
            }
            for(int x = 0; x + i <= m; ++x) {
                if(bsum[x + i] - bsum[x] == i) {
                    ++re2;
                }
            }
            ans += re1 * re2;
        }
    }
    cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}