#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

bool check(string res, string ord, string s) {
    string t = res;

    vector<bool> rem(26);
    for (int i = 0; i < ord.size(); i++) {
        rem[ord[i] - 'a'] = true;
        for (char c : res) {
            if (!rem[c - 'a']) t += c;
            if (t.size() > s.size()) return false;
        }
    }

    return t == s;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int tt;
    cin >> tt;

    while (tt--) {
        string s;
        cin >> s;

        int n = s.size();

        vector<bool> was(26);
        vector<int> cnt(26);
        string ord = "";
        for (int i = n - 1; i >= 0; i--) {
            if (!was[s[i] - 'a']) {
                was[s[i] - 'a'] = true;
                ord += s[i];
            }
            cnt[s[i] - 'a']++;
        }

        reverse(ord.begin(), ord.end());

        int m = 0;
        for (int i = 0; i < ord.size(); i++) {
            m += cnt[ord[i] - 'a'] / (i + 1);
        }

        string res = "";
        for (int i = 0; i < m; i++) {
            res += s[i];
        }

        if (check(res, ord, s)) {
            cout << res << " " << ord << '\n';
        } else {
            cout << -1 << '\n';
        }

    }
}