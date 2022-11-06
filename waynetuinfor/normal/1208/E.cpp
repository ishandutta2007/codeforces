#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
long long sum[maxn], tag[maxn];
vector<int> a[maxn];

int main() {
    int n, w; scanf("%d%d", &n, &w);
    for (int i = 0; i < n; ++i) {
        int l; scanf("%d", &l);
        a[i].resize(l);
        for (int j = 0; j < l; ++j) scanf("%d", &a[i][j]);
        int x = max(*max_element(a[i].begin(), a[i].end()), 0);
        if (2 * l <= w) {
            for (int j = 0, z = 0; j < l; ++j) {
                z = max(z, a[i][j]);
                sum[j] += z;
            }
            for (int j = w - 1, p = l - 1, z = 0; p >= 0; --p, --j) {
                z = max(z, a[i][p]);
                sum[j] += z;
            }
            tag[l] += x;
            tag[w - l] -= x;
        } else {
            multiset<int> ms;
            for (int j = 0, k = 0; j < w; ++j) {
                if (j < l) ms.insert(a[i][j]);
                int z = *ms.rbegin();
                if (j < w - l || j >= l) z = max(z, 0);
                sum[j] += z;
                if (j - k == w - l) {
                    ms.erase(ms.find(a[i][k]));
                    ++k;
                }
            }
        }
    }
    long long s = 0;
    for (int i = 0; i < w; ++i) {
        s += tag[i];
        printf("%lld ", sum[i] + s);
    }
    puts("");
    return 0;
}