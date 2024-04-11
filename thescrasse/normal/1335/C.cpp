#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

long long i, i1, j, k, k1, t, n, m, res, check1, a[200010], b, d;
map<long long, long long> f;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        f.clear();
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        m = 0; d = 0;
        for (i = 0; i < n; i++) {
            f[a[i]]++;
            if (f[a[i]] == 1) {
                d++;
            }
            m = max(m, f[a[i]]);
        }
        res = min(m, d);
        if (m == d) {
            res--;
        }
        cout << res << endl;
    }

    return 0;
}