#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, check1, a, b, c, d;

int main() {
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        res = 0;
        cin >> a >> b >> c >> d;
        if (b >= a) {
            cout << b << endl;
            continue;
        }
        res += b; a -= b;
        if (d >= c) {
            cout << -1 << endl;
            continue;
        } else {
            res += c * ((a + c - d - 1) / (c - d));
            cout << res << endl;
        }
    }

    return 0;
}