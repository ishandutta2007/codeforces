#include <bits/stdc++.h>
using namespace std;

const int N = 200001, LG = bit_width((unsigned) N);

int zeroes[LG][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < LG; ++i) {
        for (int j = 1; j < N; ++j) {
            zeroes[i][j] = zeroes[i][j - 1] + ((j & (1 << i)) == 0);
        }
    }

    int t; cin >> t;

    while (t--) {
        int l, r; cin >> l >> r;

        int ans = r - l;
        for (int i = 0; i < LG; ++i) {
            ans = min(ans, zeroes[i][r] - zeroes[i][l - 1]);
        }

        cout << ans << "\n";
    }
}