#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300005;
const int MOD = 998244353;

typedef pair<int, int> pii;

int nTest, n, a[MAXN], b[MAXN], fact[MAXN];
pii p[MAXN];

int calc(int n, int a[]) {
    vector<int> cnt(n+1, 0);
    for(int i = 0; i < n; ++i)
        ++cnt[a[i]];

    int ans = 1;
    for(int x = 1; x <= n; ++x)
        ans = (1LL * ans * fact[cnt[x]]) % MOD;
    return ans;
}

int calc(int n, pii p[]) {
    sort(p, p+n);
    for(int i = 1; i < n; ++i)
        if (p[i-1].second > p[i].second)
            return 0;

    map<pii, int> m;
    for(int i = 0; i < n; ++i)
        ++m[p[i]];

    int ans = 1;
    for(auto e: m)
        ans = (1LL * ans * fact[e.second]) % MOD;
    return ans;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i], &b[i]);
        p[i] = {a[i], b[i]};
    }

    fact[0] = 1;
    for(int i = 1; i <= n; ++i)
        fact[i] = (1LL * fact[i-1] * i) % MOD;

    int ans = fact[n];
    ans = (ans - calc(n, a) + MOD) % MOD;
    ans = (ans - calc(n, b) + MOD) % MOD;
    ans = (ans + calc(n, p)) % MOD;

    printf("%d", ans);

    return 0;
}