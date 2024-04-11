#include <bits/stdc++.h>
using namespace std;

const int N = 200001;

int prefix[N][3][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    string s;
    cin >> n >> m >> s;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                prefix[i + 1][j][k] = prefix[i][j][k] + (s[i] - 'a' != j && i % 3 == k);
            }
        }
    }

    while (m--) {
        int l, r;
        cin >> l >> r;

        int ans = INT_MAX;
        vector<int> perm = {0, 1, 2};
        do {
            int cost = 0;
            for (int i = 0; i < 3; ++i) {
                cost += prefix[r][perm[i]][i] - prefix[l - 1][perm[i]][i];
            }
            ans = min(ans, cost);
        } while (next_permutation(perm.begin(), perm.end()));

        cout << ans << "\n";
    }
}