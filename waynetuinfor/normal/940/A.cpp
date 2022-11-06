#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
int a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, d; cin >> n >> d;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    int ans = maxn + 1;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (a[j] - a[i] <= d) ans = min(ans, i + (n - j - 1));
        }
    }
    cout << ans << endl;
    return 0;
}