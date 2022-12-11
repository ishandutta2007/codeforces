#include <iostream>
#include <vector>
#define int long long

using namespace std;

const int N = 2e5 + 7, M = 998244353;
int fact[N], obr[N], pref0[N], poww[N];
int a[N];

int bin_pow(int a, int n) {
    if (n == 0) return 1;
    if (n == 1) return a % M;
    if (n % 2 == 0) {
        int mem = bin_pow(a, n / 2);
        return (mem * mem) % M;
    }
    return (a * bin_pow(a, n - 1)) % M;
}

int get_obr(int x) {
    return bin_pow(x, M - 2);
}

void init(int k) {
    fact[0] = obr[0] = pref0[0] = poww[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % M;
        obr[i] = get_obr(fact[i]);
        pref0[i] = (pref0[i - 1] * (k - 2)) % M;
        poww[i] = (poww[i - 1] * 2) % M;
    }
}

int cnk(int n, int k) {
    return (((fact[n] * obr[k]) % M) * obr[n - k]) % M;
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    init(k);
    int ca = 0, cb = 0;
    int ans = 0, mul = 1;
    for (int i = 0; i < n; i++) {
        int nxt = (i + 1) % n;
        if (a[i] == a[nxt]) cb++;
        else ca++;
    }
    for (int i = 0; i < cb; i++) mul = (mul * k) % M;
    for (int rest = 0; rest < ca; rest++) {
        int cur = (pref0[rest] * cnk(ca, rest)) % M;
        int s = ca - rest;
        int left = poww[s];
        if (s % 2 == 0) {
            left = (left - cnk(s, s / 2)) % M;
            if (left < 0) left += M;
        }
        left = (left * obr[2]) % M;
        cur = (cur * left) % M;
        ans = (ans + cur) % M;
    }
    ans = (ans * mul) % M;
    cout << ans << endl;
    return 0;
}