#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005, MOD = 1000000007;

int fac[N], inv[N];

int inverse(int a) {
    return a == 1 ? 1 : (long long)(MOD - MOD / a) * inverse(MOD % a) % MOD;
}

int cb(int n, int m) {
    return (long long)fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}

int p[N];

vector<int> ps;

int ans;

void solve(int i, int n, int f, int sign) {
    if (f > n) {
        return;
    }
    if (i == (int)ps.size()) {
        (ans += sign * cb(n - 1, f - 1)) %= MOD;
        return;
    }
    solve(i + 1, n, f, sign);
    solve(i + 1, n / ps[i], f, -sign);
}

int main() {
    fac[0] = 1, inv[0] = 1;
    for (int i = 1; i < N; ++i) {
        fac[i] = (long long)fac[i - 1] * i % MOD;
        inv[i] = inverse(fac[i]);
    }
    p[1] = 1;
    for (int i = 2; i < N; ++i) {
        if (p[i] == 0) {
            p[i] = i;
            for (long long j = (long long)i * i; j < N; j += i) {
                p[j] = i;
            }
        }
    }
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, f;
        scanf("%d%d", &n, &f);
        ps.clear();
        int a = n;
        while (a != 1) {
            ps.push_back(p[a]);
            while (a % ps.back() == 0) {
                a /= ps.back();
            }
        }
        ans = 0;
        solve(0, n, f, 1);
        if (ans < 0) {
            ans += MOD;
        }
        printf("%d\n", ans);
    }
    return 0;
}