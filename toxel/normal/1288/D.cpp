#include <bits/stdc++.h>

const int N = 300010;
const int BIT = 10;
const int M = 10;

int vis[1 << BIT];
int a[N][M];
int n, m;
int ans1, ans2;

bool check(int mid){
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; ++ i){
        int mask = 0;
        for (int j = 0; j < m; ++ j){
            if (a[i][j] >= mid){
                mask |= 1 << j;
            }
        }
        vis[mask] = i + 1;
    }
    for (int i = 0; i < 1 << m; ++ i){
        if (!vis[i]){
            continue;
        }
        for (int j = i; j < 1 << m; ++ j){
            if (!vis[j]){
                continue;
            }
            if ((i | j) == (1 << m) - 1){
                ans1 = vis[i], ans2 = vis[j];
                return true;
            }
        }
    }
    return false;
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            scanf("%d", &a[i][j]);
        }
    }
    int left = 0, right = int(1.1e9);
    while (left < right){
        int mid = (left + right + 1) / 2;
        if (check(mid)){
            left = mid;
        }
        else{
            right = mid - 1;
        }
    }
    check(left);
    printf("%d %d\n", ans1, ans2);
    return 0;
}