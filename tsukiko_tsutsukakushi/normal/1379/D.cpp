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

template<typename T>
vector<T> compress(vector<T> A){
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    return A;
}

void solve() {
	int n, h, m, k; cin >> n >> h >> m >> k;
    int dt[4] = {0, k, m / 2, m / 2 + k};
    vector<P> f(n * 2);
    vector<int> T;
    vector<int> tr(n);
    rep(i, n) {
        int x, y; cin >> x >> y;
        tr[i] = y;
        f[i] = P{y, i};
        f[n + i] = P{y + m, i};
        T.pb(y), T.pb(y + m), T.pb(y + 2 * m), T.pb(y + 3 * m);
    }
    sort(all(T));
    sort(all(f));
    int t = -1, res = n + 1;
    for(P p: f) {
        int tt = p.fr;
        rep(i, 4) {
            int nt = tt + dt[i];
            int cnt = lower_bound(all(T), nt + m / 2 + k) - upper_bound(all(T), nt + m / 2);
            cnt += lower_bound(all(T), nt + k) - upper_bound(all(T), nt);
            if(chmin(res, cnt)) {
                t = nt;
            }
        } 
    }
    while(t >= m / 2) t -= m / 2;
    int cnt = 0; set<int> se;
    rep(i, n) {
        if((t < tr[i] and tr[i] < t + k) || (t + m / 2 < tr[i] and tr[i] < t + m / 2 + k) || (t + m / 2 < tr[i] + m and tr[i] + m < t + m / 2 + k)) {
            ++ cnt;
            se.insert(i);
        }
    }
    t += k;
    while(t >= m / 2) t -= m / 2;
    cout << cnt << " " << t << endl;
    for(int j: se) {
        cout << j + 1 << " ";
    }
    cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}