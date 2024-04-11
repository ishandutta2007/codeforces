#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, flag, a[100010], b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> a[i]; a[i]--;
        }

        sort(a, a + n);
        res = -1;
        for (i = 0; i < n; i++) {
            if (a[i] <= i) res = i;
        }
        res += 2;
        cout << res << endl;
    }

    return 0;
}