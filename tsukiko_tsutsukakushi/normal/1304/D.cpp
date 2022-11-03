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
	int n; string s; cin >> n >> s;
    vector<int> res(n, -1);
    int now = 1, cnt = 0;
    per(i, n - 1) {
        if(s[i] == '<') {
            ++cnt;
        }
        if(s[i] == '>') {
            rep(j, cnt + 1) {
                res[i + 1 + j] = now;
                ++now;
            }
            cnt = 0;
        }
    }
    if(cnt > 0) {
        rep(j, cnt + 1) {
                res[j] = now;
                ++now;
            }
        cnt = 0;
    }
    now = n;
    rep(i, n) {
        if(res[i] == -1) {
            res[i] = now;
            --now;
        }
    }
    rep(i, n) cout << res[i] << " ";
    cout << endl;
    //
    vector<int> ans(n, -1);
    now = 1;
    rep(i, n - 1) {
        if(s[i] == '<') {
            ans[i] = now;
            ++now;
            if(i == n - 2) {
                ans[i + 1] = now;
                ++now;
            }
        }
    }
    per(i, n) {
        if(ans[i] == -1) {
            ans[i] = now;
            ++now;
        }
    }
    rep(i, n) cout << ans[i] << " ";
    cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	int t; cin >> t; rep(i, t)solve();
	//solve();
    return 0;
}