#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 60

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, x, y;
char mt[maxn][maxn], nw[maxn][maxn];
bool visited[maxn][maxn];

ll d1[4] = {1, 0, -1, 0};
ll d2[4] = {0, 1, 0, -1};

void dfs(ll x, ll y) {
    // cout << x << ' ' << y << nf;
    ll i, x1, y1;
    if (visited[x][y]) return;
    visited[x][y] = true;
    for (i = 0; i < 4; i++) {
        x1 = x + d1[i]; y1 = y + d2[i];
        if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && nw[x1][y1] != '#') {
            dfs(x1, y1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        flag[1] = 0;
        cin >> n >> m;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                // cout << i << ' ' << j << nf;
                cin >> mt[i][j];
                if (mt[i][j] == 'G') flag[1] = 1;
                // cout << mt[i][j] << nf;
                visited[i][j] = false;
                nw[i][j] = mt[i][j];
            }
        }

        if (flag[1] == 0) {
            cout << "Yes" << nl;
            continue;
        }

        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (mt[i][j] == 'B') {
                    nw[i][j] = '#';
                    for (k = 0; k < 4; k++) {
                        x = i + d1[k]; y = j + d2[k];
                        // cout << x << ' ' << y << nl;
                        if (x >= 0 && x < n && y >= 0 && y < m) {
                            nw[x][y] = '#';
                        }
                    }
                }
            }
        }

        /* for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cout << nw[i][j] << ' ';
            }
            cout << nl;
        } */

        // cout << n << ' ' << m << nf;
        if (nw[n - 1][m - 1] == '#') {
            cout << "No" << nl;
            continue;
        }

        dfs(n - 1, m - 1);
        flag[0] = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                // cout << visited[i][j] << ' ';
                if (mt[i][j] == 'G' && visited[i][j] == false) flag[0] = 1;
            }
            // cout << nl;
        }

        if (flag[0] == 0) cout << "Yes";
        else cout << "No";
        cout << nl;
    }

    return 0;
}