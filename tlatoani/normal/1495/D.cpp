//
// Created by Danny Mittal on 3/10/21.
//

#define ll long long

const ll MOD = 998244353LL;
const ll LIMIT = 10000000000000000LL;

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[401];
int dists[401][401];
bool uniquePath[401][401];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (; m; m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            dists[a][b] = -1;
        }
    }
    queue<int> q;
    for (int r = 1; r <= n; r++) {
        dists[r][r] = 0;
        uniquePath[r][r] = true;
        q.push(r);
        while (!q.empty()) {
            int a = q.front();
            q.pop();
            for (int b : adj[a]) {
                if (dists[r][b] == -1) {
                    dists[r][b] = dists[r][a] + 1;
                    uniquePath[r][b] = uniquePath[r][a];
                    q.push(b);
                } else if (dists[r][b] == dists[r][a] + 1) {
                    uniquePath[r][b] = false;
                }
            }
        }
    }
    for (int r = 1; r <= n; r++) {
        for (int s = 1; s <= n; s++) {
            if (uniquePath[r][s]) {
                ll res = 1;
                for (int a = 1; a <= n; a++) {
                    if (dists[r][a] + dists[a][s] != dists[r][s]) {
                        ll amt = 0;
                        for (int b : adj[a]) {
                            if (dists[r][b] + 1 == dists[r][a] && dists[b][s] + 1 == dists[a][s]) {
                                amt++;
                            }
                        }
                        res *= amt;
                        if (res > LIMIT) {
                            res %= MOD;
                        }
                    }
                }
                res %= MOD;
                cout << res << ' ';
            } else {
                cout << 0 << ' ';
            }
        }
        cout << '\n';
    }
    cout << flush;
    return 0;
}