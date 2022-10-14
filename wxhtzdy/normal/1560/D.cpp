#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int calc(string s, string t) {
    int n = s.size();
    int m = t.size();

    int nxt = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (nxt < m && s[i] == t[nxt]) {
            nxt++;
        } else ans++;
    }

    return m - nxt + ans;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    vector<string> all;
    for (int i = 0; i < 60; i++) {
        long long x = (1LL << i);

        string cur = "";
        while (x > 0) {
            cur += (char) ('0' + x % 10);
            x /= 10;
        }

        reverse(cur.begin(), cur.end());

        all.push_back(cur);
        //cout << cur << endl;
    }

    int tt;
    cin >> tt;

    while (tt--) {
        string s;
        cin >> s;

        int mn = 1e9;
        for (auto& t : all) {
            mn = min(mn, calc(s, t));
        }

        cout << mn << '\n';
    }
}