#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
int p[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= k; ++i) cin >> p[i];
    int ans = 0;
    while (n--) {
        for (int j = 0; j < m; ++j) {
            int x, pos; cin >> x;
            for (int i = 1; i <= k; ++i) {
                if (p[i] == x) { pos = i; break; }
            }
            ans += pos;
            for (int i = pos; i > 1; --i) p[i] = p[i - 1];
            p[1] = x;
        }
    }
    cout << ans << endl;
    return 0;
}