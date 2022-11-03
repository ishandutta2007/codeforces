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
#define int long long

int n;
vector<int> a;
int sum[110];
ll dp[(1<<18) + 10][25];

ll calc(int pos, int cnt) {
    if(dp[pos][cnt] != -1) return dp[pos][cnt];
    if(a[pos] == -1) return 0;
    ll res = INF;
    if(pos < sum[cnt]) {
        chmin(res, calc(pos + 1, cnt));
    }
    if(cnt < 20) {
        chmin(res, calc(pos + 1, cnt + 1) + a[pos]);
    }
    return dp[pos][cnt] = res;
}

void solve() {
    cin >> n;
    a.resize(n);
    for(int i = 0, x = n / 2; i < 100; i ++, x /= 2) {
        sum[i + 1] = sum[i] + x;
    }
    rep(i, n) {
        cin >> a[i];
    }
    reverse(all(a));
    rep(i, (1<<18) + 10) {
        rep(j, 25) {
            dp[i][j] = -1;
        }
    }
    cout << calc(0, 0) << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	//cout << "finish" << endl;
    return 0;
}