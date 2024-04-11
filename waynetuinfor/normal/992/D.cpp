#include <bits/stdc++.h>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")

using namespace std;

const int maxn = 2e5 + 5;
const long long inf = 2e18 + 5;
int a[maxn];
long long s[maxn];
vector<int> cc[maxn];

int main() {
    int n, k; scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), s[i] = s[i - 1] + a[i];
    vector<long long> ds;
    for (int i = 0; i <= n; ++i) ds.push_back(s[i]);
    sort(ds.begin(), ds.end()), ds.resize(unique(ds.begin(), ds.end()) - ds.begin());
    for (int i = 0; i <= n; ++i) {
        int x = lower_bound(ds.begin(), ds.end(), s[i]) - ds.begin();
        cc[x].push_back(i);
    }
    vector<int> ps;
    for (int i = 1; i <= n; ++i) if (a[i] != 1) ps.push_back(i);
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 1 && k == 1) ++ans;
        int x = upper_bound(ps.begin(), ps.end(), i) - ps.begin() - 1;
        if (x == -1) continue;
        long long p = 1;
        for (int j = x; j >= 0; --j) {
            int y = ps[j];
            if (p > inf / a[y]) break;
            p *= a[y];
            if (p % k == 0) {
                long long tg = p / k;
                int prv = j == 0 ? 0 : ps[j - 1];
                int q = lower_bound(ds.begin(), ds.end(), s[i] - tg) - ds.begin();
                if (q == ds.size() || ds[q] != s[i] - tg) continue;
                int g = lower_bound(cc[q].begin(), cc[q].end(), prv) - cc[q].begin();
                if (g != cc[q].size() && cc[q][g] < y) ++ans;
            }
        }
    }
    printf("%lld\n", ans);
}