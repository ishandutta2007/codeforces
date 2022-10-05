#include <bits/stdc++.h>

const int moder = 998244353;

struct Matrix{
    const static int N = 2;

    int a[N][N];

    Matrix():a(){}

    int *operator [](const int &n){return a[n];}

    Matrix operator *(const Matrix &m)const{
        Matrix ret;
        for (int k = 0; k < 2; ++ k){
            for (int i = 0; i < 2; ++ i){
                for (int j = 0; j < 2; ++ j){
                    ret[i][j] = (ret[i][j] + 1ll * a[i][k] * m.a[k][j]) % moder;
                }
            }
        }
        return ret;
    }
};

const int MAX = 1 << 19;

Matrix seg[MAX << 1];

void add(int sit, Matrix value){
    seg[sit += MAX] = value;
    for (sit >>= 1; sit; sit >>= 1){
        seg[sit] = seg[sit << 1 | 1] * seg[sit << 1];
    }
}

Matrix query(int l, int r){
    Matrix retl, retr;
    for (int i = 0; i < 2; ++ i){
        retl[i][i] = retr[i][i] = 1;
    }
    for (l += MAX, r += MAX + 1; l < r; l >>= 1, r >>= 1){
        if (l & 1) retl = seg[l ++] * retl;
        if (r & 1) retr = retr * seg[-- r];
    }
    return retr * retl;
}

char s[MAX];

void update(int pos){
    Matrix trans;
    trans[0][1] = 1;
    trans[1][1] = s[pos] - '0' + 1;
    if (pos > 0 && s[pos - 1] == '1'){
        int value = s[pos - 1] - '0';
        value = value * 10 + s[pos] - '0';
        trans[1][0] = 19 - value;
    }
    add(pos, trans);
}

int main(){
    int n, m;
    scanf("%d%d%s", &n, &m, s);
    for (int i = 0; i < n; ++ i){
        update(i);
    }
    while (m --){
        int pos, d;
        scanf("%d%d", &pos, &d);
        -- pos;
        s[pos] = d + '0';
        update(pos);
        if (pos < n - 1){
            update(pos + 1);
        }
        Matrix mat = query(0, n - 1);
        printf("%d\n", mat[1][1]);
    }
    return 0;
}