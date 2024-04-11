// 1172B
// possibili posizioni di un tree con nodi su una circonferenza

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, res, check1, a, b, mod, fct[200010], degr[200010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    mod = 998244353;

    cin >> n;
    for (i = 0; i < n - 1; i++) {
        cin >> a >> b;
        degr[a]++;
        degr[b]++;
    }

    fct[0] = 1;
    for (i = 1; i <= n; i++) {
        fct[i] = (fct[i - 1] * i) % mod;
    }

    res = n;
    for (i = 1; i <= n; i++) {
        res = (res * fct[degr[i]]) % mod;
    }

    cout << res;

    return 0;
}