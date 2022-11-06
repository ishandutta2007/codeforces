#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int s[maxn], a[maxn], prv[maxn];
int n, m, k;

bool check(int l, int &ans) {
    int x = 0; ans = 0;
    while (x < n) {
        ++ans;
        int to = x + l - 1;
        if (to >= n - 1) break;
        if (s[to + 1]) {
            if (prv[to + 1] == x) return false;
            x = prv[to + 1];
            continue;
        }
        x = to + 1;
    }
    return true;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; ++i) {
        int x; scanf("%d", &x);
        s[x] = 1;
    }
    if (s[0]) {
        puts("-1");
        return 0;
    }
    s[n] = 1;
    for (int i = 1; i <= k; ++i) scanf("%d", &a[i]);
    vector<int> cand = { k };
    int p = a[k];
    for (int i = k - 1; i >= 1; --i) {
        if (p > a[i]) cand.push_back(i);
        p = min(p, a[i]);
    }
    for (int i = 0; i <= n; ++i) {
        if (s[i]) prv[i] = prv[i - 1];
        else prv[i] = i;
    }
    long long ans = 1e15;
    int x;
    for (int i : cand) {
        if (check(i, x)) ans = min(ans, x * 1ll * a[i]);
    }
    if (ans == 1e15) ans = -1;
    printf("%lld\n", ans);
    return 0;
}