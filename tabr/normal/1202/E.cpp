#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

vector<int> kmp(string s, string w) {
    int n = (int)s.size(), m = (int)w.size();
    vector<int> p(m);
    int k = 0;
    for (int i = 1; i < m; i++) {
        while (k > 0 && w[i] != w[k]) {
            k = p[k - 1];
        }
        if (w[i] == w[k]) {
            k++;
        }
        p[i] = k;
    }
    vector<int> res;
    k = 0;
    for (int i = 0; i < n; i++) {
        while (k > 0 && (k == m || s[i] != w[k])) {
            k = p[k - 1];
        }
        if (s[i] == w[k]) {
            k++;
        }
        if (k == m) {
            res.push_back(i - m + 1);
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string t;
    cin >> t;
    int n;
    cin >> n;
    int len = t.size();
    vector<ll> a(len), b(len + 1);
    const int mn = 400;
    vector<vector<int>> trie(1, vector<int>(26, -1));
    vector<int> cnt(1);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int k = s.size();
        if (s.size() > 400) {
            vector<int> x = kmp(t, s);
            for (int j : x) {
                a[j]++;
                b[j + k]++;
            }
        } else {
            int pos = 0;
            for (int j = 0; j < k; j++) {
                if (trie[pos][s[j] - 'a'] == -1) {
                    pos = trie[pos][s[j] - 'a'] = trie.size();
                    trie.emplace_back(vector<int>(26, -1));
                    cnt.emplace_back(0);
                } else {
                    pos = trie[pos][s[j] - 'a'];
                }
            }
            cnt[pos]++;
        }
    }
    for (int i = 0; i < len; i++) {
        int pos = 0;
        for (int j = 0; j < 400 && i + j < len; j++) {
            pos = trie[pos][t[i + j] - 'a'];
            if (pos == -1) {
                break;
            }
            a[i] += cnt[pos];
            b[i + j + 1] += cnt[pos];
        }
    }
    ll ans = 0;
    for (int i = 0; i < len; i++) {
        ans += a[i] * b[i];
    }
    cout << ans << '\n';
    return 0;
}