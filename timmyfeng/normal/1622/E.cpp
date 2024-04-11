#include <bits/stdc++.h>
using namespace std;

const int N = 10, M = 10000;

int x[N], order[M], coeff[M], perm[M], best[M];
string s[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, m; cin >> n >> m;

        for (int i = 0; i < n; ++i) cin >> x[i];
        for (int i = 0; i < n; ++i) cin >> s[i];

        int surprise_value = -1;

        for (int mask = 0; mask < (1 << n); ++mask) {
            int sum = 0;
            fill(coeff, coeff + m, 0);
            for (int i = 0; i < n; ++i) {
                sum += (mask & (1 << i)) > 0 ? x[i] : -x[i];
                for (int j = 0; j < m; ++j) {
                    if (s[i][j] == '1') {
                        coeff[j] += (mask & (1 << i)) > 0 ? -1 : 1;
                    }
                }
            }

            iota(order, order + m, 0);
            sort(order, order + m, [&](int a, int b) {
                return coeff[a] < coeff[b];
            });

            for (int i = 0; i < m; ++i) {
                sum += coeff[order[i]] * (i + 1);
                perm[order[i]] = i + 1;
            }

            if (sum > surprise_value) {
                copy(perm, perm + m, best);
                surprise_value = sum;
            }
        }

        for (int i = 0; i < m; ++i) {
            cout << best[i] << " ";
        }
        cout << "\n";
    }
}