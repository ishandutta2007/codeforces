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

bool visited[10010][1010];
queue<int> hoge[1010];

void solve() {
	int n, m; cin >> n >> m;
    vector<int> d(m);
    rep(i, m) {
        cin >> d[i];
    }
    rep(i, 10010) {
        rep(j, 1010) {
            visited[i][j] = 0;
        }
    }
    sort(all(d));
    int g, r; cin >> g >> r;
    queue<int> que;
    que.push(0);
    int cnt = 0;
    while(!que.empty()) {
        while(!que.empty()) {
            hoge[0].push(que.front());
            que.pop();
        }
        rep(i, g) {
            while(!hoge[i].empty()) {
                int id = hoge[i].front(); hoge[i].pop();
                //left
                if(id >= 1) {
                    int di = abs(d[id] - d[id - 1]);
                    if(i + di < g) {
                        if(!visited[id - 1][i + di]) {
                            visited[id - 1][i + di] = 1;
                            hoge[i + di].push(id - 1);
                        }
                    } else if(i + di == g && !visited[id - 1][0]) {
                        visited[id - 1][0] = 1;
                        que.push(id - 1);
                    }
                }
                //right
                if(id + 1 < m) {
                    int di = abs(d[id] - d[id + 1]);
                    if(i + di < g) {
                        if(!visited[id + 1][i + di]) {
                            visited[id + 1][i + di] = 1;
                            hoge[i + di].push(id + 1);
                        }
                    } else if(i + di == g && !visited[id + 1][0]) {
                        visited[id + 1][0] = 1;
                        que.push(id + 1);
                    }
                }
            }
        }
        rep1(i, g - 1) {
            if(visited[m - 1][i]) {
                int ans = (g + r) * cnt + i;
                cout << ans << endl;
                return;
            }
        }
        if(visited[m - 1][0]) {
            int ans = (g + r) * cnt + g;
            cout << ans << endl;
            return;
        }
        ++ cnt;
    }
    cout << -1 << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}