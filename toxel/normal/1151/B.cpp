#include <bits/stdc++.h>

const int N = 510;

int a[N][N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            scanf("%d", &a[i][j]);
        }
    }
    int sitx = -1, sity = -1;
    for (int i = 0; i < n; ++ i){
        for (int j = 1; j < m; ++ j){
            if (a[i][j] != a[i][0]){
                sitx = i, sity = j;
                break;
            }
        }
        if (sitx != -1){
            break;
        }
    }
    int sum = 0;
    for (int i = 0; i < n; ++ i){
        sum ^= a[i][0];
    }
    if (sum){
        puts("TAK");
        for (int i = 0; i < n; ++ i){
            printf("%d%c", 1, " \n"[i == n - 1]);
        }
        return 0;
    }
    if (sitx == -1){
        puts("NIE");
        return 0;
    }
    puts("TAK");
    for (int i = 0; i < n; ++ i){
        printf("%d%c", i == sitx ? sity + 1 : 1, " \n"[i == n - 1]);
    }
    return 0;
}