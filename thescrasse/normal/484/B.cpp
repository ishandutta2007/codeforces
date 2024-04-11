// 484B
// Maximum Value

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, flag, a[200010], b, f[2000010], l;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);
    f[0] = 0; l = 0;
    for (i = 1; i < 2000010; i++) {
        if (l < n && a[l] == i - 1) {
            f[i] = i - 1;
            while (l < n && a[l] == i - 1) {
                l++;
            }
        } else {
            f[i] = f[i - 1];
        }
    }

    res = 0;
    for (i = 0; i < n; i++) {
        if (i == 0 || a[i] != a[i - 1]) {
            k = a[i];
            for (j = 2 * k; j < 2000010; j += k) {
                res = max(res, f[j] % k);
            }
        }
    }

    cout << res;

    return 0;
}