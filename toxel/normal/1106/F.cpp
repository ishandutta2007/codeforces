#include<bits/stdc++.h>
#define mp std::make_pair

const int N = 210;
const int moder = 998244353;
typedef long long ll;
typedef std::pair <int, int> pii;

template <typename T>
T inv(T a, T moder){
    T b = moder, s = 1, t = 0;
    while (b){
        T tmp = a, q = a / b;
        a = b, b = tmp % a;
        tmp = s;
        s = t;
        t = tmp - s * q;
    }
    if (a > 1) return -1;
    return s < 0 ? s + moder : s;
}

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

int BSGS(int a, int b, int moder){
    a = (a % moder + moder) % moder;
    b = (b % moder + moder) % moder;
    if (!a && !b) return 1;
    if (!a || !b) return -1;
    int now = b, x = a, m = std::sqrt(moder) + 1;
    std::vector <pii> vec;
    for (int i = 0; i < m; ++ i, now = 1ll * now * x % moder){
        vec.push_back({now, -i});
    }
    std::sort(vec.begin(), vec.end());
    x = now = powermod(a, m, moder);
    for (int i = 1; i <= m; ++ i, now = 1ll * now * x % moder){
        auto v = std::lower_bound(vec.begin(), vec.end(), mp(now, -INT_MAX));
        if (v != vec.end() && v -> first == now) return i * m + v -> second;
    }
    return -1;
}

struct poly{
    int a[N];

    poly(){memset(a, 0, sizeof(a));}

    int &operator [](const int &sit){return a[sit];}

    poly operator *(const poly &p)const{
        poly ret;
        for (int i = 0; i < N; ++ i){
            for (int j = 0; i + j < N; ++ j){
                ret[i + j] = (ret[i + j] + 1ll * a[i] * p.a[j]) % (moder - 1);
            }
        }
        return ret;
    }

    poly operator %(const poly &p)const{
        poly ret = *this;
        int len = -1;
        for (int i = N - 1; i >= 0; -- i){
            if (p.a[i]){
                len = i;
                break;
            }
        }
        for (int i = N - 1; i >= len; -- i){
            int coe = ret[i];
            for (int j = 0; j <= len; ++ j){
                int &u = ret[i - len + j];
                u = (u - 1ll * coe * p.a[j]) % (moder - 1);
                u += u < 0 ? moder - 1 : 0;
            }
        }
        return ret;
    }
};

int b[N];

int main(){
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; ++ i){
        scanf("%d", &b[i]);
    }
    std::reverse(b, b + k);
    int n, m;
    scanf("%d%d", &n, &m);
    -- n;
    poly p;
    for (int i = 0; i < k; ++ i){
        p[i] = (moder - 1 - b[i]) % (moder - 1);
    }
    p[k] = 1;
    poly q, ret;
    ret[0] = q[1] = 1;
    q = q % p;
    for ( ; n > 0; n >>= 1){
        if (n & 1){
            ret = ret * q % p;
        }
        q = q * q % p;
    }
    m = BSGS(3, m, moder);
    int x = ret[k - 1], y = moder - 1;
    int gcd = std::__gcd(x, y);
    if (m % gcd != 0){
        puts("-1");
        return 0;
    }
    x /= gcd, y /= gcd, m /= gcd;
    int Inv = inv(x, y);
    printf("%d\n", powermod(3, 1ll * Inv * m % y, moder));
    return 0;
}