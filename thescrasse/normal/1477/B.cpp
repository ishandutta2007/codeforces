#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, l, r, cn[2], q;
string s, f;
vector<array<ll, 2>> v;
vector<array<ll, 3>> rm;
set<array<ll, 3>> st;
array<ll, 3> o;
array<ll, 2> el, er;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> q >> s >> f; s = '#' + s + '#'; f = '#' + f + '#';
        st.clear(); v.clear(); rm.clear(); flag[0] = 1;
        for (i = 1; i <= q; i++) {
            cin >> a >> b; v.pb({a, b});
        }

        reverse(v.begin(), v.end());

        l = -1;
        for (i = 1; i <= n + 1; i++) {
            if (f[i] != f[i - 1]) {
                if (l != -1) st.insert({l, i - 1, (ll)f[i - 1] - '0'});
                l = i;
            }
        }

        for (auto u : v) {
            l = u[0]; r = u[1]; cn[0] = 0; cn[1] = 0; rm.clear();
            el = {-1, -1}; er = {-1, -1};
            auto itl = st.lower_bound({l + 1, -INF, -INF}); itl--;
            while (true) {
                o = (*itl); rm.pb(o);
                cn[o[2]] += (min(r, o[1]) - max(l, o[0]) + 1);

                if (o[0] < l) el = {o[0], o[2]};
                if (o[1] > r) er = {o[1], o[2]};
                if (o[1] >= r) break;

                itl++;
            }

            if (cn[0] == cn[1]) flag[0] = 0;
            else if (cn[0] > cn[1]) k = 0;
            else k = 1;

            for (auto e : rm) st.erase(e);

            st.insert({l, r, k});
            if (el[0] != -1) st.insert({el[0], l - 1, el[1]});
            if (er[0] != -1) st.insert({r + 1, er[0], er[1]});

            // for (auto e : st) cout << e[0] _ e[1] _ e[2] << nl;
        }

        // cout << nl;

        for (auto u : st) {
            l = u[0]; r = u[1]; k = u[2];
            for (i = l; i <= r; i++) {
                if ((ll)s[i] - '0' != k) flag[0] = 0;
            }
        }

        if (flag[0] == 0) {
            cout << "NO" << nl;
        } else {
            cout << "YES" << nl;
        }
    }

    return 0;
}