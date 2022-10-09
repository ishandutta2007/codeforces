#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, res[100010], check1, a, b, l[100010], s[100010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");


    cin >> n >> m;
    for (i = 0; i < m; i++) {
        cin >> l[i];
        if (s == 0) {
            s[i] = l[i];
        } else {
            s[i] = s[i - 1] + l[i];
        }
    }

    if (s[m - 1] < n) {
        cout << -1;
        return 0;
    }

    for (i = 0; i < m; i++) {
        if (l[i] > n - i) {
            cout << -1;
            return 0;
        }
    }

    res[0] = 1;
    check1 = 0;
    for (i = 1; i < m; i++) {
        if (check1 == 0) {
            res[i] = res[i - 1] + 1;
            if (res[i] + s[m - 1] - s[i - 1] - 1 < n) {
                res[i] = n - s[m - 1] + s[i - 1] + 1;
                check1 = 1;
            }
        } else {
            res[i] = res[i - 1] + l[i - 1];
        }
    }

    for (i = 0; i < m; i++) {
        cout << res[i] << ' ';
    }

    return 0;
}