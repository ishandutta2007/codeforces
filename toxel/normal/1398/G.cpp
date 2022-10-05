#include <bits/stdc++.h>

const double PI = acos(-1.0);
inline double sqr(double n){return n * n;}
const int MAX = 20;
typedef long long ll;

struct comp{
    double real, imag;

    comp(double real = 0, double imag = 0):real(real), imag(imag){}

    comp operator +(const comp &c)const{
        return comp(real + c.real, imag + c.imag);
    }

    comp operator -(const comp &c)const{
        return comp(real - c.real, imag - c.imag);
    }

    comp operator *(const comp &c)const{
        return comp(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }

    comp operator *(const double &c)const{
        return comp(real * c, imag * c);
    }

    comp conj()const{
        return comp(real, -imag);
    }

    comp operator /(const comp &c)const{
        return *this * c.conj() * (1 / (sqr(c.real) + sqr(c.imag)));
    }
};

comp w[2][1 << MAX];

void init(){
    for (int i = 0; i < 1 << MAX; ++i){
        double angle = 1.0 * i / (1 << (MAX - 1)) * PI;
        for (int type = -1; type <= 1; type += 2){
            w[!~type][i] = comp(std::cos(angle), type * std::sin(angle));
        }
    }
}

void FFT(comp *a, int len, int type){
    for (int i = 1, j = 0; i < len - 1; ++i){
        for (int s = len; j ^= s >>= 1, ~j & s; )
            ;
        if (i < j){
            std::swap(a[i], a[j]);
        }
    }
    for (int i = 2, d = 1; i <= len; i <<= 1, ++d){
        for (int j = 0; j < len; j += i){
            auto u = a + j;
            for (int k = 0; k < i / 2; ++k){
                comp s = u[k], t = w[type][k << (MAX - d)] * u[k + i / 2];
                u[k] = s + t, u[k + i / 2] = s - t;
            }
        }
    }
    if (type == 0) return;
    double inv = 1.0 / len;
    for (int i = 0; i < len; ++i){
        a[i] = a[i] * inv;
    }
}

const int N = 1 << 19;

int a[N];
comp a1[N], a2[N];
bool vis[N];
std::vector<int> fact[N];

int main(){
    init();
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    for (int i = 0; i <= n; ++ i){
        scanf("%d", &a[i]);
        a1[a[i]] = {1, 0};
        a2[x - a[i]] = {1, 0};
    }
    FFT(a1, N, 0);
    FFT(a2, N, 0);
    for (int i = 0; i < N; ++ i){
        a1[i] = a1[i] * a2[i];
    }
    FFT(a1, N, 1);
    for (int i = x + 1; i <= 2 * x; ++ i){
        int value = std::round(a1[i].real);
        if (value){
            vis[i - x + y] = true;
        }
    }
    for (int i = N - 1; i >= 1; -- i){
        for (int j = i; j < N; j += i){
            fact[j].emplace_back(i);
        }
    }
    int test;
    scanf("%d", &test);
    while (test --){
        int l;
        scanf("%d", &l);
        l /= 2;
        int ans = -1;
        for (auto u : fact[l]){
            if (vis[u]){
                ans = u * 2;
                break;
            }
        }
        printf("%d%c", ans, " \n"[test == 0]);
    }
    return 0;
}