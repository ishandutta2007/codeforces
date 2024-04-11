/**
 *    author:  otera    
**/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll INF=1LL<<60;
#define rep(i, n) for(int i = 0; i < n; ++ i)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    auto check = [&](int x) -> bool {
        if(x <= 0 or x >= n - 1) return false;
        return ((a[x - 1] < a[x] and a[x] > a[x + 1]) or (a[x - 1] > a[x] and a[x] < a[x + 1]));
    };
    vector<bool> c(n, 0);
    int cnt = 0;
    for(int i = 1; i < n - 1; ++ i) {
        if(check(i)) {
            c[i] = 1;
            ++ cnt;
        }
    }
    int off = 0;
    for(int i = 0; i < n; ++ i) {
        int  cur = a[i];
        // a[i] = a[i - 1]
        if(i - 1 >= 0) {
            a[i] = a[i - 1];
            int tmp = (i + 2 < n and check(i + 1));
            int now = c[i - 1] + c[i] + (i + 1 < n ? c[i + 1] : 0);
            chmax(off, now - tmp);
        }
        // a[i] = a[i + 1]
        if(i + 1 < n) {
            a[i] = a[i + 1];
            int tmp = (i - 2 >= 0 and check(i - 1));
            int now = (i - 1 >= 0 ? c[i - 1] : 0) + c[i] + c[i + 1];
            chmax(off, now - tmp);
        }
        a[i] = cur;
    }
    cout << cnt - off << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	int t; cin >> t; rep(i, t)solve();
	// solve();
    return 0;
}