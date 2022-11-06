#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10, mod = 1e9 + 7;
int a[maxn], c[maxn][maxn];

int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
int mul(int a, int b) { return (long long)a * (long long)b % mod; }

void init() {
    c[0][0] = 1;
    for (int i = 1; i < maxn; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j) c[i][j] = add(c[i - 1][j], c[i - 1][j - 1]);
    }
}

int main() {
    init();
    ios_base::sync_with_stdio(false); cin.tie(0);
    int k; cin >> k;
    for (int i = 1; i <= k; ++i) cin >> a[i], --a[i];
    int cur = a[1], ans = 1;
    for (int i = 2; i <= k; ++i) {
        ans = mul(ans, c[cur + a[i] + 1][a[i]]);
        cur += a[i] + 1;
    }
    cout << ans << endl;
    return 0;
}