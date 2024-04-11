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
#include<unordered_set>
#include<utility>
#include<cassert>
#include<array>
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
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

typedef pair<int, pair<int, int>> P2;

void solve() {
	vector<ll> a(6);
    rep(i, 6) {
        cin >> a[i];
    }
    int n; cin >> n;
    vector<int> b(n);
    map<int, vector<int>> mp;
    vector<vector<int>> x(n, vector<int>());
    rep(i, n) {
        cin >> b[i];
        rep(j, 6) {
            x[i].push_back(b[i] - a[j]);
            mp[b[i] - a[j]].push_back(i);
        }
        sort(all(x[i]));
    }
    int mi = inf, ma = 0;
    priority_queue<P2, vector<P2>, greater<P2>> pque;
    rep(i, n) {
        chmin(mi, x[i][0]);
        chmax(ma, x[i][0]);
        pque.push({x[i][0], {i, 0}});
    }
    int ans = ma - mi;
    while(1) {
        auto p = pque.top(); pque.pop();
        int j = p.sc.fr, k = p.sc.sc;
        if(k == 5) {
            break;
        } else {
            pque.push({x[j][k + 1], {j, k + 1}});
            chmax(ma, x[j][k + 1]);
        }
        int mi = pque.top().fr;
        chmin(ans, ma - mi);
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