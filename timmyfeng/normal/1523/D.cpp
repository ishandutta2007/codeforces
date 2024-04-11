#include <bits/stdc++.h>
using namespace std;

mt19937 rng((unsigned long long) new char);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, p; cin >> n >> m >> p;

    vector<string> s(n);
    for (auto &i : s) cin >> i;

    int answer = 0;
    string answer_bits(m, '0');

    for (int it = 0; it < 16; ++it) {
        int k = uniform_int_distribution<int>(0, n - 1)(rng);

        vector<int> bits;
        for (int i = 0; i < m; ++i) {
            if (s[k][i] == '1') bits.push_back(i);
        }
        int c = bits.size();

        vector<int> occ(1 << c);
        for (auto &i : s) {
            int mask = 0;
            for (int j = 0; j < c; ++j) {
                if (i[bits[j]] == '1') mask |= 1 << j;
            }
            ++occ[mask];
        }

        for (int i = 0; i < c; ++i) {
            for (int mask = 0; mask < (1 << c); ++mask) {
                if (mask & (1 << i)) {
                    occ[mask ^ (1 << i)] += occ[mask];
                }
            }
        }

        for (int mask = 0; mask < (1 << c); ++mask) {
            if (2 * occ[mask] >= n && __builtin_popcount(mask) > answer) {
                answer = __builtin_popcount(mask);
                answer_bits = string(m, '0');
                for (int j = 0; j < c; ++j) {
                    if (mask & (1 << j)) {
                        answer_bits[bits[j]] = '1';
                    }
                }
            }
        }
    }

    cout << answer_bits << "\n";
}