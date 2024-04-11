#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

#define X first
#define Y second


const int MOD = 1e9 + 7;
const int N = 3e5 + 10;

ll fac[N], rev[N], revfac[N];

ll C(int n, int m) {
    if (m < 0 || m > n) return 0;
    return fac[n] * revfac[m] % MOD * revfac[n - m] % MOD;
}
ll candy(int n, int m) {
    if (n == 0) return m == 0;
    return C(n + m - 1, n - 1);
}
void modified(int &c00, int &c01, int &c10, int &c11, int u, int v) {
    //cout << "kis" << u << " " << v << '\n';
    if (u == 0 && v == 0) c00--;
    if (u == 0 && v == 1) c01--;
    if (u == 1 && v == 0) c10--;
    if (u == 1 && v == 1) c11--;
}
ll calculate(int c00, int c01, int c10, int c11, int head) {
    if (c00 < 0 || c01 < 0 || c10 < 0 || c11 < 0) return 0;
    if (head == 0) {
        swap(c00, c11);
        swap(c01, c10);
    }
    //cout << "ask " << c00 << " " << c01 << " " << c10 << " " << c11 << " " << head << '\n';
    int k = c10;
    int L = c10 + c01 + 1;
    //cout << L << " "  << k << '\n';
    if (c01 == k || c01 == k - 1) {
        return candy((L + 1) / 2, c11) * candy(L / 2, c00) % MOD;
    }
    return 0;
}
bool check(string s, int c00, int c01, int c10, int c11) {
    for(int i = 1; i < s.length(); i++) 
        modified(c00, c01, c10, c11, s[i - 1] - '0', s[i] - '0');
    return (c00 == 0 && c01 == 0 && c10 == 0 && c11 == 0);
}
ll solve(string s, int c00, int c01, int c10, int c11) {
    int L = c00 + c01 + c10 + c11 + 1;
    int n = s.length();
    if (n < L) return 0;
    if (n > L) {
        return solve(string(L, '1'), c00, c01, c10, c11) 
            + check(string(L, '1'), c00, c01, c10, c11);
    }
    ll ans = 0;
    for(int i = 1; i < L; i++) {
        if (s[i] == '1') {
            int nc00 = c00;
            int nc01 = c01;
            int nc10 = c10;
            int nc11 = c11;
            modified(nc00, nc01, nc10, nc11, s[i - 1] - '0', 0);
            ans = (ans + calculate(nc00, nc01, nc10, nc11, 0)) % MOD;
        }
        modified(c00, c01, c10, c11, s[i - 1] - '0', s[i] - '0');
    }
    return ans;
}

int main() {
    fac[0] = 1;
    for(int i = 1; i < N; i++) fac[i] = fac[i - 1] * i % MOD;
    rev[1] = 1;
    for(int i = 2; i < N; i++) rev[i] = MOD - (MOD / i) * rev[MOD % i] % MOD;
    revfac[0] = 1;
    for(int i = 1; i < N; i++) revfac[i] = revfac[i - 1] * rev[i] % MOD;

    string s0, s1;
    int c00, c01, c10, c11;
    cin >> s0 >> s1 >> c00 >> c01 >> c10 >> c11;

    cout << (check(s1, c00, c01, c10, c11) + 
        solve(s1, c00, c01, c10, c11) -
        solve(s0, c00, c01, c10, c11) + 1LL * MOD * MOD) % MOD;
}