#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e6 + 10, hasht = 5;
int mod[7] = { 479001599, 433494437, 1073807359, 1442968193, 715827883, 1442968193, 715827883  };
int hs[hasht][maxn], pw[hasht][maxn];
string s;
int n;

inline int add(int a, int b, int j) { return a + b >= mod[j] ? a + b - mod[j] : a + b; }
inline int sub(int a, int b, int j) { return a - b < 0 ? a - b + mod[j] : a - b; }
inline int mul(int a, int b, int j) { return a * 1ll * b % mod[j]; }

bool check(int a, int b, int c, int sd) {
    if (a > 1 && s[0] == '0' || b > 1 && s[a] == '0' || c > 1 && s[a + b] == '0') return false;
    int ha = hs[sd][a - 1];
    int hb = sub(hs[sd][a + b - 1], mul(hs[sd][a - 1], pw[sd][b], sd), sd);
    int hc = sub(hs[sd][n - 1], mul(hs[sd][a + b - 1], pw[sd][c], sd), sd);
    return add(ha, hb, sd) == hc;
}

void solve(int a, int b, int c) {
    if (min(a, min(b, c)) < 1) return;
    for (int i = 0; i < hasht; ++i) if (!check(a, b, c, i)) return;
    cout << s.substr(0, a) << '+' << s.substr(a, b) << '=' << s.substr(a + b, c) << endl;
    exit(0);
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    srand(time(nullptr));
    random_shuffle(mod, mod + 7);
    cin >> s; n = s.size();
    for (int j = 0; j < hasht; ++j) {
        pw[j][0] = 1;
        for (int i = 1; i < n; ++i) pw[j][i] = mul(pw[j][i - 1], 10, j);
    } 
    for (int j = 0; j < hasht; ++j) {
        hs[j][0] = s[0] - '0';
        for (int i = 1; i < n; ++i) hs[j][i] = add(mul(hs[j][i - 1], 10, j), s[i] - '0', j);
    }
    for (int len = 1; len <= n; ++len) {
        solve(len, n - len - len, len);
        solve(len, n - len - len - 1, len + 1);
        solve(n - len - len, len, len);
        solve(n - len - len - 1, len, len + 1);
    }
}