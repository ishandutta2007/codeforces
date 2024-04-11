#include <bits/stdc++.h>
using namespace std;

const int maxn = 50 + 5;
string s[maxn];
map<string, int> m[maxn];

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < n; ++i) {
        m[i][s[i]] = 0;
        for (int j = 0; j < s[i].length() - 1; ++j) {
            string t = s[i].substr(1, s[i].length() - 1);
            t += s[i][0];
            if (m[i].find(t) != m[i].end()) m[i][t] = min(m[i][t], j + 1);
            else m[i][t] = j + 1;
            s[i] = t;
        }
    }
    bool ans = false;
    int Min = INT_MAX;
    for (auto str : m[0]) {
        string ss = str.first;
        bool osas = true;
        int tot = str.second;
        for (int i = 1; i < n; ++i) {
            if (m[i].find(ss) == m[i].end()) osas = false;
            else tot += m[i][ss];
        }
        if (osas) Min = min(Min, tot), ans = true;
    }
    if (!ans) cout << "-1\n";
    else cout << Min << '\n';
    return 0;
}