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

typedef pair<int, pair<int, int>> P2;

int n, m, k, q;
vector<P2> a;

bool check(int t) {
    vector<vector<int>> tv(n, vector<int>(m, 0));
    rep(i, q) {
        if(a[i].fr <= t) {
            tv[a[i].sc.fr][a[i].sc.sc] ++;
        }
    }
    vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));
    rep(i, n) {
        rep(j, m) {
            sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + tv[i][j];
        }
    }
    rep(i, n) {
        rep(j, m) {
            int s = max(0LL, j - k + 1), l = max(0LL, i - k + 1);
            int co = sum[i + 1][j + 1] - sum[i + 1][s] - sum[l][j + 1] + sum[l][s];
            if(co == k * k) {
                return true;
            }
        }
    }
    return false;
}

void solve() {
	cin >> n >> m >> k >> q;
    vector<int> x(q), y(q), t(q);
    a.resize(q);
    rep(i, q) {
        cin >> x[i] >> y[i] >> t[i];
        -- x[i], -- y[i];
        a[i] = {t[i], {x[i], y[i]}};
    }
    sort(all(a));
    int ok = inf, ng = -1;
    if(!check(ok)) {
        cout << -1 << endl;
        return;
    }
    while(ok - ng > 1) {
        int mid = (ok + ng) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
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