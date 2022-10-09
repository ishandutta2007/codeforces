#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define INF (ll)1e18

long long i, i1, j, k, k1, t, n, m, res, check1, a, b, x, y, v1, v2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        cin >> x >> y >> a >> b;
        if (x < 0) {
            x *= -1; y *= -1;
        }
        if (x < y) {
            swap(x, y);
        }
        if (y >= 0) {
            if (2 * a <= b) {
                cout << a * (x + y) << endl;
            } else {
                cout << b * y + a * (x - y) << endl;
            }
        } else {
            cout << a * (x - y) << endl;
        }
    }

    return 0;
}