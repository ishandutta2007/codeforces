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
        cin >> n;
        if (n <= 3) {
            cout << -1 << endl;
        } else if (n == 4) {
            cout << "3 1 4 2" << endl;
        } else if (n == 5) {
            cout << "5 3 1 4 2" << endl;
        } else if (n % 2 == 0) {
            for (i = 1; i <= n - 5; i += 2) {
                cout << i << ' ';
            }
            cout << n - 2 << ' ' << n << ' ' << n - 3 << ' ' << n - 1 << ' ';
            for (i = n - 4; i >= 2; i -= 2) {
                cout << i << ' ';
            }
            cout << endl;
        } else {
            for (i = 1; i <= n; i += 2) {
                cout << i << ' ';
            }
            cout << n - 3 << ' ' << n - 1 << ' ';
            for (i = n - 5; i >= 2; i -= 2) {
                cout << i << ' ';
            }
            cout << endl;
        }
    }

    return 0;
}