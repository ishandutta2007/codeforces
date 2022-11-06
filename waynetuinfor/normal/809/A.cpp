#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10, mod = 1e9 + 7;

int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
int mul(int a, int b) { return a * 1ll * b % mod; }

int a[maxn], p[maxn], s[maxn];

void init() {
    p[0] = 1;
    for (int i = 1; i < maxn; ++i) p[i] = mul(p[i - 1], 2);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    init();
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i) s[i] = add(s[i - 1], a[i]);
    int ans = 0;
    for (int i = 1; i <= n / 2; ++i) {
        int l = i, r = n - i + 1;
        int sum = sub(sub(s[n], s[r - 1]), sub(s[l], s[0]));
        ans = add(ans, mul(add(p[i - 1], p[n - i - 1]), sum));
    }
    if (n % 2 == 0) {
        int sum = sub(sub(s[n], s[n / 2]), sub(s[n / 2], s[0]));
        ans = sub(ans, mul(p[n / 2 - 1], sum));
    }
    cout << ans << endl;
    return 0;
}