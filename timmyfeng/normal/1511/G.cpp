#include <bits/stdc++.h>
using namespace std;

const int N = 200001, L = __lg(N) + 1;

int sum[L][N];
bool chip[N];

int query(int l, int r) {
    if (l > r) {
        return 0;
    } else {
        int k = __lg(r - l + 1);
        int ans = sum[k][l];
        if (chip[r + 1] ^ chip[l + (1 << k)]) {
            ans ^= 1 << k;
        }
        ans ^= query(l + (1 << k), r);
        return ans;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        chip[c] ^= true;
    }

    partial_sum(chip, chip + m + 1, chip, bit_xor<bool>());

    for (int i = 1; i <= __lg(m); ++i) {
        for (int j = 0; j + (1 << i) <= m; ++j) {
            sum[i][j] = sum[i - 1][j] ^ sum[i - 1][j + (1 << (i - 1))];
            if (chip[j + (1 << i)] ^ chip[j + (1 << (i - 1))]) {
                sum[i][j] |= 1 << (i - 1);
            }
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << "AB"[query(l - 1, r - 1) == 0];
    }

    cout << "\n";
}