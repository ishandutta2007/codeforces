#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<
#define tm guerwnogien

#define INF (ll)1e18
#define mod 998244353
#define maxn 2010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll mt[maxn][maxn], mm, dist[maxn], tm;
bool vis[maxn];
array<ll, 2> mp;
array<ll, 3> mn;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n; mn = {INF, -1, -1};
    for (i = 1; i <= n - 1; i++) {
        for (j = i + 1; j <= n; j++) {
            cin >> mt[i][j]; mt[j][i] = mt[i][j];
            mn = min(mn, {mt[i][j], i, j});
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == j) continue;
            mt[i][j] -= mn[0];
        }
    }

    for (i = 1; i <= n; i++) {
        if (i == mn[1] || i == mn[2]) continue;
        mm = INF;
        for (j = 1; j <= n; j++) {
            if (j == i) continue;
            mm = min(mm, mt[i][j]);
        }
        // too early?
        mt[i][mn[1]] = min(mt[i][mn[1]], 2 * mm);
        mt[i][mn[2]] = min(mt[i][mn[2]], 2 * mm);
        mt[mn[1]][i] = min(mt[mn[1]][i], 2 * mm);
        mt[mn[2]][i] = min(mt[mn[2]][i], 2 * mm);
    }

    /* for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cout << mt[i][j] << ' ';
        }
        cout << nl;
    } */

    for (i = 1; i <= n; i++) dist[i] = INF;
    dist[mn[1]] = 0; dist[mn[2]] = 0;

    for (tm = 1; tm <= n; tm++) {
        mp = {INF, INF};
        for (i = 1; i <= n; i++) {
            if (vis[i]) continue;
            mp = min(mp, {dist[i], i});
        }
        i = mp[1]; vis[i] = true;
        for (j = 1; j <= n; j++) dist[j] = min(dist[j], dist[i] + mt[i][j]);
    }

    for (i = 1; i <= n; i++) {
        res = dist[i] + (n - 1) * mn[0];
        cout << res << nl;
    }

    return 0;
}