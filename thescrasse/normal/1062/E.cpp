// 1062E
// Company

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define tm treapdidsu

#define INF (int)1e9
#define mod 1000000007
#define maxn 310010

int i, i1, j, k, k1, t, n, m, res, flag[10], a, b, q, l, r, tm[maxn][2], dist[maxn], msb[maxn], x, y;
array<array<int, 2>, 2> sp1[maxn][20];
array<int, 2> sp2[maxn][20], v, w;
vector<int> adj[maxn];

void et(int x, int y) {
    sp2[k][0] = {dist[x], x};
    tm[x][y] = k; k++;
}

void dfs(int s) {
    et(s, 0);
    for (auto u : adj[s]) {
        if (tm[u][0] != 0) continue;
        dist[u] = dist[s] + 1; dfs(u);
        et(s, 1);
    }
    et(s, 1);
}

array<int, 2> rmq(int t, int l, int r) {
    if (r <= l - 1) {
        if (t == 1) return {-INF, -INF};
        else return {INF, INF};
    }
    int i, j, k, s, a, b;
    s = r - l + 1; j = msb[s]; k = 1 << msb[s];
    a = l; b = r - k + 1;
    if (t == 0) return min(sp1[a][j][0], sp1[b][j][0]);
    else if (t == 1) return max(sp1[a][j][1], sp1[b][j][1]);
    else return min(sp2[a][j], sp2[b][j]);
}

array<int, 2> rmqx(int t, int l, int r, int x) {
    if (t == 1) return max(rmq(t, l, x - 1), rmq(t, x + 1, r));
    else return min(rmq(t, l, x - 1), rmq(t, x + 1, r));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> q;

    msb[0] = -1;
    for (i = 1; i <= 4 * n; i++) {
        if (__builtin_popcount(i) == 1) msb[i] = msb[i - 1] + 1;
        else msb[i] = msb[i - 1];
    }

    for (i = 2; i <= n; i++) {
        cin >> a;
        adj[a].push_back(i); adj[i].push_back(a);
    }

    for (i = 1; i <= n; i++) {
        tm[i][0] = 0; tm[i][1] = 0;
    }
    k = 1; dist[1] = 0; dfs(1);

    for (i = 1; i <= n; i++) {
        sp1[i][0][0] = {tm[i][0], i};
        sp1[i][0][1] = {tm[i][1], i};
        // cout << i << ' ' << tm[i][0] << ' ' << tm[i][1] << nl;
    }
    for (i = 1; i <= n; i++) {
        for (j = 0; j < 2; j++) {
            sp2[tm[i][j]][0] = {dist[i], i};
        }
    }

    k1 = k - 1; k = 1;

    // for (i = 1; i <= k1; i++) cout << i << ' ' << sp2[i][0][0] << nl;

    for (i = 2; i <= n; i <<= 1) {
        for (j = 1; j <= n - i + 1; j++) {
            sp1[j][k][0] = min(sp1[j][k - 1][0], sp1[j + i / 2][k - 1][0]);
            sp1[j][k][1] = max(sp1[j][k - 1][1], sp1[j + i / 2][k - 1][1]);
        }
        k++;
    }

    k = 1;
    for (i = 2; i <= k1; i <<= 1) {
        for (j = 1; j <= k1 - i + 1; j++) {
            sp2[j][k] = min(sp2[j][k - 1], sp2[j + i / 2][k - 1]);
            // cout << j << ' ' << k << ' ' << sp2[j][k][0] << nl;
        }
        k++;
    }

    while (q--) {
        cin >> l >> r;
        v = rmq(0, l, r); w = rmq(1, l, r);
        x = rmqx(0, l, r, v[1])[0]; y = rmqx(1, l, r, w[1])[0];
        // cout << x << ' ' << y << nl;
        if (v[1] == w[1]) {
            x = rmq(2, x, y)[0];
            cout << v[1] << ' ' << x << nl;
            continue;
        }
        x = rmq(2, x, w[0])[0]; y = rmq(2, v[0], y)[0];
        // cout << l << ' ' << r << ' ' << v[1] << ' ' << w[1] << ' ' << x << ' ' << y << ' ' << nl;
        if (x > y) {
            cout << v[1] << ' ' << x << nl;
        } else {
            cout << w[1] << ' ' << y << nl;
        }
    }

    return 0;
}