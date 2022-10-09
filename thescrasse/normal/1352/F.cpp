#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define INF (ll)1e18

ll i, i1, j, k, k1, nw, l, r, s, sn, t, n, m, res, check1, a, b, c;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        if (a == 0 && b == 0) {
            for (i = 0; i < c + 1; i++) {
                cout << 1; n = 1;
            }
            cout << endl; continue;
        }
        if (b == 0 && c == 0) {
            for (i = 0; i < a + 1; i++) {
                cout << 0; n = 0;
            }
            cout << endl; continue;
        }
        b--;
        for (i = 0; i < a + 1; i++) {
            cout << 0; n = 0;
        }
        for (i = 0; i < c + 1; i++) {
            cout << 1; n = 1;
        }
        for (i = 0; i < b; i++) {
            n = (n + 1) % 2; cout << n;
        }
        cout << endl;
    }

    return 0;
}