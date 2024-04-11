#include<bits/stdc++.h>

const int N = 1 << 21;

int n;

struct Zzh{
    int a, b;

    Zzh():a(0), b(0){}
    Zzh(int a, int b):a(a), b(b){}

    int operator [] (const int &n)const{
        return (b >> n & 1) << 1 | a >> n & 1;
    }

    Zzh operator + (const Zzh &z)const{
        return Zzh(a ^ z.a, (a & z.a) ^ b ^ z.b);
    }

    Zzh operator - (const Zzh &z)const{
        return Zzh(a ^ z.a, (~a & z.a) ^ b ^ z.b);
    }

    Zzh operator << (const int &sit)const{
        return Zzh(a << sit & ((1 << n + 1) - 1), b << sit & ((1 << n + 1) - 1));
    }

    Zzh operator * (const Zzh &z)const{
        Zzh ret;
        for (int i = 0; i <= n; ++ i){
            for (int j = 0, sz = (*this)[i]; j < sz; ++ j){
                ret = ret + (z << i);
            }
        }
        return ret;
    }
};

char s[N + 10], t[N + 10], ans[N + 10];
Zzh a[N], b[N];

void FMT(Zzh *f, int type){
    for (int j = 0; j < n; ++ j){
        for (int i = 0; i < 1 << n; ++ i){
            if (i >> j & 1){
                if (type == 0){
                    f[i] = f[i] + f[i ^ 1 << j];
                }
                else{
                    f[i] = f[i] - f[i ^ 1 << j];
                }
            }
        }
    }
}

void solve(){
    for (int i = 0; i < 1 << n; ++ i){
        a[i].a <<= __builtin_popcount(i);
        a[i].b <<= __builtin_popcount(i);
        b[i].a <<= __builtin_popcount(i);
        b[i].b <<= __builtin_popcount(i);
    }
    FMT(a, 0);
    FMT(b, 0);
    for (int i = 0; i < 1 << n; ++ i){
        a[i] = a[i] * b[i];
    }
    FMT(a, 1);
}

int main(){
    scanf("%d", &n);
    scanf("%s%s", s, t);
    for (int i = 0; i < 1 << n; ++ i){
        a[i].a = (s[i] - '0') & 1;
        a[i].b = (s[i] - '0') >> 1;
        b[i].a = (t[i] - '0') & 1;
        b[i].b = (t[i] - '0') >> 1;
    }
    solve();
    for (int i = 0; i < 1 << n; ++ i){
        ans[i] = a[i][__builtin_popcount(i)] + '0';
    }
    puts(ans);
    return 0;
}