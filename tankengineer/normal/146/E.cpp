#include<map>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, k;

map<int, int> mem;

bool islucky(int a) {
    while (a) {
        if (a % 10 != 4 && a % 10 != 7) {
            return false;
        }
        a /= 10;
    }
    return true;
}

const int MOD = 1000000007;
const int N = 100005;

int inverse(int a) {
    return a == 1 ? 1 : (long long)(MOD - MOD / a) * inverse(MOD % a) % MOD;
}

int fac[N], inv[N];

int cb(int n, int m) {
    return (long long)fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}

int f[N], tmp[N];

int main() {
    fac[0] = 1; inv[0] = 1;
    for (int i = 1; i < N; ++i) {
        fac[i] = (long long)fac[i - 1] * i % MOD;
        inv[i] = inverse(fac[i]);
    }
    scanf("%d%d", &n, &k);
    int left = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        if (islucky(a)) {
            mem[a]++;
        } else {
            left++;
        }
    }
    for (int i = 0; i <= k; ++i) {
        f[i] = cb(left, i);
    }
    for (map<int, int>::iterator it = mem.begin(); it != mem.end(); ++it) {
        int cnt = it->second;
        for (int j = k; j > 0; --j) {
            (f[j] += (long long)f[j - 1] * cnt % MOD) %= MOD;
        }
    }
    printf("%d\n", f[k]);
    return 0;
}