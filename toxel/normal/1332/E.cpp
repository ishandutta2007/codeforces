#include <bits/stdc++.h>

const int moder = 998244353;

struct matrix{
    const static int N = 2;

    int a[N][N]{};

    int *operator[](const int &n){ return a[n]; }
    matrix operator *(const matrix &m)const{
        matrix ret;
        for (int k = 0; k < N; ++ k){
            for (int i = 0; i < N; ++ i){
                for (int j = 0; j < N; ++ j){
                    ret[i][j] = (ret[i][j] + 1ll * a[i][k] * m.a[k][j]) % moder;
                }
            }
        }
        return ret;
    }
};

using ll = long long;

matrix powermod(matrix a, ll exp){
    matrix ret;
    ret[0][0] = ret[1][1] = 1;
    for ( ; exp > 0; exp >>= 1){
        if (exp & 1){
            ret = ret * a;
        }
        a = a * a;
    }
    return ret;
}

int main(){
    int n, m, l, r;
    scanf("%d%d%d%d", &n, &m, &l, &r);
    int zero = r / 2 - (l - 1) / 2;
    int one = r - l + 1 - zero;
    matrix trans;
    trans[0][0] = trans[1][1] = zero;
    trans[0][1] = trans[1][0] = one;
    trans = powermod(trans, 1ll * n * m);
    if (1ll * n * m % 2 != 0){
        printf("%d\n", (trans[0][0] + trans[1][0]) % moder);
    }
    else{
        printf("%d\n", trans[0][0]);
    }
    return 0;
}