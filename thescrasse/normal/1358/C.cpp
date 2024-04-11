#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18
#define y1 treapdidsu

ll i, i1, j, k, k1, t, n, m, res, flag, a, b, x1, x2, y1, y2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        cin >> x1 >> y1 >> x2 >> y2;
        res = (x2 - x1) * (y2 - y1) + 1;
        cout << res << endl;
    }

    return 0;
}