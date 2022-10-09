#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, flag[2], x, a, b, degr[1010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        cin >> n >> x;
        for (i = 1; i <= n; i++) degr[i] = 0;
        for (i = 0; i < n - 1; i++) {
            cin >> a >> b;
            degr[a]++; degr[b]++;
        }

        if (degr[x] <= 1) {
            cout << "Ayush" << endl;
        } else if (n % 2 == 1) {
            cout << "Ashish" << endl;
        } else {
            cout << "Ayush" << endl;
        }
    }

    return 0;
}