#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 10;

string shift(const string &s, int x) {
    string ret = "";
    for (int i = s.size() - 1, j = 0; j < x; --i, ++j) ret += s[i];
    for (int i = 0; i < s.size() - x; ++i) ret += s[i];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    string s, t; cin >> s >> t;
    vector<int> sc(26), tc(26);
    for (int i = 0; i < n; ++i) ++sc[s[i] - 'a'];
    for (int i = 0; i < n; ++i) ++tc[t[i] - 'a'];
    for (int i = 0; i < 26; ++i) if (sc[i] != tc[i]) return cout << "-1" << endl, 0;
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        int pos = -1;
        for (int j = 0; j < s.size() - i; ++j) {
            if (s[j] == t[i]) {
                pos = j;
                break;
            }
        }
        ans.push_back(n - 1 - pos);
        ans.push_back(1);
        ans.push_back(n);
        s = shift(shift(shift(s, n - 1 - pos), 1), n);
    }
    assert(s == t);
    cout << ans.size() << endl;
    for (int i : ans) cout << i << ' '; cout << endl;
}