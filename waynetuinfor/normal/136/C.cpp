#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    if (a[n] == 1) a[n] = 2;
    else a[n] = 1;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        // if (lower_bound(a, a + n, a[i]))
        // int p = *prev(lower_bound(a, a + n, a[i]));
        // cout << max(p, 1) << ' ';
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}