#include <bits/stdc++.h>
#define int long long

using namespace std;

const int M = 998244353, N = 5e5 + 7;
int fact[N], fact2[N];

int bpow(int a, int n) {
    if (n == 0) return 1;
    if (n == 1) return (a % M);
    if (n % 2 == 0) {
        int mem = bpow(a, n / 2);
        return (mem * mem) % M;
    }
    return (bpow(a, n - 1) * a) % M;
}

int rev(int x) {
    return bpow(x, M - 2);
}

void init() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % M;
    }
    fact2[N - 1] = rev(fact[N - 1]);
    for (int i = N - 2; i >= 0; i--) {
        fact2[i] = (fact2[i + 1] * (i + 1)) % M;
    }
}

int cnk(int n, int k) {
    if (k > n) return 0;
    int res = (((fact[n] * fact2[k]) % M) * fact2[n - k]) % M;
    return res;
}

signed main() {
    init();
    //freopen("Desktop/input.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = n / i - 1;
        res = (res + cnk(cnt, k - 1)) % M;
    }
    cout << res << endl;
    return 0;
}