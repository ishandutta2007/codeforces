#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

vector<int> manacher(string s) {
    string t;
    for (int i = 0; i < s.size(); i++) {
        t.push_back(s[i]);
        if (i != s.size() - 1) t.push_back('*');
    }
    s = t;
    int n = s.size(), i = 0, j = 0;
    vector<int> a(n);
    while (i < n) {
        while (0 <= i - j && i + j < n && s[i - j] == s[i + j]) j++;
        a[i] = j;
        int k = 1;
        while (0 <= i - k && i + k < n && k + a[i - k] < j) {
            a[i + k] = a[i - k];
            k++;
        }
        i += k;
        j -= k;
    }
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) a[i]++;
        a[i] /= 2;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        string a;
        int id = 0, n = s.size();
        while (s[id] == s[n - 1 - id] && id < n - 1 - id) {
            a.push_back(s[id]);
            id++;
        }
        string ans;
        string t = s.substr(id, n - 2 * id);
        vector<int> x = manacher(t);
        int pre = 0, suf = 0;
        for (int i = 0; i < x.size(); i++) {
            if (i / 2 + 1 == x[i]) {
                pre = max(pre, i + 1);
            }
        }
        reverse(x.begin(), x.end());
        for (int i = 0; i < x.size(); i++) {
            if (i / 2 + 1 == x[i]) {
                suf = max(suf, i + 1);
            }
        }
        if (pre > suf) {
            ans = s.substr(id, pre);
        } else if (suf != 0) {
            ans = s.substr(n - id - suf, suf);
        }
        cout << a << ans << string(a.rbegin(), a.rend()) << '\n';
    }
    return 0;
}