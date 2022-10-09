#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, flag[2], a[1010], b, x, p;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        cin >> n >> x;
        p = 0; flag[0] = 0; flag[1] = 0;
        for (i = 0; i < n; i++) {
            cin >> a[i]; p += a[i]; p %= 2;
            flag[a[i] % 2] = 1;
        }

        if (x == n) {
            if (p == 1) {
                cout << "Yes" << endl; continue;
            } else {
                cout << "No" << endl; continue;
            }
        } else {
            if (flag[0] == 1 && flag[1] == 1) {
                cout << "Yes" << endl; continue;
            } else if (flag[1] == 0) {
                cout << "No" << endl; continue;
            } else if (x % 2 == 1) {
                cout << "Yes" << endl; continue;
            } else {
                cout << "No" << endl; continue;
            }
        }
    }

    return 0;
}