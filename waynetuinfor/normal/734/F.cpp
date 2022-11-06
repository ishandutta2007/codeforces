#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10, lg = 30;
int b[maxn], c[maxn], a[maxn], bit[lg];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> b[i];
    for (int i = 1; i <= n; ++i) cin >> c[i];
    long long s2 = 0;
    for (int i = 1; i <= n; ++i) s2 += b[i] + c[i];
    if (s2 % (n * 2) != 0) return cout << "-1" << endl, 0;
    s2 /= (n * 2);
    for (int i = 1; i <= n; ++i) {
        int k = b[i] + c[i];
        if ((k - s2) % n != 0) return cout << "-1" << endl, 0;
        a[i] = (k - s2) / n;
    }
    long long s = 0;
    for (int i = 1; i <= n; ++i) s += a[i];
    if (s != s2) return cout << "-1" << endl, 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < lg; ++j) {
            if (a[i] & (1 << j)) ++bit[j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        int k = 0;
        for (int j = 0; j < lg; ++j) {
            if (a[i] & (1 << j)) k += (1 << j) * bit[j];
        }
        if (k != b[i]) return cout << "-1" << endl, 0;
        k = 0;
        for (int j = 0; j < lg; ++j) {
            if (a[i] & (1 << j)) k += (1 << j) * n;
            else k += (1 << j) * bit[j];
        }
        if (k != c[i]) return cout << "-1" << endl, 0;
    }
    for (int i = 1; i <= n; ++i) cout << a[i] << ' '; cout << endl;
    return 0;
}