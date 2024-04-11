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
	int n; cin >> n;
    vector<int> p, m, z;
    rep(i, n) {
        int a; cin >> a;
        if(a < 0) m.pb(a);
        else if(a == 0) z.pb(a);
        else p.pb(a);
    }
    sort(all(m));
    sort(all(p));
    reverse(all(p));
    ll ans = -INF;
    for(int cntp = 0; cntp <= 5; ++ cntp) {
        for(int cntm = 0; cntm <= 5; ++ cntm) {
            for(int cntz = 0; cntz <= 5; ++ cntz) {
                if(cntp > (int)p.size() || cntm > (int)m.size() || cntz > (int)z.size()) continue;
                if(cntp + cntm + cntz != 5) continue;
                ll res = 1LL;
                rep(i, cntp) res *= 1LL * p[i];
                rep(i, cntm) res *= 1LL * m[i];
                rep(i, cntz) res *= 1LL * z[i];
                chmax(ans, res);
            }
        }
    }
    reverse(all(m));
    reverse(all(p));
    for(int cntp = 0; cntp <= 5; ++ cntp) {
        for(int cntm = 0; cntm <= 5; ++ cntm) {
            for(int cntz = 0; cntz <= 5; ++ cntz) {
                if(cntp > (int)p.size() || cntm > (int)m.size() || cntz > (int)z.size()) continue;
                if(cntp + cntm + cntz != 5) continue;
                ll res = 1LL;
                rep(i, cntp) res *= 1LL * p[i];
                rep(i, cntm) res *= 1LL * m[i];
                rep(i, cntz) res *= 1LL * z[i];
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
	int t; cin >> t; rep(i, t)solve();
	//solve();
    return 0;
}