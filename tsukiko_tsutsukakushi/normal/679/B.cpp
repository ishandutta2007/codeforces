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

pair<int, int> dfs(int x) {
    if(x == 0) return P{0, 0};
    int ok = 0, ng = 1e6;
    while(ng - ok > 1) {
        int mid = (ok + ng) / 2;
        if(mid * mid * mid <= x) ok = mid;
        else ng = mid;
    }
    int a = ok;
    P p = dfs(x - a * a * a);
    P w = {p.fr + 1, p.sc + a * a * a};
    if(a - 1 >= 1) {
        P q = dfs(a * a * a - (a - 1) * (a - 1) * (a - 1) - 1);
        if(w.fr < q.fr + 1) {
            w = {q.fr + 1, q.sc + (a - 1) * (a - 1) * (a - 1)};
        }
    }
    return w;
}

void solve() {
	int m; cin >> m;
    auto ans = dfs(m);
    cout << ans.fr << " " << ans.sc << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}