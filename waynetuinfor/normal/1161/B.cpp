#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
vector<int> seg[maxn];
int cnt[maxn];

vector<int> kmp(const vector<int> &s) {
    vector<int> f(s.size(), 0);
    // f[i] = length of the longest prefix (excluding s[0:i]) such that it coincides with the suffix of s[0:i] of the same length
    // i + 1 - f[i] is the length of the smallest recurring period of s[0:i]
    int k = 0;
    for (int i = 1; i < (int)s.size(); ++i) {
        while (k > 0 && s[i] != s[k]) k = f[k - 1];
        if (s[i] == s[k]) ++k;
        f[i] = k;
    }
    return f;
}

vector<int> search(const vector<int> &s, const vector<int> &t) {
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

vector<int> calc(const vector<int> &v) {
    vector<int> w(v.begin(), v.end());
    for (int i = 0; i < (int)v.size(); ++i)
        w.push_back(v[i]);

    vector<int> mt = search(w, v);
    vector<int> res;
    for (int i = 0; i < (int)mt.size(); ++i) {
        if (mt[i] > 0 && mt[i] < (int)v.size())
            res.push_back(mt[i]);
    }
    return res;
}

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int a, b; scanf("%d%d", &a, &b);
        --a, --b;
        if ((a - b + n) % n > (b - a + n) % n)
            swap(a, b);
        
        int d = (a - b + n) % n;
        seg[d].push_back(a);
        if ((b - a + n) % n == d)
            seg[d].push_back(b);
    }

    int t = 0;
    for (int i = 1; i <= n; ++i) {
        if (seg[i].empty()) continue;
        if ((int)seg[i].size() == 1) {
            puts("No");
            return 0;
        }

        sort(seg[i].begin(), seg[i].end());
        seg[i].resize(unique(seg[i].begin(), seg[i].end()) - seg[i].begin());
        vector<int> diff;
        int m = (int)seg[i].size();
        for (int j = 0; j < m; ++j)
            diff.push_back((seg[i][(j + 1) % m] - seg[i][j] + n) % n);

        vector<int> cyc = calc(diff);
        for (int j = 0; j < (int)cyc.size(); ++j) {
            int dist = (seg[i][cyc[j]] - seg[i][0] + n) % n;
            ++cnt[dist];
        }
        ++t;
    }

    for (int i = 1; i < n; ++i) {
        if (cnt[i] == t) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}