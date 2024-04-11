#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        int sol = 0;
        vector<int> perm = { 1, 2, 3, 4, 5, 6, 7 };
        do {
            int i = 0;
            int x = a;
            int y = b;
            int z = c;
            for ( ; i < 7; i++) {
                if (perm[i] & 1) {
                    if (x) {
                        x--;
                    } else break;
                }
                if (perm[i] & 2) {
                    if (y) {
                        y--;
                    } else break;
                }
                if (perm[i] & 4) {
                    if (z) {
                        z--;
                    } else break;
                }
            }
            sol = max(sol, i);
        } while (next_permutation(perm.begin(), perm.end()));
        cout << sol << '\n';
    }
}