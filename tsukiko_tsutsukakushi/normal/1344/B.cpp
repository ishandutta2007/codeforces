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

int n, m;
vector<vector<char>> f;
vector<vector<bool>> used;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

void dfs(int x, int y) {
    used[x][y] = true;
    rep(k, 4) {
        int nx = x + dx[k], ny = y + dy[k];
        if(0 <= nx && nx < n && 0 <= ny && ny < m && f[nx][ny] == '#' && !used[nx][ny]) {
            dfs(nx, ny);
        }
    }
}

void solve() {
	cin >> n >> m;
    f.assign(n, vector<char>(m));
    used.assign(n, vector<bool>(m, false));
    rep(i, n) {
        rep(j, m) {
            cin >> f[i][j];
        }
    }
    bool w0 = 0, w1 = 0;
    rep(i, n) {
        bool now = 0; int co = 0;
        rep(j, m) {
            if(f[i][j] == '#') {
                if(!now) {
                    ++ co; now = 1;
                }
            } else {
                now = 0;
            }
        }
        if(co == 0) w0 = 1;
        if(co >= 2) {
            cout << -1 << endl;
            return;
        }
    }
    rep(j, m) {
        bool now = 0; int co = 0;
        rep(i, n) {
            if(f[i][j] == '#') {
                if(!now) {
                    ++ co; now = 1;
                }
            } else {
                now = 0;
            }
        }
        if(co == 0) w1 = 1;
        if(co >= 2) {
            cout << -1 << endl;
            return;
        }
    }
    if((w0 && w1) || (!w0 && !w1)) {
        //
    } else {
        cout << -1 << endl;
        return;
    }
    int cnt = 0;
    rep(i, n) {
        rep(j, m) {
            if(!used[i][j] && f[i][j] == '#') {
                ++ cnt;
                dfs(i, j);
            }
        }
    }
    cout << cnt << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}