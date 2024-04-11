#include <bits/stdc++.h>

const int N = 100010;
const int MAX = 1 << 17;
const int INF = 0x3f3f'3f3f;

struct Matrix{
    const static int M = 3;

    int a[M][M];

    Matrix(){
        for (int i = 0; i < M; ++ i){
            for (int j = 0; j < M; ++ j){
                a[i][j] = INF;
            }
        }
    }

    int *operator [](int n){return a[n];}

    Matrix operator *(const Matrix &m)const{
        Matrix result;
        for (int k = 0; k < M; ++ k){
            for (int i = 0; i < M; ++ i){
                for (int j = 0; j < M; ++ j){
                    result[i][j] = std::min(result[i][j], a[i][k] + m.a[k][j]);
                }
            }
        }
        return result;
    }
};

Matrix seg[MAX << 1];

void add(int pos, char ch){
    Matrix mat;
    for (int i = 0; i < 3; ++ i){
        for (int j = 0; j <= i; ++ j){
            mat[i][j] = 0;
        }
    }
    if (ch == 'a'){
        mat[0][0] = 1;
    }
    else if (ch == 'b'){
        mat[1][0] = mat[1][1] = 1;
    }
    else if (ch == 'c'){
        mat[2][0] = mat[2][1] = mat[2][2] = 1;
    }
    seg[pos + MAX] = mat;
    for (pos += MAX, pos >>= 1; pos; pos >>= 1){
        seg[pos] = seg[pos << 1 | 1] * seg[pos << 1];
    }
}

char s[N];

int main(){
    for (int i = 0; i < MAX << 1; ++ i){
        for (int j = 0; j < Matrix::M; ++ j){
            seg[i][j][j] = 0;
        }
    }
    int n, q;
    scanf("%d%d", &n, &q);
    scanf("%s", s);
    for (int i = 0; i < n; ++ i){
        add(i, s[i]);
    }
    while (q --){
        int pos;
        char ch[10];
        scanf("%d%s", &pos, ch);
        -- pos;
        add(pos, ch[0]);
        int min = INF;
        for (int i = 0; i < Matrix::M; ++ i){
            for (int j = 0; j < Matrix::M; ++ j){
                min = std::min(min, seg[1][i][j]);
            }
        }
        printf("%d\n", min);
    }
    return 0;
}