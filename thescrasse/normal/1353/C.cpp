#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, check1, a, b;

int main() {
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        cin >> n;
        n /= 2;
        res = 0;
        for (i = 1; i <= n; i++) {
            res += (i * i);
        }
        res *= 8;
        cout << res << endl;
    }

    return 0;
}