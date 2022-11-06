#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 10, inf = 1e9 + 1;
int a[maxn], b[maxn], sa[maxn], sb[maxn], ma[maxn], mb[maxn];
pair<int, int> va[maxn], vb[maxn];
int n, m, k, s, vap, vbp, anspa, anspb;

bool check(int d) {
    int pa = k, pb = 0;
    int mc = inf, anspan, anspbn;
    while (pa >= 0) {
        if (sa[pa] * ma[d] + sb[pb] * mb[d] < mc) {
            mc = sa[pa] * ma[d] + sb[pb] * mb[d];
            anspan = pa; anspbn = pb;
        }
        ++pb; --pa;
    }
    if (mc <= s) anspa = anspan, anspb = anspbn;
    return mc <= s;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> k >> s;
    ma[0] = mb[0] = inf;
    for (int i = 1; i <= n; ++i) cin >> a[i], ma[i] = min(ma[i - 1], a[i]);
    for (int i = 1; i <= n; ++i) cin >> b[i], mb[i] = min(mb[i - 1], b[i]);
    for (int i = 1; i <= m; ++i) {
        int t, c; cin >> t >> c;
        if (t == 1) va[++vap] = make_pair(c, i);
        else vb[++vbp] = make_pair(c, i);
    }
    sort(va + 1, va + vap + 1); sort(vb + 1, vb + vbp + 1);
    fill(sa, sa + maxn, inf); fill(sb, sb + maxn, inf); 
    sa[0] = sb[0] = 0;
    for (int i = 1; i <= vap; ++i) sa[i] = sa[i - 1] + va[i].first;
    for (int i = 1; i <= vbp; ++i) sb[i] = sb[i - 1] + vb[i].first;
    int d = 1, ans = n; while (d <= n) d <<= 1;
    while (d >>= 1) if (ans - d >= 1) if (check(ans - d)) ans -= d;
    if (!check(ans)) return cout << "-1" << endl, 0;
    int ansa = 0, ansb = 0;
    cout << ans << endl;
    for (int i = 1; i <= ans; ++i) {
        if (a[i] == ma[ans]) ansa = i;
        if (b[i] == mb[ans]) ansb = i;
    }
    for (int i = 1; i <= anspa; ++i) {
        cout << va[i].second << ' ' << ansa << endl;
    }
    for (int i = 1; i <= anspb; ++i) {
        cout << vb[i].second << ' ' << ansb << endl;
    }
    return 0;
}