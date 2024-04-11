#include <iostream>
#include <vector>
#define int long long

using namespace std;

const int N = 2007, M = 998244353;
int fact[N], obr[N], pref0[N];
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
    fact[0] = 1;
    obr[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % M;
        obr[i] = get_obr(fact[i]);
    }
    pref0[0] = 1;
    for (int i = 1; i < N; i++) {
        pref0[i] = (pref0[i - 1] * (k - 2)) % M;
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
    init(k);
    //cout << fact[2] << ' ' << obr[2] << ' ' << fact[0] << ' ' << obr[0] << endl;
    //cout << (fact[2] * obr[2]) % M << endl;
    //cout << cnk(2, 2) << endl;
    for (int i = 0; i < n; i++) cin >> a[i];
    int ca = 0, cb = 0;
    int ans = 0, mul = 1;
    for (int i = 0; i < n; i++) {
        int nxt = (i + 1) % n;
        if (a[i] == a[nxt]) cb++;
        else ca++;
    }
    for (int i = 0; i < cb; i++) mul = (mul * k) % M;
    for (int fi = 1; fi <= ca; fi++) {
        for (int se = 0; se < fi && fi + se <= ca; se++) {
            //cout << fi << ' ' << se << ' ' << ca << ' ' << cnk(ca, fi) << ' ' << cnk(ca - fi, se) << endl;
            int cur = (cnk(ca, fi) * cnk(ca - fi, se)) % M;
            cur = (cur * pref0[ca - fi - se]) % M;
            ans = (ans + cur) % M;
        }
    }
    ans = (ans * mul) % M;
    cout << ans << endl;
    return 0;
}