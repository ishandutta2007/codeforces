#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int mod = 998244353;

namespace {
    int add(int x) {return (x >= mod) ? x - mod : x;}
    int sub(int x) {return (x < 0) ? x + mod : x;}
    void Add(int &x, int y) {x = add(x + y);}
    void Sub(int &x, int y) {x = sub(x - y);}
    int Pow(int x, int y = mod - 2) {
        int res = 1;
        for(; y; y >>= 1, x = 1LL * x * x % mod) {
            if(y  & 1)
            res= 1LL * res * x % mod;
        }
        return res;
    }
}

int n, s[N], t[N], fac[N], inv[N], All[N], S[N], m;

#define lb(x) (x & (-x))

void add(int x, int v) {
    for(int i = x; i < N; i += lb(i))
    All[i] += v;
}

int Sum(int x) {
    int res = 0;
    for(int i = x; i; i -= lb(i))
    res += All[i];
    return res;
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++ i) scanf("%d", &s[i]), ++ S[s[i]], add(s[i], 1);
    for(int i = 1; i <= m; ++ i) scanf("%d", &t[i]);
    fac[0] = 1;
    for(int i = 1; i <= n; ++ i) fac[i] = 1LL * i * fac[i - 1] % mod;
    inv[n] = Pow(fac[n]);
    for(int i = n - 1; i >= 0; -- i)
    inv[i] = 1LL * (i + 1) * inv[i + 1] % mod;
    int mx = N - 1;
    int now = 1;
    for(int i = 1; i <= mx; ++ i) {
        now = 1LL * now * inv[S[i]] % mod;
    }
    //for(int i = 1;i <= n; ++ i) cerr << s[i] << ' ';
    //cerr << endl;
    int ans = 0, tot = n;
    //cerr << 120LL * now % mod <<' ' << fac[n - 1] << endl;
    ans = 1LL * fac[n - 1] * now % mod * Sum(t[1] - 1) % mod;
    for(int i = 1; i <= min(m - 1, n); ++ i) {
        if(S[t[i]] == 0) break;
        if(i == n) {
            ++ ans; ans %= mod; continue;
        }
        -- tot;
        now = 1LL * now * (S[t[i]]) % mod;
        S[t[i]] --;
        add(t[i], -1);
        Add(ans, 1LL * fac[tot - 1] * now % mod * Sum(t[i + 1] - 1) % mod);
    }
    cout << ans << endl;
}