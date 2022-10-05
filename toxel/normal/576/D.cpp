#include<bits/stdc++.h>

const int N = 160;

struct matrix{
    int a[N][N];
    int n;

    matrix (int n):n(n){memset(a, 0, sizeof(a));}

    int *operator [](int n){
        return a[n];
    }
};

struct Edge{
    int u, v, d;

    void read(){
        scanf("%d%d%d", &u, &v, &d);
        -- u, -- v;
    }

    bool operator < (const Edge &e)const{
        return d < e.d;
    }
};

std::bitset <N> set1[N], set2[N];

matrix mult(matrix &mat1, matrix &mat2){
    for (int i = 0; i < N; ++ i){
        set1[i].reset();
        set2[i].reset();
    }
    matrix ret(mat1.n);
    for (int i = 0; i < mat1.n; ++ i){
        for (int j = 0; j < mat1.n; ++ j){
            set1[i][j] = mat1[i][j];
            set2[j][i] = mat2[i][j];
        }
    }
    for (int i = 0; i < mat1.n; ++ i){
        for (int j = 0; j < mat1.n; ++ j){
            ret[i][j] = (set1[i] & set2[j]).any();
        }
    }
    return ret;
}

matrix mult2(matrix &mat1, matrix &mat2){
    for (int i = 0; i < N; ++ i){
        set1[i].reset();
        set2[i].reset();
    }
    matrix ret = mat1;
    for (int i = 0; i < mat1.n; ++ i){
        for (int j = 0; j < mat1.n; ++ j){
            set1[i][j] = mat1[i][j];
            set2[j][i] = mat2[i][j];
        }
    }
    for (int i = 0; i < mat1.n; ++ i){
        for (int j = 0; j < mat1.n; ++ j){
            ret[i][j] |= (set1[i] & set2[j]).any();
        }
    }
    return ret;
}

Edge e[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++ i){
        e[i].read();
    }
    std::sort(e, e + m);
    if (e[0].d != 0){
        puts("Impossible");
        return 0;
    }
    int now = 0;
    matrix mat(n), mat1(n);
    for (int i = 0; i < n; ++ i){
        mat1[i][i] = 1;
    }
    for (int i = 0; i < m; ){
        while (i < m && e[i].d == now){
            mat[e[i].u][e[i].v] = true;
            ++ i;
        }
        matrix mat2 = mat;
        for (int i = 0; i < 8; ++ i){
            mat2 = mult2(mat2, mat2);
        }
        mat2 = mult2(mat1, mat2);
        if (mat2[0][n - 1]){
            while (true){
                if (mat1[0][n - 1]){
                    printf("%d\n", now);
                    return 0;
                }
                ++ now;
                mat1 = mult(mat1, mat);
            }
        }
        if (i == m){
            puts("Impossible");
            return 0;
        }
        mat2 = mat;
        int exp = e[i].d - now;
        for ( ; exp > 0; exp >>= 1){
            if (exp & 1){
                mat1 = mult(mat1, mat2);
            }
            mat2 = mult(mat2, mat2);
        }
        /*bool flag = true;
        for (int i = 0; i < n; ++ i){
            for (int j = 0; j < n; ++ j){
                if (mat1[i][j]){
                    flag = false;
                }
            }
        }
        if (flag){
            puts("Impossible");
            return 0;
        }*/
        now = e[i].d;
    }
}