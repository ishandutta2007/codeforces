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

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

void solve() {
	int n, sx, sy; cin >> n >> sx >> sy;
    vector<int> x(n), y(n);
    rep(i, n) {
        cin >> x[i] >> y[i];
    }
    int ans = 0;
    vector<int> cnt(4, 0);
    rep(i, n) {
        if(x[i] > sx) {
            if(y[i] > sy) {
                cnt[0] ++, cnt[1] ++;
            } else if(y[i] == sy) {
                cnt[1] ++;
            } else {
                cnt[1] ++, cnt[2] ++;
            }
        } else if(x[i] == sx) {
            if(y[i] > sy) {
                cnt[0] ++;
            } else {
                cnt[2] ++;
            }
        } else {
            if(y[i] > sy) {
                cnt[0] ++, cnt[3] ++;
            } else if(y[i] == sy) {
                cnt[3] ++;
            } else {
                cnt[2] ++, cnt[3] ++;
            }
        }
    }
    auto ite = max_element(all(cnt));
    cout << *ite << endl;
    int c = ite - cnt.begin();
    cout << sx + dx[c] << " " << sy + dy[c] << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}