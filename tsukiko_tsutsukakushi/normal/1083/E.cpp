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

//from drken
template<class T> struct CHT {
    using Line = pair<T, T>;
    deque<Line> lines;
    
    inline bool check(const Line &a, const Line &b, const Line &c) {
        return(double) (b.first - a.first) * (double)(c.second - b.second)
        <= (double)(b.second - a.second) * (double)(c.first - b.first);
    }
    
    inline T get(int k, T x) {
        return lines[k].first * x + lines[k].second;
    }
    
    void insert(T a, T b) {
        Line l(a, b);
        while (lines.size() >= 2
               && check(lines[(int)lines.size()-2], lines[(int)lines.size()-1], l))
            lines.pop_back();
        lines.push_back(l);
    }
    
    T query(T x) {
        int low = -1, high = (int)lines.size();
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (get(mid, x) <= get(mid + 1, x)) low = mid;
            else high = mid;
        }
        return get(high, x);
    }
    
    T query_monotone(T x) {
        while (lines.size() >= 2 && get(0, x) <= get(1, x)) lines.pop_front();
        return lines[0].first * x + lines[0].second;
    }
};

void solve() {
	int n; cin >> n;
    vector<int> x(n), y(n), a(n);
    rep(i, n) {
        cin >> x[i] >> y[i] >> a[i];
    }
    vector<int> ids(n);
    iota(all(ids), 0);
    sort(all(ids), [&](int i, int j){ return x[i] > x[j];});
    CHT<int> cht;
    cht.insert(0, 0);
    vector<int> dp(n, -INF);
    int ans = 0;
    dp[0] = 0;
    rep(i, n) {
        int j = ids[i];
        dp[i] = cht.query_monotone(x[j]) + x[j] * y[j] - a[j];
        chmax(ans, dp[i]);
        cht.insert(-y[j], dp[i]);
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