#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int l[maxn], r[maxn], ans[maxn];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d%d", &l[i], &r[i]);
        vector<int> v(n);
        iota(v.begin(), v.end(), 0);
        sort(v.begin(), v.end(), [&](int i, int j) { return r[i] < r[j]; });
        vector<int> w(n);
        iota(w.begin(), w.end(), 0);
        sort(w.begin(), w.end(), [&](int i, int j) { return l[i] < l[j]; });
        int cr = 0, j = 0;
        bool f = false;
        for (int i = 0; i < n; ++i) {
            cr = max(cr, r[v[i]]);
            while (j < n && l[w[j]] <= r[v[i]]) {
                cr = max(cr, r[w[j]]);
                ++j;
            }
            if (cr == r[v[i]] && j < n) {
                for (int k = 0; k < j; ++k) ans[w[k]] = 1;
                for (int k = j; k < n; ++k) ans[w[k]] = 2;
                f = true;
                break;
            }
        }
        if (!f) {
            puts("-1");
        } else {
            for (int i = 0; i < n; ++i) printf("%d ", ans[i]);
            puts("");
        }
    }
}