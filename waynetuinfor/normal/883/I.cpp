#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10, inf = 1e9 + 1;
int a[maxn], n, k;

bool check(int now) {
    vector<int> s(maxn, 0);
    for (int i = 0; i < k; ++i) s[i] = 1;
    int ptr = 1;
    for (int i = k; i <= n; ++i) {
        while (ptr <= i - k + 1 && a[i] - a[ptr] > now) ++ptr;
        // cout << "ptr = " << ptr << endl;
        int lb = ptr - 1, rb = i - k;
        s[i] = s[i - 1];
        if (lb == 0) {
            s[i]++;
            continue;
        }
        if (s[rb] - s[lb - 1]) ++s[i];
    }
    return s[n] - s[n - 1];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    int d = 1, ans = inf; while (d < inf) d <<= 1;
    while (d >>= 1) if (ans - d >= 0) if (check(ans - d)) ans -= d;
    cout << ans << endl;
    return 0;
}