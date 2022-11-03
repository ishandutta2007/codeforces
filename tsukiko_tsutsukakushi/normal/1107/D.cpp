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
	int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    rep(i, n) {
        rep(j, n / 4) {
            char x; cin >> x;
            int y;
            if('0' <= x && x <= '9') {
                y = x - '0';
            } else {
                y = 10 + (x - 'A');
            }
            a[i][4 * j] = y / 8;
            a[i][4 * j + 1] = (y % 8) / 4;
            a[i][4 * j + 2] = (y % 4) / 2;
            a[i][4 * j + 3] = (y % 2);
        }
    }
    vector<vector<int>> b(n + 1, vector<int>(n + 1, 0));
    rep(i, n) {
        rep(j, n) {
            b[i + 1][j + 1] = b[i + 1][j] + b[i][j + 1] - b[i][j] + a[i][j];
        }
    }
    int ans = 1;
    for(int i = 1; i * i <= n; ++i) {
        if(n % i != 0) continue;
        //i
        bool ok = 1;
        for(int k = i; k <= n; k += i) {
            for(int l = i; l <= n; l += i) {
                int cnt = b[k][l] - b[k - i][l] - b[k][l - i] + b[k - i][l - i];
                if(cnt != i * i && cnt != 0) {
                    ok = 0;
                }
            }
        }
        if(ok) chmax(ans, i);
        int j = n / i;
        //j
        ok = 1;
        for(int k = j; k <= n; k += j) {
            for(int l = j; l <= n; l += j) {
                int cnt = b[k][l] - b[k - j][l] - b[k][l - j] + b[k - j][l - j];
                if(cnt != j * j && cnt != 0) {
                    ok = 0;
                }
            }
        }
        if(ok) chmax(ans, j);
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