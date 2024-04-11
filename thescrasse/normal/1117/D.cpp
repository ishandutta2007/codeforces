// 1117D
// possibili somme ordinate

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, res, check1, a, b, st[110][110], xp[110][110], tr[110][110], mod;
vector<long long> steps;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    mod = 1000000007;
    cin >> n >> m;

    if (n < m) {
        cout << 1;
        return 0;
    }

    if (n == m) {
        cout << 2;
        return 0;
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            st[i][j] = 0;
        }
    }

    st[0][0] = 1;
    st[0][m - 1] = 1;
    for (i = 0; i < m - 1; i++) {
        st[i + 1][i] = 1;
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            xp[i][j] = st[i][j];
        }
    }

    k = n - m + 1;
    while (k > 1) {
        if (k % 2 == 1) {
            steps.push_back(1);
        }
        k /= 2;
        steps.push_back(2);
    }

    reverse(steps.begin(), steps.end());
    for (auto u : steps) {
        // cout << u << endl;
        if (u == 1) {
            for (i = 0; i < m; i++) {
                for (j = 0; j < m; j++) {
                    tr[i][j] = 0;
                    for (k = 0; k < m; k++) {
                        tr[i][j] = (tr[i][j] + xp[i][k] * st[k][j]) % mod;
                    }
                }
            }
        } else {
            for (i = 0; i < m; i++) {
                for (j = 0; j < m; j++) {
                    tr[i][j] = 0;
                    for (k = 0; k < m; k++) {
                        tr[i][j] = (tr[i][j] + xp[i][k] * xp[k][j]) % mod;
                    }
                }
            }
        }

        for (i = 0; i < m; i++) {
            for (j = 0; j < m; j++) {
                xp[i][j] = tr[i][j];
                // cout << xp[i][j] << ' ';
            }
            // cout << endl;
        }
    }

    res = 0;
    for (i = 0; i < m; i++) {
        res = (res + xp[0][i]) % mod;
    }

    cout << res;

    return 0;
}