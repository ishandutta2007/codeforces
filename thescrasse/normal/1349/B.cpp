#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, check1, check2, a[100010], b, pv;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        // azzera!
        pv = -INF;
        check1 = 0; check2 = 0;

        cin >> n >> k;
        for (i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == k) {
                check1 = 1;
            }
            if (a[i] >= k) {
                if (i - pv <= 2) {
                    check2 = 1;
                }
                pv = i;
            }
        }
        if (check1 == 1 && (check2 == 1 || n == 1)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}