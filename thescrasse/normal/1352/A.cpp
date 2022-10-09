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
        cin >> n;
        res = 0; k = 0; r.clear();
        while (n > 0) {
            if (n % 10 != 0) {
                res++; r.push_back((n % 10) * p10[k]);
            }
            n /= 10; k++;
        }
        cout << res << endl;
        for (auto u : r) {
            cout << u << ' ';
        }
        cout << endl;
    }

    return 0;
}