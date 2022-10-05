#include<bits/stdc++.h>

const int N = 1 << 17;
const int moder = 998244353;
const int M = 10;
typedef long long ll;

int a[N], b[N], c[N];

int powermod(int a, int exp){
    int ret = 1;
    for ( ; exp > 0; exp >>= 1){
        if (exp & 1){
            ret = 1ll * ret * a % moder;
        }
        a = 1ll * a * a % moder;
    }
    return ret;
}

void FWT_XOR(int *a, int length, int type){
    int len = -1;
    for (int x = length; x; ++ len, x >>= 1);
    for (int i = 1; i <= len; ++ i){
        for (int j = 0; j < length; j += 1 << i){
            for (int k = j, szk = 1 << i - 1; k < j + szk; ++ k){
                int s = a[k], t = a[k + szk];
                a[k] = s + t >= moder ? s + t - moder : s + t;
                a[k + szk] = s - t < 0 ? s - t + moder : s - t;
            }
        }
    }
    if (type == 1) return;
    int inv = powermod(length, moder - 2);
    for (int i = 0; i < length; ++ i){
        a[i] = 1ll * a[i] * inv % moder;
    }
}

int a1[N], a2[N], a3[N], res[N];
int mat[M][M];

void gauss(){
    for (int i = 0; i < 4; ++ i){
        for (int j = i; j < 4; ++ j){
            if (mat[i][j]){
                for (int k = i; k <= 4; ++ k){
                    std::swap(mat[i][k], mat[j][k]);
                }
                break;
            }
        }
        int inv = powermod(mat[i][i], moder - 2);
        for (int j = i; j <= 4; ++ j){
            mat[i][j] = 1ll * mat[i][j] * inv % moder;
        }
        for (int j = 0; j < 4; ++ j){
            if (j == i){
                continue;
            }
            for (int k = 4; k >= i; -- k){
                mat[j][k] = (mat[j][k] - 1ll * mat[i][k] * mat[j][i]) % moder;
                mat[j][k] += mat[j][k] < 0 ? moder : 0;
            }
        }
    }
}

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    int xsum = 0;
    for (int i = 0; i < n; ++ i){
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
        xsum ^= a[i];
        c[i] ^= a[i];
        b[i] ^= a[i];
    }
    for (int i = 0; i < n; ++ i){
        ++ a1[0], ++ a1[b[i]], ++ a1[c[i]];
        ++ a2[0], ++ a2[b[i]], -- a2[c[i]];
        ++ a3[b[i] ^ c[i]];
    }
    FWT_XOR(a1, 1 << k, 1);
    FWT_XOR(a2, 1 << k, 1);
    FWT_XOR(a3, 1 << k, 1);
    for (int i = 0; i < 1 << k; ++ i){
        mat[0][0] = 3, mat[0][1] = 1, mat[0][2] = 1, mat[0][3] = -1, mat[0][4] = a1[i];
        mat[1][0] = 1, mat[1][1] = 3, mat[1][2] = -1, mat[1][3] = 1, mat[1][4] = a2[i];
        mat[2][0] = 1, mat[2][1] = 1, mat[2][2] = 1, mat[2][3] = 1, mat[2][4] = n;
        mat[3][0] = 1, mat[3][1] = -1, mat[3][2] = -1, mat[3][3] = 1, mat[3][4] = a3[i];
        gauss();
        res[i] = 1;
        res[i] = 1ll * res[i] * powermod(((ll) x + y + z) % moder, mat[0][4]) % moder;
        res[i] = 1ll * res[i] * powermod(((ll) x + y - z) % moder, mat[1][4]) % moder;
        res[i] = 1ll * res[i] * powermod(((ll) x - y + z) % moder, mat[2][4]) % moder;
        res[i] = 1ll * res[i] * powermod(((ll) x - y - z) % moder, mat[3][4]) % moder;
        res[i] += res[i] < 0 ? moder : 0;
    }
    FWT_XOR(res, 1 << k, -1);
    for (int i = 0; i < 1 << k; ++ i){
        printf("%d%c", res[i ^ xsum], " \n"[i == (1 << k) - 1]);
    }
    return 0;
}