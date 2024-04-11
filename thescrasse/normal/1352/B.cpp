#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, check1, a, b, p10[7];
vector<ll> r;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    p10[0] = 1;
    for (i = 1; i < 7; i++) {
        p10[i] = p10[i - 1] * 10;
    }
    while (t--) {
        cin >> n >> k;
        if (k % 2 == 0 && n % 2 != 0) {
            cout << "NO" << endl;
            continue;
        }
        if (k % 2 == 0) {
            if (n < k) {
                cout << "NO" << endl;
                continue;
            } else {
                cout << "YES" << endl;
                for (i = 0; i < k - 1; i++) {
                    cout << 1 << ' ';
                }
                cout << n - k + 1 << ' ';
                cout << endl;
            }
        } else {
            if (n % 2 != 0) {
                if (n < k) {
                    cout << "NO" << endl;
                    continue;
                } else {
                    cout << "YES" << endl;
                    for (i = 0; i < k - 1; i++) {
                        cout << 1 << ' ';
                    }
                    cout << n - k + 1 << ' ';
                    cout << endl;
                }
            } else {
                if (n < 2 * k) {
                    cout << "NO" << endl;
                    continue;
                } else {
                    cout << "YES" << endl;
                    for (i = 0; i < k - 1; i++) {
                        cout << 2 << ' ';
                    }
                    cout << n - 2 * k + 2 << ' ';
                    cout << endl;
                }
            }
        }
    }

    return 0;
}