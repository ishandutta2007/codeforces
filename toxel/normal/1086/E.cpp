#include<bits/stdc++.h>

typedef long long ll;
const int MAX = 20;
const int moder = 998244353;
const int root = 3;
const int invroot = (moder + 1) / root;
const int N = 2010;
const int SMAX = 1 << 11;

int w[2][1 << MAX];
int fac[N << 1], inv[N << 1], invf[N << 1];
int coe[N][N];
int a[N][N], seg1[SMAX << 1], seg2[SMAX << 1];
int power[N];
bool set1[N], set2[N], set[N];

void add(int *seg, int sit, int value){
    seg[sit += SMAX] = value;
    for (sit >>= 1; sit; sit >>= 1){
        seg[sit] = seg[sit << 1] + seg[sit << 1 | 1];
    }
}

int query(int *seg, int l, int r){
    int ret = 0;
    for (l += SMAX, r += SMAX + 1; l < r; l >>= 1, r >>= 1){
        if (l & 1) ret += seg[l ++];
        if (r & 1) ret += seg[-- r];
    }
    return ret;
}

int comb(int n, int m){
    return 1ll * fac[n] * invf[m] % moder * invf[n - m] % moder;
}

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
    fac[0] = invf[0] = 1;
    for (int i = 1; i < N << 1; ++ i){
        fac[i] = 1ll * fac[i - 1] * i % moder;
        inv[i] = i == 1 ? 1 : moder - 1ll * (moder / i) * inv[moder % i] % moder;
        invf[i] = 1ll * invf[i - 1] * inv[i] % moder;
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
    std::vector<int> a;
    int len;
    
    poly() : len(-1) {}
    poly(int len) : len(len) { a.resize(len + 1); }
    poly(const poly &p, int len) : len(len) { 
        a.resize(len + 1); 
        for (int i = 0; i <= len; ++i) {
            a[i] = i > p.len ? 0 : p.a[i];
        }
    }
    
    int &operator [] (int n) { assert(n >= 0 && n <= len); return a[n]; }
    
    poly operator * (const poly &p) const {
        if (!~len || !~p.len) return poly(-1);
        int n = len + p.len;
        int lenret = 1;
        for ( ; lenret <= n; lenret <<= 1)
            ;
        poly ret(*this, lenret);
        std::vector<int> aux(lenret);
        std::copy(p.a.begin(), p.a.begin() + p.len + 1, aux.begin());
        NTT(ret.a, lenret, 0);
        NTT(aux, lenret, 0);
        for (int i = 0; i < lenret; ++i) {
            ret.a[i] = 1ll * ret.a[i] * aux[i] % moder;
        }
        NTT(ret.a, lenret, 1);
        ret.len = n;
        return ret;
    }
};

int main(){
    init();
    for (int i = 0; i < N; ++ i){
        poly p(N - 1), q(N - 1);
        for (int j = 0; j < N; ++ j){
            p[j] = (j & 1 ? -1 : 1) * invf[j];
            p[j] += p[j] < 0 ? moder : 0;
            q[j] = 1ll * fac[i + j] * invf[j] % moder;
        }
        p = p * q;
        for (int j = 0; j < N; ++ j){
            coe[j][i] = 1ll * p[j] * fac[j] % moder;
        }
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            scanf("%d", &a[i][j]);
            -- a[i][j];
        }
    }
    power[0] = 1;
    power[1] = coe[n][0];
    for (int i = 2; i < N; ++ i){
        power[i] = 1ll * power[1] * power[i - 1] % moder;
    }
    int ans = 0;
    for (int i = 0; i < n; ++ i){
        memset(seg1, 0, sizeof(seg1));
        memset(seg2, 0, sizeof(seg2));
        for (int j = 0; j < n; ++ j){
            add(seg2, j, 1);
        }
        memset(set1, 0, sizeof(set1));
        memset(set2, 0, sizeof(set2));
        memset(set, 0, sizeof(set));
        int scnt = 0;
        for (int j = 0; j < n; ++ j){
            int up = i ? a[i - 1][j] : -1, down = a[i][j];
            if (i){
                if (set2[up]){
                    set2[up] = false;
                    set[up] = true;
                    ++ scnt;
                }
                else{
                    set1[up] = true;
                    add(seg1, up, 1);
                    add(seg2, up, 0);
                }
            }
            int zero = query(seg2, 0, down - 1), one = query(seg1, 0, down - 1);
            if (up < down && seg1[up + SMAX] == 1){
                -- one;
            }
            int x = scnt;
            int y = j + 1 - x;
            int z = n - x - 2 * y;
            ans = (ans + 1ll * zero * (i ? coe[z][y] : fac[n - j - 1]) % moder * power[n - i - 1]) % moder;
            x = scnt + 1;
            y = j + 1 - x;
            z = n - x - 2 * y;
            if (one){
                ans = (ans + 1ll * one * (i ? coe[z][y] : fac[n - j - 1]) % moder * power[n - i - 1]) % moder;
            }
            if (i){
                if (set1[down]){
                    set1[down] = false;
                    set[down] = true;
                    ++ scnt;
                }
                else{
                    set2[down] = true;
                }
            }
            add(seg1, down, 0);
            add(seg2, down, 0);
        }
    }
    printf("%d\n", ans);
    return 0;
}