#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
int a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int Min = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        if (i == m) continue;
        if (!a[i]) continue;
        if (a[i] > k) continue;
        Min = min(Min, abs(i - m) * 10);
    }
    cout << Min << '\n';
    return 0;
}