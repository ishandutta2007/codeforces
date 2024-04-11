#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

long long i, i1, j, k, k1, t, n, m, res, check1, a[200010], b, s, c[210], st, tot, resp, l, r;
vector<short> adj[210][210];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        for (i = 1; i <= 200; i++) {
            c[i] = 0;
        }
        for (i = 1; i <= 200 - 1; i++) {
            for (j = i + 1; j <= 200; j++) {
                adj[i][j].clear();
            }
        }
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> a[i];
            k = a[i];
            c[k]++;
            for (j = 1; j <= 200; j++) {
                if (j < k) {
                    adj[j][k].push_back(k);
                } else if (j > k) {
                    adj[k][j].push_back(k);
                }
            }
        }

        res = 0;
        for (i = 1; i <= 200 - 1; i++) {
            for (j = i + 1; j <= 200; j++) {
                if (adj[i][j].empty()) {
                    continue;
                }
                /* if (c[i] == 0 || c[j] == 0) {
                    continue; // cancellalo!
                } */
                // cout << i << ' ' << j << endl;
                s = adj[i][j].size();
                tot = c[j];
                resp = tot;
                st = c[i] / 2;
                l = -1;
                r = s;
                while (st--) {
                    while (adj[i][j][l + 1] == j) {
                        l++; tot--;
                    }
                    while (adj[i][j][r - 1] == j) {
                        r--; tot--;
                    }
                    // cout << l << ' ' << r << endl;
                    l++; r--;
                    tot += 2;
                    resp = max(resp, tot);
                }
                // cout << resp << endl << endl;
                res = max(res, resp);

                tot = c[i];
                resp = tot;
                st = c[j] / 2;
                l = -1;
                r = s;
                while (st--) {
                    while (adj[i][j][l + 1] == i) {
                        l++; tot--;
                    }
                    while (adj[i][j][r - 1] == i) {
                        r--; tot--;
                    }
                    // cout << l << ' ' << r << endl;
                    l++; r--;
                    tot += 2;
                    resp = max(resp, tot);
                }
                // cout << resp << endl << endl;
                res = max(res, resp);
            }
        }
        cout << res << endl;
        // cout << "--------------------------------" << endl << endl;
    }

    return 0;
}