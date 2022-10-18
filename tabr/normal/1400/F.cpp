#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    int x;
    cin >> s >> x;
    vector<string> p;
    function<void(string)> f = [&](string t) {
        int a = 0;
        for (char c : t) {
            a += c - '0';
        }
        if (a > x) {
            return;
        }
        if (a == x) {
            bool ok = true;
            for (int i = 0; i < t.size(); i++) {
                int b = 0;
                for (int j = i; j < t.size(); j++) {
                    b += t[j] - '0';
                    if (b != x && x % b == 0) {
                        ok = false;
                    }
                }
            }
            if (ok) {
                p.emplace_back(t);
            }
            return;
        }
        if (a != 0 && x % a == 0) {
            return;
        }
        for (char c = '1'; c <= '9'; c++) {
            f(t + c);
        }
    };
    f("");
    vector<vector<int>> trie(1, vector<int>(10, -1));
    vector<int> pv(1, -1);
    string node = " ";
    auto add = [&](string t) {
        int pos = 0;
        for (int i = 0; i < (int)t.size(); i++) {
            if (trie[pos][t[i] - '0'] == -1) {
                pv.emplace_back(pos);
                pos = trie[pos][t[i] - '0'] = (int)trie.size();
                trie.emplace_back(vector<int>(10, -1));
                node.push_back(t[i]);
            } else {
                pos = trie[pos][t[i] - '0'];
            }
        }
    };
    for (string t : p) {
        add(t);
    }
    int sz = trie.size();
    vector<vector<int>> ntrie = trie;
    for (int i = 0; i < sz; i++) {
        if (trie[i] == vector<int>(10, -1)) {
            continue;
        }
        string t;
        int tp = i;
        while (tp) {
            t.push_back(node[tp]);
            tp = pv[tp];
        }
        reverse(t.begin(), t.end());
        for (int j = 1; j < 10; j++) {
            if (trie[i][j] == -1) {
                string w = t;
                w.push_back('0' + j);
                while (true) {
                    if (w.empty()) {
                        ntrie[i][j] = 0;
                        break;
                    }
                    int pos = 0;
                    for (char c : w) {
                        int to = c - '0';
                        pos = trie[pos][to];
                        if (pos == -1) {
                            break;
                        }
                    }
                    if (pos != -1) {
                        ntrie[i][j] = pos;
                        break;
                    }
                    w.erase(w.begin());
                }
            }
        }
    }
    swap(trie, ntrie);
    vector<int> dp(sz, -1e9);
    dp[0] = 0;
    debug(trie);
    for (char c : s) {
        vector<int> ndp = dp;
        int to = c - '0';
        for (int i = 0; i < sz; i++) {
            if (trie[i][to] != -1) {
                ndp[trie[i][to]] = max(ndp[trie[i][to]], dp[i] + 1);
            }
        }
        swap(dp, ndp);
    }
    for (int i = 0; i < sz; i++) {
        if (trie[i] == vector<int>(10, -1)) {
            dp[i] = -1e9;
        }
    }
    cout << s.size() - *max_element(dp.begin(), dp.end()) << '\n';
    return 0;
}