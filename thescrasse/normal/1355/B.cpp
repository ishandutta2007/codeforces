#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, check1, a, b, e[200010];

int main() {
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> e[i];
        }

        sort(e, e + n);

        res = 0; k = 0;
        for (i = 0; i < n; i++) {
            k++;
            if (e[i] <= k) {
                res++; k = 0;
            }
        }

        cout << res << endl;
    }

    return 0;
}