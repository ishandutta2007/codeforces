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
    map<char, P> mp;
    mp['U'] = {0, 1};
    mp['D'] = {0, -1};
    mp['L'] = {-1, 0};
    mp['R'] = {1, 0};
	int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    int n; string s; cin >> n >> s;
    int x = x2 - x1, y = y2 - y1;
    vector<int> mx(n + 1, 0), my(n + 1, 0);
    rep(i, n) {
        mx[i + 1] = mx[i] + mp[s[i]].fr;
        my[i + 1] = my[i] + mp[s[i]].sc;
    }
    int ng = -1, ok = INF;
    while(ok - ng > 1) {
        int mid = (ok + ng) / 2;
        int cnt = mid / n, cnt1 = mid % n;
        int sx = cnt * mx[n] + mx[cnt1], sy = cnt * my[n] + my[cnt1];
        int nx = x - sx, ny = y - sy;
        if(abs(nx) + abs(ny) <= mid) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    if(ok == INF) ok = -1;
    cout << ok << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}