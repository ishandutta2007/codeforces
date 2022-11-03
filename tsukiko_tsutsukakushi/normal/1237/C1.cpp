/**
 *    author:  otera    
**/
#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(int i = 0; i < n; ++ i)
#define per(i,n) for(int i=n-1;i>=0;i--)
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

typedef pair<P, P> P2;

void solve() {
    int n; cin >> n;
    vector<int> x(n), y(n), z(n);
    rep(i, n) cin >> x[i] >> y[i] >> z[i];
    vector<bool> used(n, 0);
    set<int> se;
    rep(i, n) se.insert(i);
    rep(i, n) {
        if(!used[i]) {
            used[i] = 1;
            se.erase(i);
            int cur = *se.begin();
            rep(j, n) {
                if(!used[j]) {
                    if(min(x[i], x[cur]) <= x[j] and x[j] <= max(x[i], x[cur])) {
                        if(min(y[i], y[cur]) <= y[j] and y[j] <= max(y[i], y[cur])) {
                            if(min(z[i], z[cur]) <= z[j] and z[j] <= max(z[i], z[cur])) {
                                cur = j;
                            }
                        }
                    }
                }
            }
            used[cur] = 1, se.erase(cur);
            cout << i + 1 << " " << cur + 1 << "\n";
        }
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}