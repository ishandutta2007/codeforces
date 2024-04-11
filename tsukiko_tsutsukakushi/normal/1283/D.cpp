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
#define int long long

void solve() {
	int n, m; cin >> n >> m;
    vector<int> x(n);
    set<int> se, sxb, sxf;
    rep(i, n) {
        cin >> x[i];
        sxb.insert(x[i]);
        sxf.insert(x[i]);
        se.insert(x[i]);
    }
    sort(all(x));
    vector<int> y;
    int d = 1;
    int res = 0;
    while(m > 0) {
        // for(int i = 0; i < n && m > 0; ++i) {
        //     int a = x[i] - d;
        //     if(!se.count(a)) {
        //         se.insert(a);
        //         y.push_back(a);
        //         res += d;
        //         --m;
        //     }
        //     if(m == 0) break;
        //     int b = x[i] + d;
        //     if(!se.count(b)) {
        //         se.insert(b);
        //         y.push_back(b);
        //         res += d;
        //         --m;
        //     }
        // }
        for(auto ite = sxb.begin(); ite != sxb.end() && m > 0; ) {
            int a = *ite - d;
            if(!se.count(a)) {
                se.insert(a);
                y.push_back(a);
                res += d;
                --m;
                ++ite;
            } else {
                ite = sxb.erase(ite);
            }
        }
        for(auto ite = sxf.begin(); ite != sxf.end() && m > 0; ) {
            int a = *ite + d;
            if(!se.count(a)) {
                se.insert(a);
                y.push_back(a);
                res += d;
                --m;
                ++ite;
            } else {
                ite = sxf.erase(ite);
            }
        }
        ++d;
    }
    cout << res << endl;
    for(auto& a: y) cout << a << " ";
    cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	solve();
	//cout << "finish" << endl;
    return 0;
}