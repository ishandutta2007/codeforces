#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 10;
string s[maxn];
bool t[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int k, n; cin >> k >> n;
    bool b = true;
    int g = -1;
    for (int i = 0; i < k; ++i) {
        vector<int> c(26, 0);
        cin >> s[i];
        for (int j = 0; j < n; ++j) ++c[s[i][j] - 'a'];
        for (int j = 0; j < 26; ++j) if (c[j] > 1) t[i] = true;
        if (s[i] != s[0]) b = false, g = i;
    }
    if (b) {
        swap(s[0][1], s[0][0]);
        cout << s[0] << endl;
        return 0;
    }
    vector<pair<int, int>> act;
    for (int i = 0; i < 1; ++i) {
        vector<int> diff;
        for (int j = 0; j < n; ++j) {
            if (s[i][j] != s[g][j]) diff.push_back(j);
        }
        if (diff.size() > 10) return cout << "-1" << endl, 0;
        string a = s[i], b = s[g];
        for (int j = 0; j < diff.size(); ++j) {
            for (int k = j + 1; k < diff.size(); ++k) {
                swap(a[diff[j]], a[diff[k]]);
                int pos = -1;
                bool ok = true;
                int c = 0;
                for (int p = 0; p < n && ok; ++p) {
                    if (a[p] != b[p]) {
                        ++c;
                        if (pos == -1) { pos = p; continue; }
                        if (b[p] != a[pos]) ok = false;
                    }
                }
                ok &= (c == 2 || c == 0 && t[i + 1]);
                if (ok) act.emplace_back(diff[j], diff[k]);
                swap(a[diff[j]], a[diff[k]]);
            }
        }
    }
    if (t[0]) act.emplace_back(0, 0);
    for (auto i : act) {
        // cout << i.first << ' ' << i.second << endl;
        string a = s[0];
        bool ans = true;
        swap(a[i.first], a[i.second]);
        for (int j = 1; j < k; ++j) {
            int pos = -1, diff = 0; bool ok = true;
            for (int p = 0; p < n && ok; ++p) {
                if (a[p] != s[j][p]) {
                    ++diff;
                    if (pos == -1) { pos = p; continue; }
                    if (s[j][p] != a[pos]) ok = false;
                }
            }
            ok &= (diff == 2 || diff == 0 && t[j] || s[j] == s[0]);
            if (!ok) { ans = false; break; }
        }
        if (ans) return cout << a << endl, 0;
    }
    cout << "-1" << endl;
    return 0;
}