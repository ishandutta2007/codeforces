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
	int n, m; cin >> n >> m;
    vector<int> y[4];
    rep(i, n) {
        int w, c; cin >> w >> c;
        y[w].push_back(c);
    }
    for(int i = 1; i <= 3; ++i) {
        sort(all(y[i]));
    }
    int ans = 0;
    for(int r1 = 0; r1 < 6; ++ r1) {
        for(int r2 = 0; r2 < 3; ++ r2) {
            for(int r3 = 0; r3 < 2; ++ r3) {
                vector<int> x[4];
                for(int i = 1; i <= 3; ++ i) {
                    x[i] = y[i];
                }
                if(x[1].size() < r1 || x[2].size() < r2 || x[3].size() < r3) continue;
                int res = 0;
                rep(i, r1) {
                    res += x[1].back();
                    x[1].pop_back();
                }
                rep(i, r2) {
                    res += x[2].back();
                    x[2].pop_back();
                }
                rep(i, r3) {
                    res += x[3].back();
                    x[3].pop_back();
                }
                int m_ = m - r1 - r2 * 2 - r3 * 3;
                if(m_ < 0) continue;
                priority_queue<int> pque;
                for(int i = 1; i <= 3; ++ i) {
                    while(x[i].size() >= 6 / i) {
                        int tmp = 0;
                        rep(j, 6 / i) {
                            tmp += x[i].back();
                            x[i].pop_back();
                        }
                        pque.push(tmp);
                    }
                }
                while(m_ >= 6 && pque.size()) {
                    m_ -= 6;
                    res += pque.top();
                    pque.pop();
                }
                chmax(ans, res);
            }
        }
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