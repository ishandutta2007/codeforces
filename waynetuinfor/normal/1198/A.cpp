#include <bits/stdc++.h>
using namespace std;

const int maxn = 4e5 + 5;
int a[maxn], cnt[maxn], lg[maxn];

int main() {
    int n, p; scanf("%d%d", &n, &p); 
    p <<= 3;

    vector<int> d;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        d.push_back(a[i]);
    }

    sort(d.begin(), d.end());
    d.resize(unique(d.begin(), d.end()) - d.begin());

    for (int i = 0; i < n; ++i)
        a[i] = lower_bound(d.begin(), d.end(), a[i]) - d.begin();

    sort(a, a + n);

    int kind = 0;
    lg[1] = 0;
    for (int i = 1; (1 << i) < maxn; ++i) {
        for (int j = (1 << i); j > (1 << (i - 1)); --j) lg[j] = i;
    }
    

    auto inc = [&](int x) {
        if (cnt[x] == 0) ++kind;
        ++cnt[x];
    };

    auto dec = [&](int x) {
        --cnt[x];
        if (cnt[x] == 0) --kind;
    };

    int ans = n;

    for (int i = 0, j = 0; i < n; ++i) {
        while (j < n) {
            inc(a[j]);
            if (n * lg[kind] <= p) ++j;
            else {
                dec(a[j]);
                break;
            }
        }
        ans = min(ans, i + n - j);
        dec(a[i]);
    }
    printf("%d\n", ans);
}