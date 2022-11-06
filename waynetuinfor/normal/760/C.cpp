#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int p[maxn], b[maxn];
bool v[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> p[i];
    int s = 0;
    for (int i = 1; i <= n; ++i) cin >> b[i], s += b[i];
    int c = 0;
    for (int i = 1; i <= n; ++i) if (!v[i]) {
        int now = i;
        while (!v[now]) {
            v[now] = true;
            now = p[now];
        }
        ++c;
    }
    int ans = 0;
    if (s & 1 ^ 1) ++ans;
    ans += (c > 1 ? c : 0);
    cout << ans << endl;
    return 0;
}