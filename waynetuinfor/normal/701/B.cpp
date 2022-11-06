#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
bool r[maxn], c[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    int nr = 0, nc = 0;
    long long ans = n * 1ll * n;
    while (m--) {
        int a, b; cin >> a >> b;
        if (!r[a]) r[a] = true, ans -= n - nc, ++nr;
        if (!c[b]) c[b] = true, ans -= n - nr, ++nc;
        cout << ans << ' ';
    }
    cout << endl;
    return 0;
}