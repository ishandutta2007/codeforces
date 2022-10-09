#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, check1, a, b;

int main() {
   // ifstream cin("input.txt");
   // ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        cin >> n >> m;
        n--;
        n = min(n, (ll)2);
        cout << n * m << endl;
    }

    return 0;
}