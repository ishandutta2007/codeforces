/**
 *    author:  otera    
**/
#include<bits/stdc++.h>
using namespace std;

#define int long long
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
    int n; string s; cin >> n >> s;
    int cnt = 0;
    vector<int> a;
    int cur = 1;
    rep(i, n - 1) {
        if(s[i] != s[i + 1]) {
            a.push_back(cur);
            cur = 1;
        } else {
            ++ cur;
        }
    }
    a.push_back(cur);
    int sz = (int)a.size();
    // rep(i, sz) cerr << a[i] << " \n"[i == sz - 1];
    vector<int> nxt(sz + 1, sz);
    per(i, sz) {
        nxt[i] = nxt[i + 1];
        if(a[i] >= 2) nxt[i] = i;
    }
    int i = 0, j = nxt[0];
    for(; i < sz;) {
        if(j < i) j = nxt[i];
        if(a[i] >= 2) ++ cnt;
        else {
            if(j == sz) {
                ++ cnt; ++ i;
            } else {
                assert(a[j] >= 2);
                ++ cnt; -- a[j];
                if(a[j] == 1) j = nxt[j + 1];
            }
        }
        ++ i;
    }
    cout << cnt << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	int t; cin >> t; rep(i, t)solve();
	// solve();
    return 0;
}