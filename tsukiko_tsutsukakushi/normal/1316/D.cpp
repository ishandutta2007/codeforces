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

int n;

int f(int i, int j) {
    return i * n + j;
}

bool isin(int i, int j) {
    if(0 <= i && i < n && 0 <= j && j < n) {
        return true;
    } else {
        return false;
    }
}

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

char ve[4] = {'D', 'R', 'U', 'L'};

struct UnionFind {
    vector<int> par, w;
    
    UnionFind(int n) : par(n, -1), w(n, 0) { }
    void init(int n) { par.assign(n, -1); w.assign(n, 0); }
    
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) {
            ++w[x];
            return false;
        }
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        w[x] += w[y];
        ++w[x];
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
 
    int wei(int x) {
        return w[root(x)];
    }
};

vector<vector<char>> ans;
vector<vector<P>> c;

void dfs(int X, int Y, P p) {
    rep(k, 4) {
        int nx = X + dx[k], ny = Y + dy[k];
        if(isin(nx, ny) && c[nx][ny] == p && ans[nx][ny] == '?') {
            ans[nx][ny] = ve[(k + 2) % 4];
            dfs(nx, ny, p);
        }
    }
}


void solve() {
	cin >> n;
    //UnionFind uf(n * n);
    //vector<vector<int>> x(n, vector<int>(n));
    //vector<vector<int>> y(n, vector<int>(n));
    c.assign(n, vector<P>(n));
    rep(i, n) {
        rep(j, n) {
            //cin >> x[i][j] >> y[i][j];
            //--x[i][j]; --y[i][j];
            int x, y; cin >> x >> y;
            if(x != -1 && y != -1) {
                --x; --y;
            }
            c[i][j] = make_pair(x, y);
        }
    }
    ans.assign(n, vector<char>(n, '?'));
    rep(i, n) {
        rep(j, n) {
            if(c[i][j] == make_pair(-1, -1)) {
                bool ok = 0;
                rep(k, 4) {
                    int nx = i + dx[k], ny = j + dy[k];
                    if(isin(nx, ny)) {
                        if(c[nx][ny] == P{-1, -1}) {
                            ans[i][j] = ve[k];
                            ans[nx][ny] = ve[(k + 2) % 4];
                            ok = 1;
                            continue;
                        }
                    }
                }
                if(!ok) {
                    cout << "INVALID" << endl;
                    return;
                }
            } else {
                if(c[i][j] == make_pair(i, j)) {
                    ans[i][j] = 'X';
                    dfs(i, j, make_pair(i, j));
                }
            }
        }
    }
    rep(i, n) {
        rep(j, n) {
            if(ans[i][j] == '?') {
                cout << "INVALID" << endl;
                return;
            }
        }
    }
    cout << "VALID" << endl;
    rep(i, n) {
        rep(j, n) {
            cout << ans[i][j];
        }
        cout << endl;
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