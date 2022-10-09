#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, tt, cn[32][2], c;
vector<ll> st;

void solve(vector<ll> v, ll b) {
    /* cout << "solve" << ' ' << b << nl;
    for (auto u : v) cout << u << ' ';
    cout << nl; */

    if (b < 0) return;
    k = 0; c = 0;
    for (auto u : v) {
        if ((u >> b) & 1) k += c;
        else c++;
    }
    cn[b][1] += k;

    k = 0; c = 0;
    for (auto u : v) {
        if ((u >> b) & 1) c++;
        else k += c;
    }
    cn[b][0] += k;

    vector<ll> l, r;
    for (auto u : v) {
        if ((u >> b) & 1) r.pb(u);
        else l.pb(u);
    }

    if (!l.empty()) solve(l, b - 1);
    if (!r.empty()) solve(r, b - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a; st.pb(a);
    }

    solve(st, 31);
    res = 0; tt = 0;
    for (b = 0; b <= 31; b++) {
        tt += min(cn[b][0], cn[b][1]);
        if (cn[b][1] < cn[b][0]) res += (1 << b);
        // cout << cn[b][0] << ' ' << cn[b][1] << nl;
    }
    cout << tt << ' ' << res << nl;

    return 0;
}