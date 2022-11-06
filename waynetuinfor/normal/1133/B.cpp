#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; scanf("%d%d", &n, &k);
    vector<int> d(n), cnt(k);
    for (int i = 0; i < n; ++i) scanf("%d", &d[i]), ++cnt[d[i] % k];
    int ans = 0;
    for (int i = 0; i < k; ++i) {
        int j = (k - i) % k;
        if (i == j) {
            ans += cnt[i] / 2;
            cnt[i] = 0;
        } else {
            ans += min(cnt[i], cnt[j]);
            cnt[i] = cnt[j] = 0;
        }
    }
    printf("%d\n", 2 * ans);
}