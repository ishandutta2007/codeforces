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

int m, n, k, t; 
vector<int> a;
vector<pair<int, pair<int, int>>> vec;

bool check(int x) {
    int res = n + 1;
    vector<int> b(n + 2, 0);
    rep(i, k) {
        if(vec[i].fr < x) {
            int l = vec[i].sc.fr, r = vec[i].sc.sc;
            b[l] ++;
            b[r + 1] --;
        }
    }
    rep(i, n + 1) {
        b[i + 1] += b[i];
    }
    rep(i, n + 2) {
        if(b[i] > 0) {
            res += 2;
        }
    }
    //cerr << x << " " << res << endl;
    if(res <= t) return true;
    else return false;
}

void solve() {
	cin >> m >> n >> k >> t;
    a.resize(m);
    rep(i, m) {
        cin >> a[i];
    }
    sort(all(a));
    rep(i, k) {
        int l, r, d; cin >> l >> r >> d;
        int cnt = a.end() - lower_bound(all(a), d);
        //int cnt = upper_bound(all(a), d) - a.begin();
        vec.push_back({cnt, {l, r}});
    }
    int ok = 0, ng = m + 1;
    while(ng - ok > 1) {
        int mid = (ok + ng) / 2;
        if(check(mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
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