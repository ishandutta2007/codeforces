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

void solve() {
    int n; cin >> n;
    vector<int> p(n);
    vector<int> pos(n, -1);
    rep(i, n) {
        cin >> p[i];
        -- p[i];
        // cerr << p[i] << " " << i << endl;
        pos[p[i]] = i;
    }
    // cerr << pos[1] << endl;
    vector<P> ans;
    auto swp = [&](int i, int j) {
        ans.push_back({i, j});
        pos[p[i]] = j;
        pos[p[j]] = i;
        swap(p[i], p[j]);
    };
    for(int i = 1; i < n - 1; ++ i) {
        if(pos[i] == i) continue;
        if(2 * abs(pos[i] - i) >= n) {
            swp(i, pos[i]);
        } else {
            int mi = min(i, pos[i]), ma = max(i, pos[i]);
            // cerr << mi << " " << ma << endl;
            if(2 * abs(n - 1 - ma) >= n) {
                swp(pos[i], n - 1);
                swp(i, n - 1);
            } else if(2 * abs(mi) >= n) {
                swp(pos[i], 0);
                swp(i, 0);
            } else {
                if(pos[i] < i) {
                    swp(pos[i], n - 1);
                    swp(0, n - 1);
                    swp(i, 0);
                } else {
                    swp(pos[i], 0);
                    swp(0, n - 1);
                    swp(i, n - 1);
                }
            }
        }
        // rep(j, n) cerr << p[j] << " \n"[j == n - 1];
    }
    if(p[0] != 0) swp(0, n - 1);
    // rep(i, n) cerr << p[i] << " \n"[i == n - 1];
    cout << (int)ans.size() << endl;
    for(auto p: ans) {
        cout << p.fr + 1 << " " << p.sc + 1 << "\n";
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