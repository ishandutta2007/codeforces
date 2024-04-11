#include <bits/stdc++.h>
#define int long long

using namespace std;

const int M = 998244353, N = 3e5 + 7;
int a[N];
int fact[N];

int bpow(int x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x % M;
    if (n % 2 == 0) {
        int mem = bpow(x, n / 2);
        return (mem * mem) % M;
    }
    return (bpow(x, n - 1) * x) % M;
}

int obr(int x) {
    return bpow(x, M - 2); 
}

void init() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % M;
    }
}

signed main() {
    init();
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < 2 * n; i++) cin >> a[i];
    sort(a, a + 2 * n);
    int up = fact[2 * n];
    int dwn = (obr(fact[n]) * obr(fact[n])) % M;
    int cnt = (up * dwn) % M;
    int sm = 0;
    for (int i = 0; i < n; i++) sm -= a[i];
    for (int i = n; i < 2 * n; i++) sm += a[i];
    sm %= M;
    int res = (sm * cnt) % M;
    cout << res << endl;
    return 0;
}