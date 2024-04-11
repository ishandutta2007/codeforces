#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, check1, f[3], o[200010], d, l, r;
string s;

int main() {
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        cin >> s;
        d = s.size();
        for (i = 0; i < d; i++) {
            o[i] = (ll)s[i] - 49;
        }
        for (i = 0; i < 3; i++) {
            f[i] = 0;
        }
        l = 0; r = -1; res = INF;
        while (r < d) {
            if (f[0] > 0 && f[1] > 0 && f[2] > 0) {
                res = min(res, r - l + 1);
                f[o[l]]--; l++;
            } else {
                r++; f[o[r]]++;
            }
        }

        if (res == INF) {
            res = 0;
        }
        cout << res << endl;
    }

    return 0;
}