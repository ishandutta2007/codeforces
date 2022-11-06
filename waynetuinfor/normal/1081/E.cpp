#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

const int maxn = 2e5 + 5;
int a[maxn];
long long ans[maxn];
vector<pair<long long, long long>> cand[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n / 2; ++i) scanf("%d", &a[i]);
    for (int i = 1; i < maxn; ++i) {
        for (int j = 1; j * j <= i; ++j) {
            if (i % j) continue;
            int x = j, y = i / j;
            if ((x + y) & 1) continue;
            cand[i].emplace_back((x + y) / 2 - j, (x + y) / 2);
        }
        sort(cand[i].begin(), cand[i].end());
    }
    long long j = 1;
    long long sum = 0;
    for (int i = 0; i < n / 2; ++i) {
        int p = lower_bound(cand[a[i]].begin(), cand[a[i]].end(), make_pair(j, 0ll)) - cand[a[i]].begin();
        if (p == (int)cand[a[i]].size()) {
            puts("No");
            return 0;
        }
        ans[i * 2] = cand[a[i]][p].first * 1ll * cand[a[i]][p].first - sum;
        ans[i * 2 + 1] = a[i];
        sum += ans[i * 2] + ans[i * 2 + 1];
        j = cand[a[i]][p].second;
    }
    puts("Yes");
    for (int i = 0; i < n; ++i) printf("%lld ", ans[i]);
    puts("");
    return 0;
}