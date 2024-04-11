#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
struct fenwick {
    vector<T> a;
    int n;
    fenwick(int n): n(n), a(n) {}
    void add(int x, T v) {
        assert(0 <= x && x < n);
        for(int i = x + 1; i <= n; i += i & -i) a[i - 1] += v;
    }
    T qry(int x) {
        T ret = 0;
        for(int i = min(x + 1, n); i > 0; i -= i & -i) ret += a[i - 1];
        return ret;
    }
};

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q;
    cin >> q;
    while(q--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        vector<int> vis(n);
        vector<vector<int>> pos(26);
        for(int i = n - 1; i >= 0; --i) {
            pos[s[i] - 'a'].push_back(i);
        }
        ll ans = 1e18, cur = 0;
        fenwick<int> fen(n);
        for(int i = 0; i < n; ++i) fen.add(i, 1);
        string x;
        for(int i = 0, j = 0; i < n; ++i) {
            while(vis[j]) ++j;
            ll lp = 1e18;
            for(int k = 0; k < t[i] - 'a'; ++k) {
                if(!pos[k].empty()) {
                    lp = min(lp, (ll)pos[k].back());
                }
            }
            if(lp != 1e18) {
                ans = min(ans, cur + fen.qry(lp - 1) - fen.qry(j - 1));
            }
            if(pos[t[i] - 'a'].empty()) break;
            int p = pos[t[i] - 'a'].back(); pos[t[i] - 'a'].pop_back();
            vis[p] = 1;
            cur += fen.qry(p - 1) - fen.qry(j - 1);
            fen.add(p, -1);
        }
        if(ans != 1e18) cout << ans << '\n';
        else cout << -1 << '\n';
    }
}