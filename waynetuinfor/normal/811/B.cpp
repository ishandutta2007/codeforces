#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 10;
int p[maxn], cnt[maxn], tmp[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> p[i];
    while (m--) {
        int l, r, x; cin >> l >> r >> x;
        memset(cnt, 0, sizeof(cnt));
        for (int i = l; i <= r; ++i) ++cnt[p[i]];
        for (int i = 1; i <= n; ++i) tmp[i] = p[i];
        int ind = l;
        for (int i = 1; i <= n; ++i) while (cnt[i]--) tmp[ind++] = i;
        cout << (p[x] == tmp[x] ? "Yes\n" : "No\n");
    }
    return 0;
}