#include<bits/stdc++.h>

typedef unsigned long long ll;
const int N = 100010;
const ll moder = (1ll << 58) - 1;

ll inv(ll a, ll moder){
    ll b = moder, s = 1, t = 0;
    while (b){
        ll tmp = a, q = a / b;
        a = b, b = tmp % a;
        tmp = s;
        s = t;
        t = tmp - s * q;
    }
    if (a > 1) return -1;
    return s < 0 ? s + moder : s;
}

struct poly{
    static const int N = 5;
    ll a[N];

    poly(){memset(a, 0, sizeof(a));}

    ll &operator [](int sit){return a[sit];}

    poly operator +(const poly &p)const{
        poly ret;
        for (int i = 0; i < N; ++ i){
            ret[i] = a[i] + p.a[i];
        }
        return ret;
    }

    poly operator *(const poly &p)const{
        poly ret;
        for (int i = 0; i < N; ++ i){
            for (int j = 0; j < N; ++ j){
                ll x = a[i] * p.a[j];
                int sit = i + j;
                if (sit >= N){
                    sit -= N;
                    x = -x;
                }
                ret[sit] += x;
            }
        }
        return ret;
    }

    poly powermod(int exp)const{
        poly a = *this, ret;
        ret[0] = 1;
        for ( ; exp > 0; exp >>= 1){
            if (exp & 1){
                ret = ret * a;
            }
            a = a * a;
        }
        return ret;
    }
};

poly root[N];

std::vector <poly*> vec[N];

void FFT(std::vector <poly*> a, int type){
    int n = a.size();
    std::vector <poly> vec(n);
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            vec[i] = vec[i] + root[type == 1 ? i * j : 10 - i * j % 10] * *a[j];
        }
    }
    for (int i = 0; i < n; ++ i){
        *a[i] = vec[i];
    }
}

void multiFFT(std::vector <poly> &a, std::vector <int> len, int type){
    int dim = len.size(), n = a.size();
    std::vector <int> pre(dim + 1, 1);
    for (int i = 0; i < dim; ++ i){
        pre[i + 1] = pre[i] * len[i];
    }
    for (int i = 0; i < dim; ++ i){
        for (int j = 0; j < N; ++ j){
            vec[j].clear();
        }
        for (int j = 0; j < n; ++ j){
            vec[j % pre[i] + j / pre[i + 1] * pre[i]].push_back(&a[j]);
        }
        for (int j = 0, sz = n / len[i]; j < sz; ++ j){
            FFT(vec[j], type);
        }
    }
    if (type == -1){
        ll inv5 = inv(3125, 1ll << 58);
        for (auto &u : a){
            for (int i = 0; i < 5; ++ i){
                u[i] >>= 5;
                u[i] *= inv5;
            }
        }
    }
}

int main(){
    root[0][0] = root[1][1] = 1;
    for (int i = 2; i < N; ++ i){
        root[i] = root[i - 1] * root[1];
    }
    int n;
    scanf("%d", &n);
    std::vector <poly> vec(100000);
    for (int i = 0, x; i < n; ++ i){
        scanf("%d", &x);
        ++ vec[x][0];
    }
    std::vector <int> len(5, 10);
    multiFFT(vec, len, 1);
    for (auto &u : vec){
        u = u.powermod(n);
    }
    multiFFT(vec, len, -1);
    for (int _ = 0; _ < n; ++ _){
        poly u = vec[_];
        for (int i = 0; i < 4; ++ i){
            u[i] += u[4] * (i & 1 ? 1 : -1);
        }
        printf("%llu\n", u[0] & moder);
    }
    return 0;
}