#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int l[maxn], r[maxn], a[maxn], b[maxn], s[maxn];
bool v[maxn];

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i) scanf("%d%d", &l[i], &r[i]);
    for (int i = 0; i < m; ++i) {
        --l[i], --r[i];
        v[l[i]] = true;
        v[r[i]] = true;
        if (l[i]) v[l[i] - 1] = true;
        if (r[i] + 1 < n) v[r[i] + 1] = true;
    }
    vector<int> vans(m);
    iota(vans.begin(), vans.end(), 0);
    for (int i = 0; i < m; ++i) {
        --s[l[i]];
        ++s[r[i] + 1];
    }
    for (int i = 0; i < n; ++i) b[i] = a[i];
    for (int i = 1; i < n; ++i) s[i] += s[i - 1];
    for (int i = 0; i < n; ++i) b[i] += s[i];
    int ans = *max_element(b, b + n) - *min_element(b, b + n);
    if (*max_element(a, a + n) - *min_element(a, a + n) > ans) {
        ans = *max_element(a, a + n) - *min_element(a, a + n);
        vans.clear();
    }
    for (int i = 0; i < n; ++i) {
        if (!v[i]) continue;
        for (int j = 0; j < n; ++j) b[j] = a[j];
        for (int j = 0; j < n; ++j) s[j] = 0;
        vector<int> w;
        for (int j = 0; j < m; ++j) {
            if (r[j] < i) {
                s[l[j]]--;
                s[r[j] + 1]++;
                w.push_back(j);
            } else if (l[j] > i) {
                s[l[j]]--;
                s[r[j] + 1]++;
                w.push_back(j);
            }
        }
        for (int j = 1; j < n; ++j) s[j] += s[j - 1];
        for (int j = 0; j < n; ++j) b[j] += s[j];
        int p = *max_element(b, b + n) - *min_element(b, b + n);
        if (p > ans) {
            ans = p;
            vans = w;
        }
    }
    printf("%d\n", ans);
    printf("%d\n", (int)vans.size());
    for (int i = 0; i < (int)vans.size(); ++i) 
        printf("%d ", vans[i] + 1);
    puts("");
    return 0;
}