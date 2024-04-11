#include <bits/stdc++.h>

typedef long long ll;
const int MAX = 22;
const int moder = 998244353;
const int root = 3;
const int invroot = (moder + 1) / root;

int w[2][1 << MAX];

int powermod(int a, int exp){
    int ret = 1;
    for ( ; exp > 0; exp >>= 1){
        if (exp & 1){
            ret = 1ll * a * ret % moder;
        }
        a = 1ll * a * a % moder;
    }
    return ret;
}

void init(){
    w[0][0] = w[1][0] = 1;
    w[0][1] = powermod(root, (moder - 1) >> MAX);
    for (int i = 2; i < (1 << MAX); ++i){
        w[0][i] = 1ll * w[0][i - 1] * w[0][1] % moder;
    }
    for (int i = 1; i < (1 << MAX); ++i){
        w[1][(1 << MAX) - i] = w[0][i];
    }
}

void NTT(std::vector <int> &a, int len, int type){
    for(int i = 1, j = 0; i < len - 1; ++i){
        for(int s = len; j ^= (s >>= 1), ~j & s; )
            ;
        if(i < j){
            std::swap(a[i], a[j]);
        }
    }
    for (int i = 2, d = 1; i <= len; i <<= 1, ++d){
        for (int j = 0; j < len; j += i){
            auto u = a.begin() + j;
            for (int k = 0; k < i / 2; ++k){
                int t = 1ll * w[type][k << (MAX - d)] * u[k + i / 2] % moder;
                u[k + i / 2] = u[k] - t + (u[k] - t < 0 ? moder : 0);
                u[k] += t; u[k] -= u[k] >= moder ? moder : 0;
            }
        }
    }
    if (type == 0) return;
    int inv = powermod(len, moder - 2);
    for (int i = 0; i < len; ++i){
        a[i] = 1ll * a[i] * inv % moder;
    }
}

struct poly{
    std::vector<int> a; int len;
    poly() : len(-1) {}
    poly(int len) : len(len) { a.resize(len + 1); }
    poly(const poly &p, int len) : len(len) {
        a.resize(len + 1);
        for (int i = 0; i <= len; ++i)
            a[i] = i > p.len ? 0 : p.a[i];
    }
    int &operator [] (int n) { assert(n >= 0 && n <= len); return a[n]; }
    void setlen(int len) {
        a.resize(len + 1); this->len = len;
    }
    poly operator * (const poly &p) const {
        if (!~len || !~p.len) return poly(-1);
        int n = len + p.len, lenret = 1;
        for ( ; lenret <= n; lenret <<= 1);
        poly ret(*this, lenret);
        std::vector<int> aux(lenret);
        std::copy(p.a.begin(), p.a.begin() + p.len + 1, aux.begin());
        NTT(ret.a, lenret, 0); NTT(aux, lenret, 0);
        for (int i = 0; i < lenret; ++i)
            ret.a[i] = 1ll * ret.a[i] * aux[i] % moder;
        NTT(ret.a, lenret, 1); ret.len = n;
        return ret;
    }
};

const int N = 2000010;

int dp[N][2][2];
// 0/1: parity of root, 0/1: parity of smallest

std::vector <int> mult(std::vector <int> a, std::vector <int> b){
    int n = a.size();
    for (int i = 0; i < n; ++ i){
        a[i] = 1ll * a[i] * b[i] % moder;
    }
    NTT(a, n, 1);
    return a;
}

int main(){
    init();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 2; ++ i){
        for (int j = 0; j < 2; ++ j){
            dp[0][i][j] = 1;
        }
    }
    dp[1][0][0] = dp[1][1][1] = 1;
    const int MAX = 20;
    for (int i = 2; i <= MAX; ++ i){
        std::vector <int> vec[2][2];
        int len = 1 << i;
        for (int u = 0; u < 2; ++ u){
            for (int v = 0; v < 2; ++ v){
                vec[u][v].resize(len);
            }
        }
        for (int j = (1 << (i - 2)) - 1; j < 1 << (i - 1); ++ j){
            for (int u = 0; u < 2; ++ u){
                for (int v = 0; v < 2; ++ v){
                    vec[u][v][j] = dp[j][u][v];
                }
            }
        }
        for (int u = 0; u < 2; ++ u){
            for (int v = 0; v < 2; ++ v){
                NTT(vec[u][v], len, 0);
            }
        }
        {
            //00
            std::vector <int> res = mult(vec[1][0], vec[0][1]);
            for (int j = 1 << (i - 1); j < 1 << i; ++ j){
                dp[j][0][0] = res[j - 1];
            }
        }
        {
            //01
            std::vector <int> res = mult(vec[1][1], vec[0][1]);
            for (int j = 1 << (i - 1); j < 1 << i; ++ j){
                dp[j][0][1] = res[j - 1];
            }
        }
        {
            //10
            std::vector <int> res = mult(vec[0][0], vec[1][0]);
            for (int j = 1 << (i - 1); j < 1 << i; ++ j){
                dp[j][1][0] = res[j - 1];
            }
        }
        {
            //11
            std::vector <int> res = mult(vec[0][1], vec[1][0]);
            for (int j = 1 << (i - 1); j < 1 << i; ++ j){
                dp[j][1][1] = res[j - 1];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 2; ++ i){
        ans = (ans + dp[n][i][1]) % moder;
    }
    printf("%d\n", ans);
    return 0;
}