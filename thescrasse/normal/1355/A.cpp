#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, check1, a, b, p[100010];

ll mn(ll x) {
    res = 10;
    while (x > 0) {
        res = min(res, x % 10);
        x /= 10;
    }
    return res;
}

ll mx(ll x) {
    res = -1;
    while (x > 0) {
        res = max(res, x % 10);
        x /= 10;
    }
    return res;
}

int main() {
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        cin >> n >> m;
        k = 1;
        while (mn(n) != 0) {
            p[k] = n;
            n += mn(n) * mx(n);
            k++;
        }

        if (m < k) {
            cout << p[m] << endl;
        } else {
            cout << n << endl;
        }
    }

    return 0;
}