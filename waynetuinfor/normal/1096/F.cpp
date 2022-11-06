#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
const int mod = 998244353;
int a[maxn], rev[maxn], e[maxn], fc[maxn], fw[maxn];

int fpow(int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1) res = res * 1ll * a % mod;
        a = a * 1ll * a % mod;
        n >>= 1;
    }
    return res;
}

void add(int p, int v) {
    for (int i = p + 1; i < maxn; i += i & -i)
        fw[i] += v;
}

int query(int p) {
    int res = 0;
    for (int i = p + 1; i; i -= i & -i)
        res += fw[i];
    return res;
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] > 0) --a[i];
    }
    vector<int> pos;
    memset(rev, -1, sizeof(rev));
    for (int i = 0; i < n; ++i) {
        if (a[i] == -1) pos.push_back(i), e[i] = 1;
        else rev[a[i]] = i;
    }
    for (int i = 1; i < n; ++i) e[i] += e[i - 1];
    vector<int> sop, inq;
    for (int i = 0; i < n; ++i) {
        if (rev[i] == -1) sop.push_back(i);
        else inq.push_back(i);
    }
    assert((int)pos.size() == (int)sop.size());
    fc[0] = 1;
    for (int i = 1; i < maxn; ++i) fc[i] = fc[i - 1] * 1ll * i % mod;
    int j = 0, sum = 0, ans = 0, all = e[n - 1];
    for (int i = 0; i < (int)sop.size(); ++i) {
        while (j < (int)inq.size() && inq[j] < sop[i]) {
            sum += e[rev[inq[j]]];
            sum %= mod;
            ++j;
        }
        ans += sum * 1ll * fc[all - 1] % mod;
        ans %= mod;
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == -1) e[i] = 1;
        else e[i] = 0;
    }
    for (int i = n - 2; i >= 0; --i) e[i] += e[i + 1];
    j = (int)inq.size() - 1, sum = 0;
    for (int i = (int)sop.size() - 1; i >= 0; --i) {
        while (j >= 0 && inq[j] > sop[i]) {
            sum += e[rev[inq[j]]];
            sum %= mod;
            --j;
        }
        ans += sum * 1ll * fc[all - 1] % mod;
        ans %= mod;
    }
    int c2 = all * 1ll * (all - 1) / 2 % mod;
    for (int i = 0; i < (int)sop.size(); ++i) {
        if (all < 2) continue;
        ans += c2 * 1ll * i % mod * fc[all - 2] % mod;
        ans %= mod;
    }
    ans = ans * 1ll * fpow(fc[all], mod - 2) % mod;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == -1) continue;
        ans += query(a[i]);
        ans %= mod;
        add(a[i], 1);
    }
    printf("%d\n", ans);
    return 0;
}