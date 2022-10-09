#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define endlf "\n" << flush
#define ll long long
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, check1, a, b, c[5010], cr, r1, r2, r3, l;
bool dp[5010][5010];
vector<ll> choices;
bool visited[5010];
vector<ll> adj[5010], cn[2];

void dfs(ll s) {
    // cout << s << endl << flush;
    ll i, j, k;
    if (visited[s]) return;
    visited[s] = true;
    // cout << s << endl << flush;
    cn[c[s]][cr]++;
    // cout << s << endl << flush;
    if (adj[s].empty()) {
        return;
    }
    // cout << s << endl << flush;
    for (auto u : adj[s]) {
        k = (c[s] + 1) % 2;
        if (c[u] != -1 && c[u] != k) check1 = 0;
        c[u] = k;
        dfs(u);
    }
    // cout << s << endl << flush;
}

int main() {
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n >> m;
    cin >> r1 >> r2 >> r3;

    for (i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            dp[i][j] = false;
        }
    }
    dp[0][0] = true;

    check1 = 1;
    for (i = 1; i <= n; i++) {
        c[i] = -1;
    }

    cr = 0;

    for (i = 1; i <= n; i++) {
        // cout << i << endl << flush;
        if (!visited[i]) {
            cn[0].push_back(0); cn[1].push_back(0);
            c[i] = 0; dfs(i);

            a = cn[0][cr]; b = cn[1][cr];
            // cout << a << ' ' << b << endl;
            for (j = 0; j < n; j++) {
                if (dp[cr][j] == false) continue;
                if (j + a <= n) {
                    dp[cr + 1][j + a] = true;
                }
                if (j + b <= n) {
                    dp[cr + 1][j + b] = true;
                }
            }
            cr++;
        }
    }

    /* for (i = 0; i <= 5; i++) {
        for (j = 0; j <= 5; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    } */

    // cout << cr << endl << flush;

    k = r2;
    if (check1 == 0 || dp[cr][k] == false) {
        cout << "NO";
        return 0;
    }

    while (cr >= 1) {
        // cout << cr << endl << flush;
        a = cn[0][cr - 1]; b = cn[1][cr - 1];
        if (k - a >= 0 && dp[cr - 1][k - a] == true) {
            choices.push_back(0); k -= a;
        } else {
            choices.push_back(1); k -= b;
        }
        cr--;
    }

    reverse(choices.begin(), choices.end());

    /* for (auto u : choices) {
        cout << u << ' ';
    }
    cout << endl << flush; */

    cr = 0;
    for (i = 1; i <= n; i++) {
        visited[i] = 0; c[i] = -1;
    }

    for (i = 1; i <= n; i++) {
        if (!visited[i]) {
            // cout << i << ' ' << cr << endl << flush;
            c[i] = choices[cr]; dfs(i);
            cr++;
        }
    }

    k = 0;
    cout << "YES" << endl;
    check1 = 1;
    for (i = 1; i <= n; i++) {
        if (k >= r1) {
            check1 = 3;
        }
        if (c[i] == 1) {
            cout << check1; k++;
        } else {
            cout << 2;
        }
    }
    cout << endl;

    return 0;
}