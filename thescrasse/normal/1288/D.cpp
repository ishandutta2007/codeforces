// 1288D
// Minimax Problem

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, flag, a, b, mt[300010][10], v[300010], bsl, bsu, bsm, used[1010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n >> m;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> mt[i][j];
        }
    }

    bsl = 0; bsu = (ll)1e9 + 10;
    while (bsl < bsu) {
        for (i = 0; i < (1 << m); i++) {
            used[i] = -1;
        }
        bsm = (bsl + bsu) / 2;
        flag = 0;
        for (i = 0; i < n; i++) {
            v[i] = 0;
            for (j = 0; j < m; j++) {
                if (mt[i][j] >= bsm) {
                    v[i] += (1 << j);
                }
            }
            used[v[i]] = i;
        }

        for (i = 0; i < (1 << m); i++) {
            for (j = 0; j < (1 << m); j++) {
                if (used[i] != -1 && used[j] != -1) {
                    if ((i | j) == (1 << m) - 1) {
                        flag = 1; a = used[i]; b = used[j];
                    }
                }
            }
        }

        if (flag == 1) {
            bsl = bsm + 1;
        } else {
            bsu = bsm;
        }
    }

    cout << a + 1 << ' ' << b + 1 << endl;

    return 0;
}