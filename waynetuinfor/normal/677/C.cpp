#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, mod = 1e9 + 7;

int conv(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
    if (c >= 'a' && c <= 'z') return c - 'a' + 36;
    if (c == '-') return 62;
    if (c == '_') return 63;
}

int c[100][100];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    c[0][0] = 1;
    for (int i = 1; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            c[i][j] = c[i - 1][j];
            if (j) c[i][j] = (c[i][j] + c[i - 1][j - 1]) % mod;
        }
    }
    int n = (int)s.size();
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) vec[i] = conv(s[i]);
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        int now = vec[i];
        int a = 6;
        for (int j = 0; j < 6; ++j) if ((1 << j) & vec[i]) --a;
        int b = 0;
        for (int j = 0; j <= a; ++j) {
            b += c[a][j] * 1ll * (1 << (a - j)) % mod;
            b %= mod;
            // b -= c[a][j];
            b += mod;
            b %= mod;
        }
        ans = ans * 1ll * b % mod;
    }
    cout << ans << endl;
    return 0;
}