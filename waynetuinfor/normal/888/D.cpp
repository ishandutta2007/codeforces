#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10;
long long c[5], f[5];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    c[0] = 1; c[1] = n; f[1] = 1; f[0] = 1;
    for (int i = 2; i < 5; ++i) c[i] = c[i - 1] * (n - i + 1) / (i), f[i] = f[i - 1] * 1ll * i;
    long long ans = 0;
    for (int i = n - k; i <= n; ++i) {
        int p = n - i;
        long long now = c[p];
        long long q = 0;
        long long coef = 1;
        vector<long long> tc(5); tc[0] = 1, tc[1] = p;
        for (int j = 2; j < 5; ++j) tc[j] = tc[j - 1] * (p - j + 1) / (j);
        for (int j = p; j >= 0; --j) {
            q += coef * tc[p - j] * f[j];
            coef *= -1;
        } 
        ans += now * q;
    } 
    cout << ans << endl;
    return 0;
}