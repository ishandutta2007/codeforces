#include <bits/stdc++.h>

const int N = 1010;
const int M = 30;

int digit[N][M];

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++ i){
        int x = i - 1;
        for (int j = 0; j < M; ++ j){
            digit[i][j] = x % k;
            x /= k;
        }
    }
    bool first = false;
    int max = 0;
    for (int i = 1; i <= n; ++ i){
        for (int j = i + 1; j <= n; ++ j){
            for (int K = M - 1; K >= 0; -- K){
                if (digit[i][K] != digit[j][K]){
                    max = std::max(max, K + 1);
                    break;
                }
            }
        }
    }
    printf("%d\n", max);
    for (int i = 1; i <= n; ++ i){
        for (int j = i + 1; j <= n; ++ j){
            for (int K = M - 1; K >= 0; -- K){
                if (digit[i][K] != digit[j][K]){
                    if (!first){
                        first = true;
                    }
                    else{
                        putchar(' ');
                    }
                    printf("%d", K + 1);
                    break;
                }
            }
        }
    }
    puts("");
    return 0;
}