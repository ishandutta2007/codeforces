#include <bits/stdc++.h>
using namespace std;

const int maxn = 1500 + 10;
char c[maxn], fav;
int n, q, m, em[26][maxn];

bool check(int);
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    for (int ch = 0; ch < 26; ++ch) {
        for (int i = 1; i <= n; ++i) {
            if (c[i] != (char)(ch + 'a')) em[ch][i] = em[ch][i - 1] + 1;
            else em[ch][i] = em[ch][i - 1];
        }
    }
    cin >> q;
    while (q--) {
        cin >> m >> fav;
        int d = 1, ans = 0; while (d <= n) d <<= 1;
        while (d >>= 1) if (ans + d <= n) if (check(ans + d)) ans += d;
        cout << ans << endl;
    }
    return 0;
}

bool check(int len) {
    for (int i = len; i <= n; ++i) {
        if (em[fav - 'a'][i] - em[fav - 'a'][i - len] <= m) return true;
    }
    return false;
}