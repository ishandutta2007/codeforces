#include <bits/stdc++.h>

const int MAX = 20;
const double PI = std::acos(-1.0);

struct comp{
    double real, imag;

    explicit comp(double real = 0, double imag = 0):real(real), imag(imag){}

    comp operator +(const comp &c)const{return comp(real + c.real, imag + c.imag);}
    comp operator -(const comp &c)const{return comp(real - c.real, imag - c.imag);}
    comp operator *(const comp &c)const{return comp(real * c.real - imag * c.imag, real * c.imag + imag * c.real);}
    comp operator *(const double &c)const{return comp(real * c, imag * c);}
};

comp w[2][1 << MAX];

void init(){
    for (int i = 0; i < 1 << MAX; ++i){
        double angle = 1.0 * i / (1 << (MAX - 1)) * PI;
        for (int type = -1; type <= 1; type += 2)
            w[!~type][i] = comp(cos(angle), type * sin(angle));
    }
}

void FFT(std::vector <comp> &a, int len, int type){
    for (int i = 1, j = 0; i < len - 1; ++i){
        for (int s = len; j ^= s >>= 1, ~j & s; ) ;
        if (i < j) std::swap(a[i], a[j]);
    }
    for (int i = 2, d = 1; i <= len; i <<= 1, ++d)
        for (int j = 0; j < len; j += i){
            auto u = a.begin() + j;
            for (int k = 0; k < i / 2; ++k){
                comp s = u[k];
                comp t = w[type][k << (MAX - d)] * u[k + i / 2];
                u[k] = s + t, u[k + i / 2] = s - t;
            }
        }
    if (type == 0) return; double inv = 1.0 / len;
    for (int i = 0; i < len; ++i) a[i] = a[i] * inv;
}

const int LEN = 1 << 18;
using ll = long long;

ll ans[LEN], tmp[LEN];

void solve(const std::vector<int> &a, const std::vector<int> &b, int coe, int dir){
    std::vector<comp> a1(LEN), a2(LEN);
    for (auto u : a){
        a1[u].real += 1;
    }
    for (auto u : b){
        a2[u].real += 1;
    }
    FFT(a1, LEN, 0);
    FFT(a2, LEN, 0);
    for (int i = 0; i < LEN; ++ i){
        a1[i] = a1[i] * a2[i];
    }
    FFT(a1, LEN, 1);
    memset(tmp, 0, sizeof(tmp));
    if (dir == 0){
        for (int i = 1; i < LEN; ++ i){
            tmp[i] = tmp[i - 1] + ll(std::round(a1[i - 1].real));
        }
    }
    else{
        for (int i = LEN - 2; i >= 0; -- i){
            tmp[i] = tmp[i + 1] + ll(std::round(a1[i].real));
        }
    }
    for (int i = 0; i < LEN; ++ i){
        ans[i] += coe * tmp[i];
    }
}

int main(){
    init();
    int n, m;
    int test;
    scanf("%d%d%d", &n, &m, &test);
    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; ++ i){
        scanf("%d", &b[i]);
    }
    solve(a, b, 1, 1);
    solve(a, b, -1, 0);
    std::vector<int> mina(n - 1), minb(m - 1);
    for (int i = 0; i < n - 1; ++ i){
        mina[i] = std::min(a[i], a[i + 1]);
    }
    for (int i = 0; i < m - 1; ++ i){
        minb[i] = std::min(b[i], b[i + 1]);
    }
    solve(mina, b, -1, 1);
    solve(a, minb, -1, 1);
    std::vector<int> maxa(n - 1), maxb(m - 1);
    for (int i = 0; i < n - 1; ++ i){
        maxa[i] = std::max(a[i], a[i + 1]);
    }
    for (int i = 0; i < m - 1; ++ i){
        maxb[i] = std::max(b[i], b[i + 1]);
    }
    solve(maxa, b, 1, 0);
    solve(a, maxb, 1, 0);
    solve(mina, minb, 1, 1);
    solve(maxa, maxb, -1, 0);
    while (test --){
        int x;
        scanf("%d", &x);
        printf("%lld\n", ans[x]);
    }
    return 0;
}