#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

vector<int> kmp_table(const string &s) {
    int n = (int) s.size();
    vector<int> res(n);
    int k = 0;
    for (int i = 1; i < n; i++) {
        while (k > 0 && s[i] != s[k]) {
            k = res[k - 1];
        }
        if (s[i] == s[k]) {
            k++;
        }
        res[i] = k;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    auto p = kmp_table(s);
    int q;
    cin >> q;
    map<string, int> memo;
    while (q--) {
        string t;
        cin >> t;
        s += t;
        int k = p.back();
        string w;
        for (int i = (int) s.size() - (int) t.size(); i < (int) s.size(); i++) {
            w += s[i];
            if (memo.count(w)) {
                k = memo[w];
            } else {
                while (k > 0 && s[i] != s[k]) {
                    k = p[k - 1];
                }
                if (s[i] == s[k]) {
                    k++;
                }
                memo[w] = k;
            }
            p.emplace_back(k);
            cout << k << " \n"[i == (int) s.size() - 1];
        }
        for (int i = 0; i < (int) t.size(); i++) {
            s.pop_back();
            p.pop_back();
        }
    }
    return 0;
}