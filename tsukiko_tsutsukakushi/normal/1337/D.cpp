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
const ll INF= 9223372036854775807;
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

int f(int x, int y, int z) {
    return (x - y) * (x - y) + (y - z) * (y - z) + (z - x) * (z - x);
} 

void solve() {
	int nr, ng, nb; cin >> nr >> ng >> nb;
    vector<int> r(nr), g(ng), b(nb);
    rep(i, nr) {
        scanf("%lld", &r[i]);
    }
    rep(i, ng) {
        scanf("%lld", &g[i]);
    }
    rep(i, nb) {
        scanf("%lld", &b[i]);
    }
    sort(all(r));
    sort(all(g));
    sort(all(b));
    int ans = INF;
    rep(i, nr) {
        int x = r[i];
        //
        auto ite = lower_bound(all(g), x);
        if(ite != g.end()) {
            int y = *ite;
            auto ite1 = lower_bound(all(b), (x + y + 1) / 2);
            if(ite1 != b.end()) {
                int z = *ite1;
                //cerr << x << " " << y << " " << z << endl;
                chmin(ans, f(x, y, z));
            }
            if(ite1 != b.begin()) {
                ite1 --;
                int z = *ite1;
                chmin(ans, f(x, y, z));
            }
        }
        if(ite != g.begin()) {
            --ite;
            int y = *ite;
            auto ite1 = lower_bound(all(b), (x + y + 1) / 2);
            if(ite1 != b.end()) {
                int z = *ite1;
                chmin(ans, f(x, y, z));
            }
            if(ite1 != b.begin()) {
                ite1 --;
                int z = *ite1;
                chmin(ans, f(x, y, z));
            }
        }
        //
        auto ite2 = lower_bound(all(b), x);
        if(ite2 != b.end()) {
            int y = *ite2;
            auto ite1 = lower_bound(all(g), (x + y + 1) / 2);
            if(ite1 != g.end()) {
                int z = *ite1;
                chmin(ans, f(x, y, z));
            }
            if(ite1 != g.begin()) {
                ite1 --;
                int z = *ite1;
                chmin(ans, f(x, y, z));
            }
        }
        if(ite2 != b.begin()) {
            --ite2;
            int y = *ite2;
            auto ite1 = lower_bound(all(g), (x + y + 1) / 2);
            if(ite1 != g.end()) {
                int z = *ite1;
                chmin(ans, f(x, y, z));
            }
            if(ite1 != g.begin()) {
                ite1 --;
                int z = *ite1;
                chmin(ans, f(x, y, z));
            }
        }
    }
    cout << ans << endl;
}

signed main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	//cout << fixed << setprecision(10);
	int t; cin >> t; rep(i, t)solve();
	//solve();
    return 0;
}