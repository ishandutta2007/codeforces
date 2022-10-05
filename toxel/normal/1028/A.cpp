#include<bits/stdc++.h>

const int N = 120;

char s[N][N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        scanf("%s", s[i]);
    }
    int lsum = 0, rsum = 0, cnt = 0;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            if (s[i][j] == 'B'){
                lsum += i;
                rsum += j;
                ++ cnt;
            }
        }
    }
    printf("%d %d\n", lsum / cnt + 1, rsum / cnt + 1);
    return 0;
}