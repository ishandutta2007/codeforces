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

void solve() {
	int n; cin >> n;
    vector<int> a(n);
    int sum = 0;
    vector<int> b;
    int cur = 0;
    rep(i, n) {
        cin >> a[i];
        if(a[i] == 0) {
            ++ sum;
            ++ cur;
        } else {
            b.push_back(cur);
            cur = 0;
        }
    }
    b.push_back(cur);
    static int dp[85][85][3300];
    rep(i, 85) {
        rep(j, 85) {
            rep(k, 3300) {
                dp[i][j][k] = INF;
            }
        }
    }
    dp[0][0][0] = 0;
    int sz = (int)b.size();
    // rep(i, sz) cerr << b[i] << " \n"[i == sz - 1];
    int s = 0;
    rep(i, sz) {
        s += b[i];
        rep(j, 85) {
            rep(k, 3300) {
                rep(nxt, 85) {
                    if(j + nxt > sum) break;
                    if(k + abs(s - (j + nxt)) < 3300) chmin(dp[i + 1][j + nxt][k + abs(s - (j + nxt))], dp[i][j][k] + nxt * nxt);
                }
            }
        }
    }
    int res = 0;
    for(int k = 0; k <= n * (n - 1) / 2; ++ k) {
        chmax(res, (sum * sum - dp[sz][sum][k]) / 2);
        cout << res << " \n"[k == n * (n - 1) / 2];
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}