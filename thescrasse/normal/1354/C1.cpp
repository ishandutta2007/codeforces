#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18
#define PI acos(-1.0)

ll i, i1, j, k, k1, t, n, m, check1, a, b;
long double res;

int main() {
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        cin >> n; n /= 2;
        res = 0;
        for (i = 1; i < n; i++) {
            res += cos((long double)i * PI / (2 * n));
        }
        res *= 2;
        res += 1;
        cout << fixed << setprecision(20);
        cout << res << endl;
    }

    return 0;
}