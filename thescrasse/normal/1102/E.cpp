// 1102E
// sequenza b[i] con a[i] = a[j] => b[i] = b[j], 0 <= b[i + 1] - b[i] <= 1

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, res, check1, a[200010], b, f[200010], mod, p;
bool r[200010];
map<long long, long long> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    k = 0;
    for (i = 0; i < n; i++) {
        if (s[a[i]] == 0) {
            s[a[i]] = k + 1;
            a[i] = k;
            k++;
        } else {
            a[i] = s[a[i]] - 1;
        }
    }
    k1 = k;

    for (i = 0; i < n; i++) {
        f[i] = 1000010;
    }
    for (i = 0; i < n - 1; i++) {
        if (a[i + 1] < a[i]) {
            f[a[i]] = min(f[a[i]], a[i + 1]);
        }
    }

    k = 1000010;
    p = 1000010;
    for (i = n - 1; i >= 0; i--) {
        k = min(k, i);
        p = min({p, i, f[i]});
        if (k > p) {
            for (j = k; j > p; j--) {
                r[j] = true;
            }
        }
        k = min(k, p);
    }

    mod = 998244353;
    res = 1;
    for (i = 1; i < k1; i++) {
        if (r[i] == false) {
            res = (2 * res) % mod;
        }
    }

    cout << res;

    return 0;
}