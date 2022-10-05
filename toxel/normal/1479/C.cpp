#include <bits/stdc++.h>

const int N = 24;
const int M = 1000010;

int cnt[N][M];
int mat[N][N];

int main(){
    for (int i = N - 2; i >= 2; -- i){
        for (int j = i + 1; j < N; ++ j){
            int exp = N - i - (j - i) - 2;
            exp = std::max(exp, 0);
            mat[i][j] = 1 << exp;
        }
    }
    int l, r;
    scanf("%d%d", &l, &r);
    int ll = l, rr = r;
    if (l == 1){
        ++ l;
        mat[1][N - 1] = 1;
    }
    if (l <= r){
        -- l, -- r;
        r -= l;
        ++ r;
        for (int i = 2; i <= N - 2; ++ i){
            int exp = N - 2 - i;
            if (r >> exp & 1){
                mat[1][i] = l + (r >> (exp + 1) << (exp + 1));
            }
        }
    }
    cnt[N - 1][0] = 1;
    for (int i = N - 2; i >= 1; -- i){
        for (int j = i + 1; j < N; ++ j){
            if (mat[i][j]){
                for (int k = 0; k + mat[i][j] < M; ++ k){
                    cnt[i][k + mat[i][j]] += cnt[j][k];
                }
            }
        }
    }
    for (int i = 0; i < M; ++ i){
        if (ll <= i && i <= rr){
            assert(cnt[1][i] == 1);
        }
        else{
            assert(cnt[1][i] == 0);
        }
    }
    int n = N - 1, m = 0;
    for (int i = 1; i < N; ++ i){
        for (int j = i + 1; j < N; ++ j){
            if (mat[i][j]){
                ++ m;
            }
        }
    }
    printf("YES\n%d %d\n", n, m);
    for (int i = 1; i < N; ++ i){
        for (int j = i + 1; j < N; ++ j){
            if (mat[i][j]){
                printf("%d %d %d\n", i, j, mat[i][j]);
            }
        }
    }
    return 0;
}