#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, check1, a1, b1, a2, b2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        cin >> a1 >> a2 >> b1 >> b2;
        if (a1 < a2) {
            swap(a1, a2);
        }
        if (b1 < b2) {
            swap(b1, b2);
        }

        if (a1 == b1 && a1 == a2 + b2) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}