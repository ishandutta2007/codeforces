// 1242C
// Sum Balance

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 5010

ll i, i1, j, k, k1, t, n[20], res, flag[10], a[20][5010], b, s, tt[maxn], c, x, st[33010], dp[33010], o;
map<ll, array<ll, 3>> m;
array<ll, 3> y;
bool visited[20];
vector<ll> r[2];
array<ll, 2> sl[20];

void dfs(ll s) {
    // cout << "s = " << s << nl;
    ll i, j, x;
    if (m.find(s) == m.end()) return;
    if (m[s][2] == 2) return;
    if (m[s][2] == 1) {
        // cout << "cyc start = " << s << nl;
        for (i = 0; i < k; i++) visited[i] = false;
        x = s; flag[0] = 1;
        while (true) {
            x = m[x][0];
            // cout << "x = " << x << nf;
            if (visited[m[x][1]]) {
                flag[0] = 0; break;
            }
            visited[m[x][1]] = true;
            // cout << "mx1 = " << m[x][1] << nl;
            if (x == s) break;
        }

        if (flag[0] == 1) {
            x = 0;
            for (i = 0; i < k; i++) {
                if (visited[i]) x += (1 << i);
            }
            st[x] = s + INF;
            // cout << "x = " << x << nl;
        }

        return;
    }
    m[s][2] = 1;
    dfs(m[s][0]);
    m[s][2] = 2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> k; s = 0;
    for (i = 0; i < k; i++) {
        cin >> n[i]; tt[i] = 0;
        for (j = 0; j < n[i]; j++) {
            cin >> a[i][j];
            s += a[i][j]; tt[i] += a[i][j];
        }
    }

    if (s % k != 0) {
        cout << "No"; return 0;
    }

    s /= k;
    for (i = 0; i < k; i++) {
        for (j = 0; j < n[i]; j++) {
            x = a[i][j];
            b = s - tt[i] + x;
            m[x] = {b, i, 0};
        }
    }

    for (auto u : m) {
        // cout << "u.first = " << u.first << nf;
        dfs(u.first);
    }

    // cout << "ok" << nf;

    dp[0] = INF;
    for (i = 1; i < (1 << k); i++) {
        for (j = i;; j = (j - 1) & i) {
            if (dp[j] && st[i - j]) dp[i] = i - j;
            if (j == 0) break;
        }
        // cout << i << ' ' << dp[i] << nf;
    }

    if (dp[(1 << k) - 1] == 0) {
        cout << "No"; return 0;
    }

    cout << "Yes" << nl;
    x = (1 << k) - 1;
    while (x != 0) {
        // cout << "x = " << x << nf;
        o = dp[x]; x -= o;
        s = st[o] - INF; c = s;
        r[0].clear(); r[1].clear();
        while (true) {
            c = m[c][0];
            r[0].pb(m[c][0]); r[1].pb(m[c][1]);
            // cout << m[c][0] << ' ' << m[c][1] << nl;
            if (c == s) break;
        }

        s = r[0].size();
        for (i = 0; i < s; i++) {
            sl[r[1][(i + 1) % s]] = {r[0][i], r[1][i] + 1};
        }
    }

    for (i = 0; i < k; i++) {
        cout << sl[i][0] << ' ' << sl[i][1] << nl;
    }

    return 0;
}