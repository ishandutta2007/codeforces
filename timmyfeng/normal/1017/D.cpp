#include <bits/stdc++.h>
using namespace std;

const int N = 12;
const int W = 1200 + 1;

int w[N], s[1 << N], pairs[1 << N][W], n;

int read() {
    string s;
    cin >> s;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            res |= 1 << i;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, q;
    cin >> n >> m >> q;

    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    for (int i = 0; i < m; ++i) {
        ++s[read()];
    }

    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < (1 << n); ++j) {
            int wu = 0;
            for (int k = 0; k < n; ++k) {
                if ((i & (1 << k)) == (j & (1 << k))) {
                    wu += w[k];
                }
            }
            pairs[i][wu] += s[j];
        }

        for (int j = 1; j < W; ++j) {
            pairs[i][j] += pairs[i][j - 1];
        }
    }

    for (int i = 0; i < q; ++i) {
        int t = read(), k;
        cin >> k;
        cout << pairs[t][k] << "\n";
    }
}