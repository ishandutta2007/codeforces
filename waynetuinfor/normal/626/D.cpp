#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 10, maxa = 5000 + 10;
int a[maxn];
double p[maxa];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    int tot = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) ++tot, ++p[a[i] - a[j]];
    }
    for (int i = 0; i < maxa; ++i) p[i] /= (double)tot;
    for (int i = 1; i < maxa; ++i) p[i] += p[i - 1];
    double ans = 0.0;
    for (int i = 0; i < maxa; ++i) {
        for (int j = 0; j < maxa; ++j) {
            if (i + j >= maxa) continue;
            ans += (i == 0 ? p[i] : p[i] - p[i - 1]) * (j == 0 ? p[j] : p[j] - p[j - 1]) * (p[maxa - 1] - p[i + j]);
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}