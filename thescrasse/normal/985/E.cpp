// 985E
// matite negli astucci

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, res, check1, a[500010], b, d, nv[500010], p;
bool dp[500010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n >> k >> d;
    for (i = 0; i < n; i++) {
        cin >> a[i + 1];
    }

    sort(a + 1, a + n + 1);

    dp[0] = true;
    p = 0;
    for (i = 1; i < k; i++) {
        nv[i] = p;
    }

    for (i = k; i <= n; i++) {
        nv[i] = p;
        if (a[i] - a[nv[i - k + 1] + 1] <= d) {
            dp[i] = true;
            p = i;
        } else {
            dp[i] = false;
        }
    }

    if (dp[n] == true) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}