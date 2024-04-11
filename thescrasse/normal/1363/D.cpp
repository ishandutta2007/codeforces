#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, flag[2], x, a, b, bsl, bsu, bsm, c;
vector<ll> adj[1010];
bool visited[1010];
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (i = 0; i < k; i++) {
            cin >> c;
            adj[i].clear();
            for (j = 0; j < c; j++) {
                cin >> a;
                adj[i].push_back(a);
            }
        }

        cout << "? " << n;
        for (i = 1; i <= n; i++) {
            cout << ' ' << i;
        }
        cout << endl << flush;
        cin >> m;

        bsl = 1; bsu = n;
        while (bsl != bsu) {
            bsm = (bsl + bsu) / 2;
            cout << "? " << bsm;
            for (j = 1; j <= bsm; j++) {
                cout << ' ' << j;
            }
            cout << endl << flush;
            cin >> a;
            if (a == m) {
                bsu = bsm;
            } else {
                bsl = bsm + 1;
            }
        }

        // cout << "!";
        for (i = 0; i < k; i++) {
            flag[0] = 0;
            for (auto u : adj[i]) {
                if (u == bsl) flag[0] = 1;
            }
            if (flag[0] == 0) {
                // cout << ' ' << m;
            } else {
                for (j = 1; j <= n; j++) visited[j] = false;
                for (auto u : adj[i]) visited[u] = true;
                cout << "? " << n - adj[i].size();
                for (j = 1; j <= n; j++) {
                    if (visited[j] == false) {
                        cout << ' ' << j;
                    }
                }
                cout << endl << flush;
                cin >> x;
            }
        }

        cout << "!";
        for (i = 0; i < k; i++) {
            flag[0] = 0;
            for (auto u : adj[i]) {
                if (u == bsl) flag[0] = 1;
            }
            if (flag[0] == 0) {
                cout << ' ' << m;
            } else {
                cout << ' ' << x;
            }
        }

        cout << endl << flush;

        cin >> s;
        if (s == "Incorrect") return 0;
    }

    return 0;
}