#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int diff = count(s.begin(), s.end(), '0') - count(s.begin(), s.end(), '1');
    if (diff < 0) {
        reverse(s.begin(), s.end());
        for (auto &i : s) i ^= 1;
        diff = -diff;
    }

    vector<int> balance(n + 1), jump(diff + 1);
    for (int i = 0; i < n; ++i) {
        balance[i + 1] = balance[i] + (s[i] == '0' ? 1 : -1);
        if (0 <= balance[i + 1] && balance[i + 1] <= diff) {
            jump[balance[i + 1]] = (i + 1 + balance[i + 1]) / 2;
        }
    }

    int prefix = 0;
    while (prefix < n && s[prefix] == '0') ++prefix;

    int answer = 0;
    while (prefix < (n + diff) / 2) {
        prefix = jump[min(prefix, diff)];
        ++answer;
    }

    cout << answer << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}