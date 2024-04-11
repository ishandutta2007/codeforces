// 1197D
// valore di un subarray = somma elementi - k * ceil(...), trovare massimo
// idee: dp

#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000000010

long long i, i1, j, k, t, n, m, res, check1, a[300010], b, v[300010][15];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n >> m >> k;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (j = 0; j < m; j++) {
        v[0][j] = -INF;
    }

    for (i = 1; i <= n; i++) {
        v[i][0] = max(v[i - 1][m - 1], (long long)0) + a[i] - k;
        for (j = 1; j < m; j++) {
            v[i][j] = v[i - 1][j - 1] + a[i];
        }
    }

    res = 0;
    for (i = 1; i <= n; i++) {
        for (j = 0; j < m; j++) {
            res = max(res, v[i][j]);
        }
    }

    cout << res;

    return 0;
}