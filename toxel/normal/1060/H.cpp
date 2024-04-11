#include<bits/stdc++.h>

int d, moder;
const int N = 12;
const int MAX = 5000;
const int MID = 2000;
const int BIT = 31;

int a[N][N];
int inv[N][N];

inline void sub(int &a, int b){
    a -= b;
    a += a < 0 ? moder : 0;
}

int powermod(int a, int exp){
    int ret = 1;
    for ( ; exp; exp >>= 1){
        if (exp & 1){
            ret = 1ll * ret * a % moder;
        }
        a = 1ll * a * a % moder;
    }
    return ret;
}

void mult(int sit, int value){
    printf("+ %d %d %d\n", MAX - 1, MAX - 1, MAX);
    for ( ; value > 0; value >>= 1){
        if (value & 1){
            printf("+ %d %d %d\n", MAX, sit, MAX);
        }
        printf("+ %d %d %d\n", sit, sit, sit);
    }
    printf("+ %d %d %d\n", MAX - 1, MAX, sit);
}

void power2(int sit){
    printf("+ %d %d %d\n", MAX - 1, sit, MID);
    for (int i = 1; i <= d; ++ i){
        printf("+ %d %d %d\n", MID + i - 1, MID - 1, MID + i);
    }
    for (int i = 0; i <= d; ++ i){
        printf("^ %d %d\n", MID + i, MID + i);
    }
    for (int i = 0; i <= d; ++ i){
        mult(MID + i, inv[d - 2][i]);
    }
    for (int i = 1; i <= d; ++ i){
        printf("+ %d %d %d\n", MID, MID + i, MID);
    }
    printf("+ %d %d %d\n", MID, MAX - 1, sit);
}

int comb[N][N];

int main(){
    scanf("%d%d", &d, &moder);
    for (int i = 0; i < N; ++ i){
        comb[i][0] = 1;
        for (int j = 1; j <= i; ++ j){
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % moder;
        }
    }
    int value = moder - 2;
    for ( ; value > 0; value >>= 1){
        if (value & 1){
            printf("+ %d %d %d\n", MAX, MAX - 1, MAX);
        }
        printf("+ %d %d %d\n", MAX - 1, MAX - 1, MAX - 1);
    }
    printf("+ %d %d %d\n", MAX - 2, MAX, MAX - 1);
    for (int i = 0; i <= d; ++ i){
        a[i][0] = 1;
        for (int j = 1; j <= d; ++ j){
            a[i][j] = 1ll * a[i][j - 1] * i % moder;
        }
        for (int j = 1; j <= d; ++ j){
            a[i][j] = 1ll * a[i][j] * comb[d][j] % moder;
        }
        inv[i][i] = 1;
    }
    for (int i = 0; i <= d; ++ i){
        for (int j = i; j <= d; ++ j){
            if (a[i][j]){
                if (i != j){
                    for (int k = 0; k <= d; ++ k){
                        std::swap(a[i][k], a[j][k]);
                        std::swap(inv[i][k], inv[j][k]);
                    }
                }
                break;
            }
        }
        int x = powermod(a[i][i], moder - 2);
        for (int j = 0; j <= d; ++ j){
            a[i][j] = 1ll * a[i][j] * x % moder;
            inv[i][j] = 1ll * inv[i][j] * x % moder;
        }
        for (int j = 0; j <= d; ++ j){
            if (j == i) continue;
            int coe = a[j][i];
            for (int k = 0; k <= d; ++ k){
                sub(a[j][k], 1ll * coe * a[i][k] % moder);
                sub(inv[j][k], 1ll * coe * inv[i][k] % moder);
            }
        }
    }
    puts("+ 1 2 1");
    mult(2, moder - 2);
    puts("+ 1 2 2");
    power2(1);
    power2(2);
    mult(2, moder - 1);
    puts("+ 1 2 1");
    mult(1, powermod(4, moder - 2));
    puts("f 1");
    return 0;
}