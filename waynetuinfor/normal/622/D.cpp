#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;
int a[maxn << 1];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        if (i & 1) {
            a[(i - 1) / 2 + 1] = i;
            if (!a[n - (i - 1) / 2]) a[n - (i - 1) / 2] = i;
            else a[n * 2] = i;
        } else {
            a[n + i / 2] = i;
            if (!a[2 * n - i / 2]) a[2 * n - i / 2] = i;
            else a[n * 2] = i;
        }
    }
    for (int i = 1; i <= 2 * n; ++i) cout << a[i] << ' '; cout << endl;
    return 0;
}