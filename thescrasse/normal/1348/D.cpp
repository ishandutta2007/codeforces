#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, check1, a, b, mx[50], p2[50];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    mx[0] = 0; p2[0] = 1;
    for (i = 1; i <= 40; i++) {
        mx[i] = 2 * mx[i - 1] + 2;
        p2[i] = 2 * p2[i - 1];
    }
    cin >> t;
    while (t--) {
        cin >> n;
        n--;
        k = 0;
        if (n == 1) {
            cout << 1 << endl << 0 << endl;
            continue;
        }
        while (mx[k + 1] <= n) {
            k++;
        }

        if (mx[k] == n) {
            cout << k << endl;
            for (i = 0; i < k; i++) {
                cout << p2[i] << ' ';
            }
        } else {
            cout << k + 1 << endl;
            for (i = 0; i < k - 1; i++) {
                cout << p2[i] << ' ';
            }
            if (n - mx[k] >= p2[k]) {
                cout << p2[k - 1] << ' ';
                cout << n - mx[k] - p2[k] << ' ';
            } else {
                k1 = (n - mx[k - 1]) / 2;
                cout << k1 - p2[k - 1] << ' ';
                cout << (n - mx[k - 1]) % 2 << ' ';
            }
        }

        cout << endl;
    }

    return 0;
}