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
    vector<ll> x(4), y(4);
    rep(i, 4) {
        cin >> x[i] >> y[i];
    }
    ll ans = INF;
    vector<int> ids(4);
    auto dis = [&](int x, int y, int x1, int y1) {
        return abs(x - x1) + abs(y - y1);
    };
    auto f = [&](vector<P> v) {
        assert((int)v.size() == 4);
        iota(all(ids), 0);
        do {
            ll res = 0;
            rep(i, 4) {
                int id = ids[i];
                res += dis(x[i], y[i], v[id].fr, v[id].sc);
            }
            chmin(ans, res);
        } while(next_permutation(all(ids)));
    };
    rep(i, 4) {
        rep(j, 4) {
            rep(k, 4) {
                // (x[i], y[k]), (x[j], y[k])
                ll d1 = abs(x[i] - x[j]);
                vector<P> vec = {{x[i], y[k]}, {x[j], y[k]}, {x[i], y[k] + d1}, {x[j], y[k] + d1}};
                f(vec);
                vec = {{x[i], y[k]}, {x[j], y[k]}, {x[i], y[k] - d1}, {x[j], y[k] - d1}};
                f(vec);
                // (x[i], y[j]), (x[i], y[k])
                ll d2 = abs(y[j] - y[k]);
                vec = {{x[i], y[j]}, {x[i], y[k]}, {x[i] + d2, y[j]}, {x[i] + d2, y[k]}};
                f(vec);
                vec = {{x[i], y[j]}, {x[i], y[k]}, {x[i] - d2, y[j]}, {x[i] - d2, y[k]}};
                f(vec);
            }
        }
    }
    cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	int t; cin >> t; rep(i, t)solve();
	// solve();
    return 0;
}