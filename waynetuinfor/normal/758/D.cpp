#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 60 + 10;
const long long inf = 1e18 + 1;
string s;
long long mem[maxn][maxn], n;

long long pow(long long, int);
long long dp(int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> s;
    int k = (int)s.length();
    long long ans = LLONG_MAX;
    for (int i = 0; i < k; ++i) ans = min(ans, dp(i, 0));
    cout << ans << endl;
    return 0;
}

long long pow(long long x, int n) {
    long long ret = 1LL;
    for (int i = 0; i < n; ++i) {
        ret *= x;
        if (ret >= inf) return -1;
    }
    return ret;
}

long long dp(int k, int p) {
    // cout << "dping(" << k << ", " << p << ")" << endl;
    if (p == s.length()) {
        // cout << "dp terminate when k = " << k << " and p = " << p << endl;
        return 0;
    }
    if (k < 0) return inf;
    mem[k][p] = inf;
    // cout << "----------------" << endl;
    if (s[p] == '0') {
        mem[k][p] = min(mem[k][p], dp(k - 1, p + 1));
        return mem[k][p];
    } 
    for (int i = p; i < s.length(); ++i) {
        // if (i + 1 < s.length() && s[i + 1] == '0') continue;
        string t = s.substr(p, i - p + 1);
        // cout << "t = " << t << endl;
        stringstream ss(t);
        long long tmp; ss >> tmp; 
        long long mul = pow(n, k);
        // if (mul != -1 && tmp >= mul) continue;
        if (tmp >= n) continue;
        // cout << "tmp = " << tmp << "  mul = " << mul << endl;
        if (mul != -1 && log10(tmp) + log10(mul) <= 18) mem[k][p] = min(mem[k][p], tmp * mul + dp(k - 1, i + 1));
    }
    // cout << "----------------" << endl; 
    // cout << "dp(" << k << ", " << p << ") = " << mem[k][p] << endl;
    return mem[k][p];
}