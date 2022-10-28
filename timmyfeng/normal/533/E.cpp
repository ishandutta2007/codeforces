#include <bits/stdc++.h>
using namespace std;

const int N = 100001;

int prefix[N], suffix[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s, t;
    cin >> n >> s >> t;

    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + (s[i] == t[prefix[i]]);
    }

    for (int i = n - 1; i >= 0; --i) {
        suffix[i] = suffix[i + 1] + (s[i] == t[n - 1 - suffix[i + 1]]);
    }

    int ways = 0;
    char prv = '#';
    for (int i = 0; i <= n; ++i) {
        if (prefix[i] + suffix[i] == n - 1) {
            ways += prv != t[prefix[i]] || (i > 0 && prv != s[i - 1]);
            prv = t[prefix[i]];
        } else {
            prv = '#';
        }
    }

    cout << ways << "\n";
}