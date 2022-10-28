#include <bits/stdc++.h>
using namespace std;

const int N = 2500 + 1, K = 6 + 1;

int sum[N][N];
int n, m, k;

int rect_sum(int l, int r, int u, int d, bool rotate) {
    if (rotate) swap(l, u), swap(r, d);
    return sum[r][d] - sum[r][u] - sum[l][d] + sum[l][u];
}

int ptr_l[K], ptr_r[K];

long long solve(int l, int r, int u, int d) {
    if (r - l == 1 && d - u == 1) return rect_sum(l, r, u, d, false) == k;

    bool rotate = false;
    if (d - u > r - l) {
        swap(l, u), swap(r, d), rotate = true;
    }

    long long answer = 0;
    int m = (l + r) / 2;
    for (int row1 = u; row1 < d; ++row1) {
        fill(ptr_l, ptr_l + k + 1, l);
        fill(ptr_r, ptr_r + k + 1, r);

        for (int row2 = row1 + 1; row2 <= d; ++row2) {
            for (int i = 0; i <= k; ++i) {
                while (rect_sum(ptr_l[i], m, row1, row2, rotate) > i) ++ptr_l[i];
                while (rect_sum(m, ptr_r[i], row1, row2, rotate) > i) --ptr_r[i];
            }

            for (int i = 0; i <= k; ++i) {
                answer += ((i ? ptr_l[i - 1] : m) - ptr_l[i]) * (ptr_r[k - i] - (k - i ? ptr_r[k - i - 1] : m));
            }
        }
    }

    return answer + (rotate ? solve(u, d, l, m) + solve(u, d, m, r) : solve(l, m, u, d) + solve(m, r, u, d));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i) {
        string row; cin >> row;
        for (int j = 0; j < m; ++j) {
            sum[i + 1][j + 1] = (row[j] - '0') + sum[i][j + 1] + sum[i + 1][j] - sum[i][j];
        }
    }

    cout << solve(0, n, 0, m) << "\n";
}