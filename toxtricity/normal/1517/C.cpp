#include <bits/stdc++.h>

const int N = 510;

int p[N];
int ans[N][N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &p[i]);
        // p[i] = i;
    }
    // std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
    // std::shuffle(p + 1, p + n + 1, rnd);
    for (int i = 1; i <= n; ++ i){
        int curx = i, cury = i;
        for (int j = 1; j <= p[i]; ++ j){
            ans[curx][cury] = p[i];
            if (cury > 1 && ans[curx][cury - 1] == 0){
                -- cury;
            }
            else{
                ++ curx;
            }
        }
    }
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= i; ++ j){
            printf("%d%c", ans[i][j], " \n"[j == i]);
        }
    }
    return 0;
}