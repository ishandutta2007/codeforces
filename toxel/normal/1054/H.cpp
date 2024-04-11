#include<bits/stdc++.h>

const int moder = 490019;
const int mod1 = 491;
const int mod2 = 499;
const int root = 7;

int powermod(int a, int exp, int moder){
    int ret = 1;
    for ( ; exp > 0; exp >>= 1){
        if (exp & 1){
            ret = 1ll * ret * a % moder;
        }
        a = 1ll * a * a % moder;
    }
    return ret;
}

const double PI = std::acos(-1.0);
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
};

comp w[2][1 << MAX];
int loga1[mod1], loga2[mod2];
int crt[mod1][mod2];
int power[moder];

void init(){
    for (int i = 0; i < 1 << MAX; ++i){
        double angle = 1.0 * i / (1 << (MAX - 1)) * PI;
        for (int type = -1; type <= 1; type += 2){
            w[!~type][i] = comp(std::cos(angle), type * std::sin(angle));
        }
    }
    int power = 1, loga = 0;
    for (int i = 0; i < mod1 - 1; ++ i){
        loga1[power] = loga;
        ++ loga;
        power = root * power % mod1;
    }
    power = 1, loga = 0;
    for (int i = 0; i < mod2 - 1; ++ i){
        loga2[power] = loga;
        ++ loga;
        power = root * power % mod2;
    }
    for (int i = 0; i < mod1 * mod2; ++ i){
        crt[i % mod1][i % mod2] = i;
    }
}

void FFT(std::vector <comp> &a, int len, int type){
    for (int i = 1, j = 0; i < len - 1; ++i){
        for (int s = len; j ^= s >>= 1, ~j & s; )
            ;
        if (i < j){
            std::swap(a[i], a[j]);
        }
    }
    for (int i = 2, d = 1; i <= len; i <<= 1, ++d){
        for (int j = 0; j < len; j += i){
            auto u = a.begin() + j;
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

void FFTcomb(std::vector <comp> &a, std::vector <comp> &b){
    int n = a.size();
    FFT(a, n, 0);
    for (int i = 0; i < n; ++ i){
        b[i] = a[i ? n - i : 0].conj();
    }
    for (int i = 0; i < n; ++ i){
        comp tmp1 = (a[i] + b[i]) * comp(0.5, 0);
        comp tmp2 = (a[i] - b[i]) * comp(0, -0.5);
        a[i] = tmp1, b[i] = tmp2;
    }
}

const int N = 100010;

int a[N], b[N];

int main(){
    init();
    int n, m, c;
    scanf("%d%d%d", &n, &m, &c);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; ++ i){
        scanf("%d", &b[i]);
    }
    power[0] = 1;
    for (int i = 1; i < moder; ++ i){
        power[i] = 1ll * c * power[i - 1] % moder;
    }
    int ans = 0;
    for (int i = 0; i < n; ++ i){
        if (i % mod1 == 0 || i % mod2 == 0){
            for (int j = 0; j < m; ++ j){
                ans = (ans + 1ll * a[i] * b[j] * power[1ll * i * i * j % (moder - 1) * j * j % (moder - 1)]) % moder;
            }
        }
    }
    for (int i = 0; i < m; ++ i){
        if (i % mod1 == 0 || i % mod2 == 0){
            for (int j = 0; j < n; ++ j){
                if (j % mod1 == 0 || j % mod2 == 0) continue;
                ans = (ans + 1ll * a[j] * b[i] * power[1ll * j * j * i % (moder - 1) * i * i % (moder - 1)]) % moder;
            }
        }
    }
    std::vector <comp> p[2], q[2];
    for (int i = 0; i < 2; ++ i){
        p[i].resize(1 << MAX);
        q[i].resize(1 << MAX);
    }
    for (int i = 0; i < n; ++ i){
        if (i % mod1 == 0 || i % mod2 == 0) continue;
        int sit1 = 2 * loga1[i % mod1] % (mod1 - 1);
        int sit2 = 2 * loga2[i % mod2] % (mod2 - 1);
        auto &u = p[0][sit1 * 2 * mod2 + sit2];
        (i & 1 ? u.imag : u.real) += a[i];
    }
    FFTcomb(p[0], p[1]);
    for (int i = 0; i < m; ++ i){
        if (i % mod1 == 0 || i % mod2 == 0) continue;
        int sit1 = 3 * loga1[i % mod1] % (mod1 - 1);
        int sit2 = 3 * loga2[i % mod2] % (mod2 - 1);
        auto &u = q[0][sit1 * 2 * mod2 + sit2];
        (i & 1 ? u.imag : u.real) += b[i];
    }
    FFTcomb(q[0], q[1]);
    std::vector <comp> aux(1 << MAX);
    for (int i = 0; i < 1 << MAX; ++ i){
        aux[i] = p[0][i] * q[0][i] + p[1][i] * q[0][i] + p[0][i] * q[1][i] + comp(0, 1) * p[1][i] * q[1][i];
    }
    FFT(aux, 1 << MAX, 1);
    for (int i = 0; i < 1 << MAX; ++ i){
        int sit1 = i / (2 * mod2) % (mod1 - 1);
        int sit2 = i % (2 * mod2) % (mod2 - 1);
        int sit = crt[powermod(root, sit1, mod1)][powermod(root, sit2, mod2)];
        int value1 = (ll) std::round(aux[i].real) % moder;
        int value2 = (ll) std::round(aux[i].imag) % moder;
        sit1 = sit2 = sit;
        (sit & 1 ? sit1 : sit2) += mod1 * mod2;
        ans = (ans + 1ll * value1 * power[sit1] + 1ll * value2 * power[sit2]) % moder;
    }
    printf("%d\n", ans);
    return 0;
}