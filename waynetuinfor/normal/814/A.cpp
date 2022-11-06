#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
int a[maxn], b[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < k; ++i) cin >> b[i];
    if (k > 1) return cout << "YES\n", 0;
    for (int i = 0; i < n; ++i) if (a[i] == 0) a[i] = b[0];
    for (int i = 0; i < n - 1; ++i) {
        if (a[i + 1] < a[i]) return cout << "YES\n", 0;
    }
    cout << "NO\n";
    return 0;
}