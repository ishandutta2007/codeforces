#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, tc, n, m, res, flag[10], a, b;
ll f[30], cn[30], sz;
bool vis[30];
string s, rse, rs1, rs2;
vector<array<ll, 2>> v;

void reset() {
    ll i;
    for (i = 0; i <= 25; i++) {
        f[i] = 0; cn[i] = 0; vis[i] = false;
    }
    v.clear(); rs1.clear(); rs2.clear(); rse.clear();
    rse = '#';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> tc;
    while (tc--) {
        cin >> s; n = s.size(); s = '#' + s; reset();

        for (i = 1; i <= n; i++) {
            f[(ll)s[i] - 'a'] = i; cn[(ll)s[i] - 'a']++;
        }
        for (i = 0; i <= 25; i++) {
            if (f[i] == 0) continue;
            v.pb({f[i], i});
        }
        v.pb({-1, -1});

        sort(v.begin(), v.end()); sz = (ll)v.size() - 1;
        for (i = 1; i <= sz; i++) {
            rs2.pb((char)v[i][1] + 'a');
            cn[v[i][1]] /= i;
        }

        for (i = 1; i <= n; i++) {
            if (cn[(ll)s[i] - 'a'] == 0) break;
            cn[(ll)s[i] - 'a']--; rs1.pb(s[i]);
        }

        for (i = 1; i <= sz; i++) {
            for (auto u : rs1) {
                if (vis[(ll)u - 'a']) continue;
                rse.pb(u);
            }
            vis[(ll)rs2[i - 1] - 'a'] = true;
        }

        // cout << s _ rse << nl;
        if (s == rse) cout << rs1 _ rs2 << nl;
        else cout << -1 << nl;
    }

    return 0;
}