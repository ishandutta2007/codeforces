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
	int n, k; cin >> n >> k;
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    int now = 0;
    int l = max(l1, l2), r = min(r1, r2);
    now = (l <= r ? r - l : 0) * n;
    if(now >= k) {
        cout << 0 << endl;
        return;
    }
    if(l > r) {
        int lmi = min(l1, l2), rma = max(r1, r2);
        int tmp1 = l - r;
        int tmp2 = 2 * (rma - lmi) - (r2 - l2) - (r1 - l1) - tmp1;
        k -= now;
        if(tmp1 <= tmp2) {
            int cnt = min(k / tmp2, n);
            int ans = cnt * (tmp1 + tmp2);
            int res1 = (k - tmp2 * cnt) * 2;
            if(cnt == n) {
                cout << ans + res1 << endl;
                return;
            }
            int res2 = (k % tmp2 == 0 ? 0 : tmp1 + k % tmp2);
            if(cnt == 0) {
                cout << ans + res2 << endl;
                return;
            }
            cout << ans + min(res1, res2) << endl;
        } else {
            int ans = tmp1;
            if(k <= tmp2) ans += k;
            else {
                ans += tmp2 + (k - tmp2) * 2;
            }
            cout << ans << endl;
        }
    } else {
        int lmi = min(l1, l2), rma = max(r1, r2);
        int tmp = 2 * (rma - lmi) - (r2 - l2) - (r1 - l1);
        k -= now;
        if(k <= tmp * n) {
            cout << k << endl;
        } else {
            cout << tmp * n + (k - tmp * n) * 2 << endl;
        }
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	int t; cin >> t; rep(i, t)solve();
	//solve();
    return 0;
}