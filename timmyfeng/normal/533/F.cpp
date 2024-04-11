#include <bits/stdc++.h>
using namespace std;

const int N = 400001, A = 26;

int perm[N][A], mask[N], pi[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;

    for (int i = 0; i < n; ++i) {
        fill(perm[i], perm[i] + A, -1);
    }

    int skips = 0;
    for (int i = 0; i < A; ++i) {
        if (count(t.begin(), t.end(), 'a' + i) == 0) {
            ++skips;
            continue;
        }

        for (int j = 0; j < m; ++j) {
            mask[j] = t[j] == 'a' + i;
        }
        mask[m] = -1;

        for (int j = 0; j < A; ++j) {
            for (int k = 0; k < n; ++k) {
                mask[k + m + 1] = s[k] == 'a' + j;
            }

            for (int k = 1; k < n + m + 1; ++k) {
                pi[k] = pi[k - 1];
                while (pi[k] > 0 && mask[k] != mask[pi[k]]) {
                    pi[k] = pi[pi[k] - 1];
                }
                pi[k] += mask[k] == mask[pi[k]];
            }

            for (int k = 0; k < n - m + 1; ++k) {
                if (pi[k + 2 * m] == m) {
                    perm[k][j] = i;
                }
            }
        }
    }

    vector<int> ans;
    for (int i = 0; i < n - m + 1; ++i) {
        bool ok = count(perm[i], perm[i] + A, -1) == skips;
        for (int j = 0; j < A; ++j) {
            ok &= perm[i][j] == -1 ||
                perm[i][j] == j ||
                perm[i][perm[i][j]] == j ||
                perm[i][perm[i][j]] == -1;
        }

        if (ok) {
            ans.push_back(i);
        }
    }

    cout << ans.size() << "\n";
    for (auto &i : ans) {
        cout << i + 1 << " ";
    }
    cout << "\n";
}