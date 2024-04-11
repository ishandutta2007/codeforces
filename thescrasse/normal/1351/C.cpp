#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, check1, a1, b1, a2, b2, x, y;
map<array<ll, 3>, bool> f;
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        x = 0; y = 0;
        f.clear();
        cin >> s;
        res = 0;

        for (i = 0; i < s.size(); i++) {
            if (s[i] == 'N') {
                y++; k = 0;
            }
            if (s[i] == 'S') {
                y--; k = 0;
            }
            if (s[i] == 'E') {
                x++; k = 1;
            }
            if (s[i] == 'W') {
                x--; k = 1;
            }
            if (f[{x, y, k}] == false) {
                res += 5;
            } else {
                res++;
            }
            f[{x, y, k}] = true;

            if (s[i] == 'N') {
                y++; k = 0;
            }
            if (s[i] == 'S') {
                y--; k = 0;
            }
            if (s[i] == 'E') {
                x++; k = 1;
            }
            if (s[i] == 'W') {
                x--; k = 1;
            }
        }

        cout << res << endl;
    }

    return 0;
}