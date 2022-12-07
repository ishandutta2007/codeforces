#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define maxn 55
using namespace std;
int grid[maxn][maxn];
int n;
void work(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (grid[i][j] == 1) continue;
            int now = grid[i][j];
            for (int k = 1; k <= n; k++){
                for (int l = 1; l <= n; l++){
                    if (now == grid[i][k] + grid[l][j]){
                        goto jump;
                    }
                }
            }
            printf("No");
            return;
            jump:;
        }
    }
    printf("Yes");
    return;
}
int main(){
    /*freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);*/
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            scanf("%d", &grid[i][j]);
        }
    }
    work();
    return 0;
}