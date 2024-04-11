#include <bits/stdc++.h>

const int N = 500010;
const int moder = 998244353;

int fac[N], inv[N], invf[N];
int power[N];
char s[N], input[N];


int comb(int n, int m){
    if (m < 0 || n < m){
        return 0;
    }
    return 1ll * fac[n] * invf[m] % moder * invf[n - m] % moder;
}

void sub(int &u, int v){
    u -= v;
    u += u < 0 ? moder : 0;
}

void add(int &u, int v){
    u += v;
    u -= u >= moder ? moder : 0;
}

int update(int n1, int m1, int ans, int n2, int m2){
    while (n1 < n2){
        ans = (2ll * ans - comb(n1 ++, m1)) % moder;
    }
    while (n1 > n2){
        ans = 1ll * (ans + comb(-- n1, m1)) * inv[2] % moder;
    }
    ans += ans < 0 ? moder : 0;
    while (m1 < m2){
        add(ans, comb(n1, ++ m1));
    }
    while (m1 > m2){
        sub(ans, comb(n1, m1 --));
    }
    return ans;
}

struct Solver{
    int pre_n, pre_m, ans;

    Solver():pre_n(0), pre_m(0), ans(1){}

    int solve(int n, int m, int k){
        if (n < 0 || m < 0){
            return 0;
        }
        m = std::min(n, m);
        if (n == 0){
            return m % 2 == k % 2 ? 1 : 0;
        }
        m -= m % 2 != k % 2;
        -- n;
        ans = update(pre_n, pre_m, ans, n, m);
        pre_n = n;
        pre_m = m;
        return ans;
    }
};

int main(){
    fac[0] = invf[0] = 1;
    for (int i = 1; i < N; ++ i){
        fac[i] = 1ll * i * fac[i - 1] % moder;
        inv[i] = i == 1 ? 1 : moder - 1ll * (moder / i) * inv[moder % i] % moder;
        invf[i] = 1ll * inv[i] * invf[i - 1] % moder;
    }
    power[0] = 1;
    for (int i = 1; i < N; ++ i){
        power[i] = 1ll * power[i - 1] * inv[2] % moder;
    }
    Solver solver[4];
    int n, m;
    scanf("%d%d", &n, &m);
    scanf("%s", s);
    int be = 0, bo = 0, pe = 0, po = 0;
    auto calc = [&](){
        int c = be - bo - po, p = pe + po;
        int n1 = p - 1, m1 = -c - 1, k1 = (c & 1) ^ 1;
        int n2 = p, m2 = -c, k2 = c & 1;
        int n3 = p - 1, m3 = p + c - 1, k3 = (p ^ c) & 1;
        int n4 = p, m4 = p + c - 1, k4 = (p ^ c) & 1;
        int ans1 = solver[0].solve(n1, m1, k1);
        int ans2 = solver[1].solve(n2, m2, k2);
        int ans3 = solver[2].solve(n3, m3, k3);
        int ans4 = solver[3].solve(n4, m4, k4);
        int ans = (-1ll * ans1 * p - 1ll * ans2 * c + 1ll * ans3 * p + 1ll * ans4 * c) % moder;
        ans += ans < 0 ? moder : 0;
        ans = 1ll * ans * power[p] % moder;
        printf("%d\n", ans);
    };
    for (int i = 0; i < n; ++ i){
        if (i % 2 == 0){
            be += s[i] == 'b';
            pe += s[i] == '?';
        }
        else{
            bo += s[i] == 'b';
            po += s[i] == '?';
        }
    }
    calc();
    while (m --){
        int pos;
        scanf("%d%s", &pos, input);
        -- pos;
        if (pos % 2 == 0){
            be -= s[pos] == 'b';
            pe -= s[pos] == '?';
            s[pos] = input[0];
            be += s[pos] == 'b';
            pe += s[pos] == '?';
        }
        else{
            bo -= s[pos] == 'b';
            po -= s[pos] == '?';
            s[pos] = input[0];
            bo += s[pos] == 'b';
            po += s[pos] == '?';
        }
        calc();
    }
    return 0;
}