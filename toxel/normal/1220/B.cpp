#include<bits/stdc++.h>

const int N = 1010;
typedef long long ll;

int a[N][N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; ++ i){
        int x = (i + 1) % n, y = (i + 2) % n;
        ll value = 1ll * a[y][i] * a[i][x] / a[x][y];
        int u = std::sqrt((long double) value);
        while (1ll * u * u < value){
            ++ u;
        }
        while (1ll * u * u > value){
            -- u;
        }
        printf("%d%c", u, " \n"[i == n - 1]);
    }
    return 0;
}