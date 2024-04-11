#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int a[maxn];

long long dvcq(int l, int r) {
    if (r - l == 1) return 0;
    int m = (l + r) >> 1;
    long long res = dvcq(l, m) + dvcq(m, r);
    {
        set<int> s;
        for (int i = m - 1, j = m, p = 0; i >= l; --i) {
            p = max(p, a[i]);
            while (j < r && a[j] < p) {
                s.insert(a[j]);
                ++j;
            }
            res += s.count(p - a[i]); 
        }
    }
    {
        set<int> s;
        for (int i = m, j = m - 1, p = 0; i < r; ++i) {
            p = max(p, a[i]);
            while (j >= l && a[j] < p) {
                s.insert(a[j]);
                --j;
            }
            res += s.count(p - a[i]); 
        }
    }
    return res;
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    printf("%lld\n", dvcq(0, n));
}