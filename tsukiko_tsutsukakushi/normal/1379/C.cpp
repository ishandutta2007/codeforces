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
    vector<int> a(m), b(m);
    vector<int> sum(m + 1, 0);
    vector<P> f(m);
    rep(i, m) {
        cin >> a[i] >> b[i];
        f[i] = P{a[i], b[i]};
    }
    sort(all(a));
    reverse(all(a));
    rep(i, m) {
        sum[i + 1] = sum[i] + a[i];
    }
    sort(all(f));
    int ans = 0;
    rep(i, m) {
        int cnt = f.end() - upper_bound(all(f), P{f[i].sc + 1, -1});
        if(cnt >= n) {
            chmax(ans, sum[n]);
            continue;
        } else {
            int res = n - cnt;
            int tmp = sum[cnt];
            //cerr << tmp << endl;
            if(f[i].fr <= f[i].sc) {
                tmp += f[i].fr;
                -- res;
            }
            if(res == 0) {
                chmax(ans, tmp); continue;
            }
            tmp += f[i].sc * res;
            chmax(ans, tmp);
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