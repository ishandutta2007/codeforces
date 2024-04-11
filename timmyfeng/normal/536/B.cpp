#include <bits/stdc++.h>
using namespace std;

const int N = 2000000 + 1;
const int M = 1000000007;

int match[N], pi[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    string pattern;
    cin >> n >> m >> pattern;

    for (int i = 0; i < m; ++i) {
        cin >> match[i];
        --match[i];
    }

    long long ways = 1;
    string ans;

    for (int i = 0, j = -1; i < n; ++i) {
        j += j < m - 1 && match[j + 1] == i;
        if (j >= 0 && i - match[j] < (int) pattern.size()) {
            ans += pattern[i - match[j]];
        } else {
            ways = ways * 26 % M;
            ans += '?';
        }
    }

    ans = pattern + '#' + ans;
    for (int i = 1; i < (int) ans.size(); ++i) {
        int j = pi[i - 1];
        while (j > 0 && ans[j] != ans[i]) {
            j = pi[j - 1];
        }
        pi[i] = j + (ans[j] == ans[i]);
    }

    for (int i = 0; i < m; ++i) {
        if (pi[match[i] + 2 * pattern.size()] != (int) pattern.size()) {
            cout << 0 << "\n";
            exit(0);
        }
    }

    cout << ways << "\n";
}