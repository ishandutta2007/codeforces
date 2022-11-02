#include <iostream>

using namespace std;
using ll = long long;

const ll MOD = 998244353;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int a[n + 2];
    a[0] = a[n + 1] = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    ll ok[201], ng[201];
    fill(ok, ok + 201, 0);
    fill(ng, ng + 201, 1);

    for (int i = 1; i <= n; ++i) {
        ll nok[201], nng[201];
        fill(nok, nok + 201, 0);
        fill(nng, nng + 201, 0);

        for (int v = 1; v <= 200; ++v) {
            if (a[i] > 0 && a[i] != v) continue;

            // 
            nng[v] += ok[v - 1] + ng[v - 1];
            nng[v] %= MOD;

            // 
            nok[v] += ok[200] - ok[v] + MOD;
            nok[v] %= MOD;

            // 
            nok[v] += ok[v] - ok[v - 1] + ng[v] - ng[v - 1] + MOD * 2;
            nok[v] %= MOD;
        }

        ok[0] = ng[0] = 0;
        for (int v = 1; v <= 200; ++v) {
            ok[v] = (ok[v - 1] + nok[v]) % MOD;
            ng[v] = (ng[v - 1] + nng[v]) % MOD;
        }
    }

    cout << ok[200] << endl;
    return 0;
}