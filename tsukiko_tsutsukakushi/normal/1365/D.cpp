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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

bool ok(int x, int y) {
    return (0 <= x && x < n && 0 <= y && y < m);
}

void solve() {
	cin >> n >> m;
    f.assign(n, vector<char>(m));
    rep(i, n) {
        rep(j, m) {
            cin >> f[i][j];
        }
    }
    rep(i, n) {
        rep(j, m) {
            if(f[i][j] == 'B') {
                rep(k, 4) {
                    int nx = i + dx[k], ny = j + dy[k];
                    if(ok(nx, ny)) {
                        if(f[nx][ny] == 'G') {
                            cout << "No" << endl;
                            return;
                        } else if(f[nx][ny] != 'B') {
                            f[nx][ny] = '#';
                        }
                    }
                }
            }
        }
    }
    queue<P> que;
    vector<vector<int>> d(n, vector<int>(m, inf));
    if(f[n - 1][m - 1] != '#') {
        d[n - 1][m - 1] = 0;
        que.push({n - 1, m - 1});
    }
    while(!que.empty()) {
        P p = que.front(); que.pop();
        int x = p.fr, y = p.sc;
        rep(k, 4) {
            int nx = x + dx[k], ny = y + dy[k];
            if(ok(nx, ny) && f[nx][ny] != '#') {
                if(chmin(d[nx][ny], d[x][y] + 1)) {
                    que.push({nx, ny});
                }
            }
        }
    }
    rep(i, n) {
        rep(j, m) {
            if(f[i][j] == 'G' && d[i][j] == inf) {
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	int t; cin >> t; rep(i, t)solve();
	//solve();
    return 0;
}