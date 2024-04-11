// 552D
// numero triangoli non degeneri

#include <bits/stdc++.h>
using namespace std;

#define eps 1e-8
#define INF 1e15

long long i, i1, j, k, t, n, m, res, check1, a, b, x[2010], y[2010];
vector<double> sl[2010];

long long bnm(long long a) {
    return (a * (a - 1)) / 2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    res = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            if (x[j] == x[i]) {
                sl[i].push_back(INF);
                continue;
            }
            sl[i].push_back((double)(y[j] - y[i]) / (x[j] - x[i]));
        }
        sort(sl[i].begin(), sl[i].end());
        k = 1;
        for (j = 1; j < n - 1; j++) {
            if (sl[i][j] - sl[i][j - 1] < eps) {
                res -= bnm(k);
                k++;
                res += bnm(k);
            } else {
                k = 1;
            }
        }
    }

    res /= 3;
    res = (n * (n - 1) * (n - 2)) / 6 - res;

    cout << res;

    return 0;
}