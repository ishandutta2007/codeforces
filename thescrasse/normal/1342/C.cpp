#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, a, b, l, r, check1, v1, v2, lcm, q, v1m, v2m;
string s;

ll gcd(ll a, ll b) {
    if (a == b) {
        return a;
    }
    if (a < b) {
        swap(a, b);
    }
    a = ((a + b - 1) % b) + 1;
    return gcd(a, b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        cin >> a >> b >> q;
        while (q--) {
            if (a > b) {
                swap(a, b);
            }
            cin >> l >> r;

            lcm = (a / gcd(a, b)) * b;
            res = 0;
            check1 = 1;
            k = l % lcm;
            if (k < b) {
                if (l + (b - 1) - k <= r) {
                    res += (b - k);
                } else {
                    check1 = 0;
                }
            }
            v1 = (l + lcm) / lcm; v1m = v1 * lcm;
            v2 = r / lcm; v2m = v2 * lcm;
            res += (v2 - v1 + 1) * b;
            if (v2m + b - 1 > r) {
                res -= (v2m + b - 1 - r);
            }

            if (check1 == 0) {
                cout << 0 << ' ';
            } else {
                res = r - l + 1 - res;
                cout << res << ' ';
            }
        }
        cout << endl;
    }

    return 0;
}