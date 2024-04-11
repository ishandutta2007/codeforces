#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

int prefix[N], suffix[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;

    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            prefix[i] = prefix[i - 1];
        }
        if (prefix[i] < m) {
            prefix[i] += s[i] == t[prefix[i]];
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        if (i < n - 1) {
            suffix[i] = suffix[i + 1];
        }
        if (suffix[i] < m) {
            suffix[i] += s[i] == t[m - 1 - suffix[i]];
        }
    }

    int ans = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        while (j + 1 < n && prefix[i] + suffix[j + 1] >= m) {
            ++j;
        }

        if (prefix[i] > 0 && suffix[j] > 0) {
            ans = max(ans, j - i);
        }
    }

    cout << ans << "\n";
}