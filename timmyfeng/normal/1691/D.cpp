#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
const int L = __lg(N) + 1;

long long sums[N], max_sum[L][N], min_sum[L][N];
pair<int, int> sparse[L][N];
int a[N];

template <class T>
T query(T table[L][N], int l, int r) {
    int lg = __lg(r - l);
    return max(table[lg][l], table[lg][r - (1 << lg)]);
}

bool solve(int l, int r) {
    if (r - l <= 1) return true;
    int min_index = query(sparse, l, r).second;
    assert(l <= min_index && min_index < r);
    return sums[min_index] + query(min_sum, l, min_index + 1) <= 0 &&
        query(max_sum, min_index + 1, r + 1) - sums[min_index + 1] <= 0 &&
        solve(l, min_index) && solve(min_index + 1, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i < n; ++i) {
            sums[i + 1] = sums[i] + a[i];
        }

        for (int i = 0; i <= __lg(n + 1); ++i) {
            for (int j = 0; j + (1 << i) <= n + 1; ++j) {
                if (i == 0) {
                    sparse[i][j] = {a[j], j};
                    max_sum[i][j] = sums[j];
                    min_sum[i][j] = -sums[j];
                } else {
                    sparse[i][j] = max(sparse[i - 1][j], sparse[i - 1][j + (1 << (i - 1))]);
                    max_sum[i][j] = max(max_sum[i - 1][j], max_sum[i - 1][j + (1 << (i - 1))]);
                    min_sum[i][j] = max(min_sum[i - 1][j], min_sum[i - 1][j + (1 << (i - 1))]);
                }
            }
        }

        cout << (solve(0, n) ? "YES" : "NO") << "\n";
    }
}