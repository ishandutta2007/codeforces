#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define INF (ll)1e18

ll i, i1, j, k, k1, nw, c, l, r, s, sn, t, n, m, res, check1, a[1010], b, ps[1010], ss[1010], s1, s2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        cin >> n;
        s = 0;
        for (i = 0; i < n; i++) {
            cin >> a[i]; s += a[i];
        }
        /* ps[0] = a[0]; ss[0] = a[n - 1];
        for (i = 1; i < n; i++) {
            ps[i] = ps[i - 1] + a[i];
            ss[i] = ss[i - 1] + a[n - i - 1];
        } */
        k = a[0]; nw = 1; l = 1; r = n - 1; s1 = a[0]; s2 = 0; res = 1; s -= a[0];
        while (s > k) {
            c = 0; sn = 0;
            if (nw == 0) {
                while (sn <= k) {
                    sn += a[l]; l++;
                }
                nw = 1; s1 += sn;
            } else {
                while (sn <= k) {
                    sn += a[r]; r--;
                }
                nw = 0; s2 += sn;
            }
            k = sn; s -= k; res++;
            // cout << sn << endl;
        }
        if (nw == 0) {
            s1 += s;
        } else {
            s2 += s;
        }
        if (s != 0) res++;

        cout << res << ' ' << s1 << ' ' << s2 << endl;
    }

    return 0;
}