// 1503D
// Flip the Cards

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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll c[maxn], ls, rs, tl1, tl2, tr1, tr2;
vector<array<ll, 3>> vl, vr;
bool vis[maxn];

bool upd(ll ty, ll v) {
    if (ty == 1) {
        if (v == 1) vis[vl[ls][2]] = true;
        while (ls <= n && vis[vl[ls][2]]) ls++;
        if (ls == n + 1) return true;
    } else {
        if (v == 1) vis[vr[rs][2]] = true;
        while (rs >= 1 && vis[vr[rs][2]]) rs--;
        if (ls == 0) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n; flag[0] = 1;
    vl.pb({-1, -1, -1}); vr.pb({-1, -1, -1});
    for (i = 1; i <= n; i++) {
        cin >> a >> b;
        if (a > b) {
            swap(a, b); c[i] = 1;
        }
        vl.pb({a, b, i}); vr.pb({b, a, i});
    }

    sort(vl.begin(), vl.end()); sort(vr.begin(), vr.end());
    for (auto &u : vr) swap(u[0], u[1]);

    if (vl[n][0] != n || vr[1][1] != n + 1) {
        cout << -1 << nl; return 0;
    }

    ls = 1; rs = n;
    while (true) {
        if (upd(1, 0) || upd(2, 0)) break;
        tl1 = vl[ls][0]; tr1 = vl[ls][1]; tl2 = vr[rs][0]; tr2 = vr[rs][1];
        if (tr1 < tl2) {
            flag[0] = 0; break;
        }
        a = 0; b = 0;
        if (vl[ls][2] != vr[rs][2]) {
            a = c[vl[ls][2]] + (c[vr[rs][2]] ^ 1); b = 2;
        }
        if (upd(1, 1) || upd(2, 1)) break;
        while (true) {
            flag[1] = 0;

            if (upd(1, 0)) break;
            if (vl[ls][0] < tl2) {
                if (vl[ls][1] > tr1) flag[0] = 0;
                tl1 = vl[ls][0]; tr1 = vl[ls][1];
                a += c[vl[ls][2]]; b++; flag[1] = 1;
                if (upd(1, 1)) break;
            }
            if (upd(2, 0)) break;
            if (vr[rs][1] > tr1) {
                if (vr[rs][0] < tl2) flag[0] = 0;
                tl2 = vr[rs][0]; tr2 = vr[rs][1];
                a += (c[vr[rs][2]] ^ 1); b++; flag[1] = 1;
                if (upd(2, 1)) break;
            }
            if (flag[1] == 0) break;
        }

        res += min(a, b - a);
        if (flag[0] == 0) break;
    }

    if (flag[0] == 0) cout << -1 << nl;
    else cout << res << nl;

    return 0;
}