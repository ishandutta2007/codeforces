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

int n, m; 
int x, y, k;
vector<int> a, b;

void fail() {
    cout << -1 << endl;
    exit(0);
}

void update(int l, int r, int &ans) {
    if(l > r) return;
    int ma = *max_element(a.begin() + l, a.begin() + r + 1);
    bool ok = 0;
    if(l - 1 >= 0 && a[l - 1] > ma) ok = 1;
    if(r + 1 < n && a[r + 1] > ma) ok = 1;
    if(r - l + 1 < k && !ok) fail();
    int len = r - l + 1;
    int need = len % k;
    ans += need * y;
    len -= need;
    if(x <= y * k) {
        ans += len / k * x;
    } else if(ok) {
        ans += y * len;
    } else {
        ans += (len - k) * y + x; 
    }
}

void solve() {
	cin >> n >> m;
    cin >> x >> k >> y;
    a.resize(n), b.resize(m);
    rep(i, n) {
        cin >> a[i];
    }
    rep(i, m) {
        cin >> b[i];
    }
    int ans = 0;
    int posa = 0, posb = 0, lst = -1;
    while(posb < m) {
        while(posa < n and a[posa] != b[posb]) ++ posa;
        if(posa == n) {
            fail();
        }
        update(lst + 1, posa - 1, ans);
        lst = posa;
        ++ posb;
    }
    update(lst + 1, n - 1, ans);
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