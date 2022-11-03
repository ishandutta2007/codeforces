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

void solve() {
	string s; cin >> s;
    int n = (int)s.size();
    int cnt[10][10][10][10]; //start, goal, x, y
    rep(i, 10) {
        rep(j, 10) {
            rep(k, 10) {
                rep(l, 10) {
                    cnt[i][j][k][l] = INF;
                }
            }
        }
    }
    rep(x, 10) {
        rep(y, 10) {
            rep(s, 10) {
                rep(i, 100) {
                    rep(j, 100) {
                        if(i + j == 0) continue;
                        int v = (s + x * i + y * j) % 10;
                        chmin(cnt[s][v][x][y], i + j - 1);
                    }
                }
            }
        }
    }
    rep(x, 10) {
        rep(y, 10) {
            int ans = 0;
            for(int i = 0; i < n - 1; ++i) {
                if(cnt[s[i] - '0'][s[i + 1] - '0'][x][y] == INF) {
                    ans = -1;
                    break;
                }
                ans += cnt[s[i] - '0'][s[i + 1] - '0'][x][y];
            }
            cout << ans << " ";
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