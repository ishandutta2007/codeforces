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
    vector<ll> s(n), t(n);
    vector<pair<ll, int>> vec(n);
    ll sums = 0, sumt = 0;
    rep(i, n) {
        cin >> s[i];
        vec[i] = {s[i], i};
        sums += s[i];
    }
    rep(i, n) {
        cin >> t[i];
        sumt += t[i];
    }
    sort(all(t));
    if(sums != sumt) {
        cout << "NO\n";
        return;
    }
    sort(all(vec));
    vector<array<int, 3>> ans;
    stack<P> st;
    rep(i, n) {
        ll d = t[i] - vec[i].fr;
        if(d == 0) continue;
        if(d > 0) {
            st.push({d, vec[i].sc});
        } else {
            while(st.size() and d < 0) {
                P p = st.top(); st.pop();
                if(d + p.fr <= 0) {
                    d += p.fr;
                    ans.push_back({p.sc, vec[i].sc, p.fr});
                } else {
                    st.push({p.fr - abs(d), p.sc});
                    ans.push_back({p.sc, vec[i].sc, abs(d)});
                    d = 0;
                }
            }
            if(d < 0) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
    cout << (int)ans.size() << endl;
    rep(i, (int)ans.size()) {
        cout << ans[i][0] + 1 << " " << ans[i][1] + 1 << " " << ans[i][2] << '\n';
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