#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int MOD = 1e9 + 7;
int n, m;
int fac[3000010], ifac[3000010];
int ans[3000010];
int C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return 1LL * fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;
}
int quick_pow(int a, int x) {
    int ret = 1;
    while(x) {
        if (x & 1) ret = 1LL * ret * a % MOD;
        a = 1LL * a * a % MOD;
        x >>= 1;
    }
    return ret;
}

int main() {
    scanf("%d%d",&n,&m);
    fac[0] = 1;
    for (int i = 1; i <= 3 * n + 1; i++) fac[i] = 1LL * fac[i - 1] * i % MOD;
    ifac[3 * n + 1] = quick_pow(fac[3 * n + 1], MOD - 2);
    int tmp[3];
    int inv3 = quick_pow(3, MOD - 2);
    for (int i = 3 * n; i >= 0; i--) ifac[i] = 1LL * ifac[i + 1] * (i + 1) % MOD;
    tmp[0] = tmp[1] = tmp[2] = n;
    for (int i = 1; i <= 3 * n; i++) {
        int fuck = ((C(3 * n + 1, i + 1) - tmp[2] * 2LL - 1LL * tmp[1]) % MOD + MOD) % MOD;
        fuck = 1LL * fuck * inv3 % MOD;
        int ntmp1 = (fuck + tmp[2]) % MOD;
        int ntmp0 = (ntmp1 + tmp[1]) % MOD;
        tmp[0] = ntmp0;
        tmp[1] = ntmp1;
        tmp[2] = fuck;
        ans[i] = ntmp0;
    }
    while(m--) {
        int x;
        scanf("%d",&x);
        printf("%d\n",ans[x]);
    }
}