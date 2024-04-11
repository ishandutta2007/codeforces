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

//#define int long long
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

vector<int> divi[200200];

void solve() {
	int n; cin >> n;
    vector<int> p(n), c(n);
    rep(i, n) {
        cin >> p[i];
        -- p[i];
    }
    rep(i, n) {
        cin >> c[i];
    }
    int ans = n;
    vector<bool> ok(n, 0), check(n, 0);
    rep(i, n) {
        if(!ok[i]) {
            vector<int> cycle(1, i);
            int tmp = i;
            ok[i] = 1;
            while(p[tmp] != i) {
                cycle.push_back(p[tmp]);
                tmp = p[tmp];
                ok[tmp] = 1;
            }
            int sz = (int)cycle.size();
            //cerr << sz << endl;
            for(int d: divi[sz]) {
                rep(j, d) {
                    check[j] = 1;
                }
                for(int j = d; j < sz; ++ j) {
                    if(c[cycle[j]] != c[cycle[j % d]]) {
                        check[j % d] = 0;
                    }
                }
                rep(j, d) {
                    if(check[j]) {
                        chmin(ans, d);
                    }
                }
            }
        }
    }
    cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    for(int i = 1; i < 200200; ++ i) {
        for(int j = 1; j * j <= i; ++ j) {
            if(i % j == 0) {
                divi[i].push_back(j);
                if(j * j != i) divi[i].push_back(i / j);
            }
        }
    }
	//cout << fixed << setprecision(10);
	int t; cin >> t; rep(i, t)solve();
	//solve();
    return 0;
}