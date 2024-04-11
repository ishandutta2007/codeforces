#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
int k[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        k[a] -= c; k[b] += c;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) if (k[i] > 0) ans += k[i];
    cout << ans << endl;
    return 0;
}