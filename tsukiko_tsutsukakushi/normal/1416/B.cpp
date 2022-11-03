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

typedef pair<int, P> P2;

void solve() {
	int n; cin >> n;
    vector<int> a(n + 1, 0);
    int sum = 0;
    rep(i, n) {
        cin >> a[i + 1];
        sum += a[i + 1];
    }
    if(sum % n != 0) {
        cout << -1 << endl;
        return;
    }
    int y = sum / n;
    vector<P2> ans;
    for(int i = 2; i <= n; ++ i) {
        int res = a[i] % i;
        if(res == 0) {
            ans.emplace_back(P2{a[i] / i, P{i, 1}});
            a[1] += a[i], a[i] = 0;
        } else {
            int need = i - res;
            ans.emplace_back(P2{need, P{1, i}});
            a[1] -= need, a[i] += need;
            ans.emplace_back(P2{a[i] / i, P{i, 1}});
            a[1] += a[i], a[i] = 0;
        }
    }
    for(int i = 2; i <= n; ++ i) {
        ans.emplace_back(P2{y, P{1, i}});
        a[1] -= y, a[i] += y;
    }
    cout << (int)ans.size() << endl;
    rep(i, (int)ans.size()) {
        cout << ans[i].sc.fr << " " << ans[i].sc.sc << " " << ans[i].fr << endl;
    }
    // rep(i, n) {
    //     cerr << a[i] << " \n"[i == n - 1];
    // }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	int t; cin >> t; rep(i, t)solve();
	//solve();
    return 0;
}