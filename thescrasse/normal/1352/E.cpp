#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define INF (ll)1e18

ll i, i1, j, k, k1, nw, c, l, r, s, sn, t, n, m, res, check1, a[8010], b, ps[8010], used[8010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        res = 0;
        for (i = 0; i <= n; i++) {
            used[i] = 0;
        }
        cin >> n;
        for (i = 1; i <= n; i++) {
            cin >> a[i]; used[a[i]]++;
        }

        ps[0] = 0;
        for (i = 1; i <= n; i++) {
            ps[i] = ps[i - 1] + a[i];
        }

        for (i = 0; i <= n; i++) {
            for (j = i + 2; j <= n; j++) {
                k = ps[j] - ps[i];
                // cout << k << ' ';
                if (k <= n) {
                    if (used[k] != 0) {
                        res += used[k]; used[k] = 0;
                    }
                }
            }
        }
        // cout << endl;

        cout << res << endl;
    }

    return 0;
}