#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, check1, a[200010], b;
map<ll, ll> f;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        check1 = 0;
        f.clear();
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> a[i];
            k = (a[i] + i) % n;
            k += n; k %= n;
            f[k]++;
            if (f[k] == 2) {
                check1 = 1;
            }
        }

        if (check1 == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}