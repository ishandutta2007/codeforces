#include <bits/stdc++.h>
using namespace std;

const int maxn = 3000 + 5;
string a[maxn], b[maxn], s[maxn], t[maxn];
int l[maxn], r[maxn], f[maxn];

vector<int> kmp(const string &s) {
    vector<int> f(s.size(), 0);
    int k = 0;
    for (int i = 1; i < (int)s.size(); ++i) {
        while (k > 0 && s[i] != s[k]) k = f[k - 1];
        if (s[i] == s[k]) ++k;
        f[i] = k;
    }
    return f;
}

vector<int> search(const string &s, const string &t) {
    // return 0-indexed occurrence of t in s
    vector<int> f = kmp(t), res;
    int k = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        while (k > 0 && (k == (int)t.size() || s[i] != t[k])) k = f[k - 1];
        if (s[i] == t[k]) ++k;
        if (k == (int)t.size()) res.push_back(i - t.size() + 1);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) {
        int j = 0, k = a[i].size() - 1;
        while (j < a[i].size() && a[i][j] == b[i][j]) ++j; 
        while (k >= j && a[i][k] == b[i][k]) --k;
        s[i] = a[i].substr(j, k - j + 1);
        t[i] = b[i].substr(j, k - j + 1);
        l[i] = j;
        r[i] = k;
    }
    int lng = 0, whr = -1;
    for (int i = 0; i < n; ++i) {
        if (r[i] - l[i] + 1 > lng) {
            lng = r[i] - l[i] + 1;
            whr = i;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (s[i].size() == 0) continue;
        if (s[i] != s[whr] || t[i] != t[whr]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    while (true) {
        bool br = false;
        char c = ' ';
        for (int i = 0; i < n && !br; ++i) {
            if (s[i].size() == 0) continue;
            if (l[i] == 0) {
                br = true;
                break;
            }
            if (c == ' ') c = a[i][l[i] - 1];
            else if (c != a[i][l[i] - 1]) br = true;
        }
        if (br) break;
        for (int i = 0; i < n; ++i) {
            if (s[i].size() == 0) continue;
            --l[i];
        }
    }
    while (true) {
        bool br = false;
        char c = ' ';
        for (int i = 0; i < n && !br; ++i) {
            if (s[i].size() == 0) continue;
            if (r[i] == a[i].size() - 1) {
                br = true;
                break;
            }
            if (c == ' ') c = a[i][r[i] + 1];
            else if (c != a[i][r[i] + 1]) br = true;
        }
        if (br) break;
        for (int i = 0; i < n; ++i) {
            if (s[i].size() == 0) continue;
            ++r[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        s[i] = a[i].substr(l[i], r[i] - l[i] + 1);
        t[i] = b[i].substr(l[i], r[i] - l[i] + 1);
    }
    for (int i = 0; i < n; ++i) {
        vector<int> p = search(a[i], s[whr]);
        if (p.size()) {
            for (int j = 0; j < s[whr].size(); ++j)
                a[i][j + p[0]] = t[whr][j];
        }
        if (a[i] != b[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    cout << s[whr] << endl;
    cout << t[whr] << endl;
    return 0;
}