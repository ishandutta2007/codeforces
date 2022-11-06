#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 5e6 + 10;
int f[maxn];

void sieve() {
    bitset<maxn> v;
    for (int i = 2; i < maxn; ++i) if (!v[i]) {
        f[i] = 1;
        for (int j = i + i; j < maxn; j += i) {
            v[j] = true;
            f[j] = f[j / i] + 1;
        }
    }
    for (int i = 1; i < maxn; ++i) f[i] += f[i - 1];
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    sieve();
    int t; cin >> t; while (t--) {
        int a, b; cin >> a >> b;
        cout << f[a] - f[b] << '\n';
    }
    return 0;
}