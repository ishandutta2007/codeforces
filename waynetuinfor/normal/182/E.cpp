#include <bits/stdc++.h>
using namespace std;

const int maxn = 200 + 10, maxl = 3000 + 10, mod = 1e9 + 7;
int dp[maxn][maxl], a[maxn], b[maxn], id[maxn], n, l;
bool v[maxn][maxl];

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }

int go(int now, int len) {
    if (v[now][len]) return dp[now][len];
    for (int i = 1; i <= n; ++i) if (id[i] != id[now]) {
        if (a[now] == b[i] && len - b[now] >= 0) dp[now][len] = add(dp[now][len], go(i, len - b[now]));
    }
    v[now][len] = true;
    return dp[now][len];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> l;
    for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
    int ptr = 0;
    for (int i = 1; i <= n; ++i) id[i] = i;
    for (int i = 1; i <= n; ++i) {
        if (a[i] != b[i]) {
            ++ptr;
            a[n + ptr] = b[i]; b[n + ptr] = a[i]; id[n + ptr] = id[i];
        }
    }
    n += ptr;
    for (int i = 1; i <= n; ++i) ++dp[i][b[i]], v[i][b[i]] = true;
    int ans = 0;
    for (int i = 1; i <= n; ++i) ans = add(ans, go(i, l));
    cout << ans << endl;
    return 0;
}