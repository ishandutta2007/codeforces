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
	int n, m, d; cin >> n >> m >> d;
    vector<int> c(m);
    int sum = 0;
    rep(i, m) {
        cin >> c[i];
        sum += c[i];
    }
    if(n - sum > (m + 1) * (d - 1)) {
        cout << "NO" << endl;
        return;
    }
    int re = n - sum, cur = 0, now = 0;
    cout << "YES" << endl;
    vector<int> ans(n, -1);
    while(cur < n) {
        if(re - (d - 1) >= 0) {
            re -= (d - 1);
            //cerr << re << endl;
            rep(i, (d - 1)) {
                ans[cur] = 0;
                ++ cur;
            }
            rep(i, c[now]) {
                ans[cur] = now + 1;
                ++ cur;
            }
            ++ now;
        } else if(re > 0) {
            rep(i, re) {
                ans[cur] = 0;
                ++ cur;
            }
            re = 0;
            rep(i, c[now]) {
                ans[cur] = now + 1;
                ++ cur;
            }
            ++ now;
        } else {
            rep(i, c[now]) {
                ans[cur] = now + 1;
                ++ cur;
            }
            ++ now;
        }
        //cerr << re << endl;
    }
    rep(i, n) {
        if(i) cout << " ";
        cout << ans[i];
    }
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