#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, check1, a, b, s;

int main() {
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n >> s;
    if (s >= 2 * n) {
        cout << "YES" << endl;
        for (i = 0; i < n - 1; i++) {
            cout << 2 << ' ';
        }
        cout << s - (2 * n - 2) << ' ';
        cout << endl;
        cout << 1 << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}