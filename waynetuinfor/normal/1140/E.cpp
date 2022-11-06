#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
const int mod = 998244353;
int a[maxn], dp[maxn][2][2];
int sum[maxn * 4], add[maxn * 4], mul[maxn * 4];

void init() {
    for (int i = 0; i < maxn * 4; ++i) {
        mul[i] = 1;
        add[i] = 0;
        sum[i] = 0;
    }
}

void push(int o, int l, int r) {
    int m = (l + r) >> 1;
    sum[o * 2 + 1] = (sum[o * 2 + 1] * 1ll * mul[o] + (m - l) * 1ll * add[o]) % mod;
    sum[o * 2 + 2] = (sum[o * 2 + 2] * 1ll * mul[o] + (r - m) * 1ll * add[o]) % mod;
    mul[o * 2 + 1] = mul[o * 2 + 1] * 1ll * mul[o] % mod;
    mul[o * 2 + 2] = mul[o * 2 + 2] * 1ll * mul[o] % mod;
    add[o * 2 + 1] = add[o * 2 + 1] * 1ll * mul[o] % mod;
    add[o * 2 + 2] = add[o * 2 + 2] * 1ll * mul[o] % mod;
    (add[o * 2 + 1] += add[o]) %= mod;
    (add[o * 2 + 2] += add[o]) %= mod;
    mul[o] = 1;
    add[o] = 0;
}

void addition(int l, int r, int ql, int qr, int v, int o = 0) {
    if (l >= qr || ql >= r) return;
    if (l >= ql && r <= qr) {
        sum[o] += (r - l) * 1ll * v % mod;
        sum[o] %= mod;
        (add[o] += v) %= mod;
        return;
    }
    push(o, l, r);
    addition(l, (l + r) >> 1, ql, qr, v, o * 2 + 1);
    addition((l + r) >> 1, r, ql, qr, v, o * 2 + 2);
    sum[o] = (sum[o * 2 + 1] + sum[o * 2 + 2]) % mod;
}

void multiply(int l, int r, int ql, int qr, int v, int o = 0) {
    if (l >= qr || ql >= r) return;
    if (l >= ql && r <= qr) {
        sum[o] = sum[o] * 1ll * v % mod;
        mul[o] = mul[o] * 1ll * v % mod;
        add[o] = add[o] * 1ll * v % mod;
        return;
    }
    push(o, l, r);
    multiply(l, (l + r) >> 1, ql, qr, v, o * 2 + 1);
    multiply((l + r) >> 1, r, ql, qr, v, o * 2 + 2);
    sum[o] = (sum[o * 2 + 1] + sum[o * 2 + 2]) % mod;
}

int query(int l, int r, int ql, int qr, int o = 0) {
    if (l >= qr || ql >= r) return 0;
    if (l >= ql && r <= qr) return sum[o];
    push(o, l, r);
    return (query(l, (l + r) >> 1, ql, qr, o * 2 + 1) + 
            query((l + r) >> 1, r, ql, qr, o * 2 + 2)) % mod;
}

int main() {
    int n, k; scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 3; i <= n; ++i) {
        if (a[i] != -1 && a[i] == a[i - 2]) {
            puts("0");
            return 0;
        }
    }
    vector<int> odd, even;
    for (int i = 1; i <= n; ++i) {
        if (i & 1) odd.push_back(a[i]);
        else even.push_back(a[i]);
    }
    function<int(vector<int>)> solve = [&](vector<int> v) {
        init();
        addition(0, k + 1, 0, 1, 1);
        for (int i = 0; i < (int)v.size(); ++i) {
            int sum = query(0, k + 1, 0, k + 1);
            multiply(0, k + 1, 0, 1, 0);
            if (v[i] == -1) {
                multiply(0, k + 1, 1, k + 1, mod - 1);
                addition(0, k + 1, 1, k + 1, sum);
            } else {
                multiply(0, k + 1, 1, v[i], 0);
                multiply(0, k + 1, v[i] + 1, k + 1, 0);
                multiply(0, k + 1, v[i], v[i] + 1, mod - 1);
                addition(0, k + 1, v[i], v[i] + 1, sum);
            }
        }
        return query(0, k + 1, 1, k + 1);
    };
    printf("%d\n", 1ll * solve(odd) * solve(even) % mod);
}