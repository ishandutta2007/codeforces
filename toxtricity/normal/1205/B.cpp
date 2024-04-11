#include <bits/stdc++.h>

const int N = 1000010;
const int M = 210;
typedef long long ll;

ll a[N];
int mat[M][M];
int dis[M];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%lld", &a[i]);
        if (!a[i]){
            -- i, -- n;
        }
    }
    for (int i = 0; i <= 60; ++ i){
        int cnt = 0;
        for (int j = 0; j < n; ++ j){
            cnt += a[j] >> i & 1;
        }
        if (cnt >= 3){
            puts("3");
            return 0;
        }
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            mat[i][j] = (a[i] & a[j]) > 0;
        }
    }
    int min = INT_MAX;
    for (int i = 0; i < n; ++ i){
        for (int j = i + 1; j < n; ++ j){
            if (!mat[i][j]){
                continue;
            }
            mat[i][j] = 0;
            memset(dis, -1, sizeof(dis));
            std::queue <int> queue;
            queue.push(i);
            dis[i] = 0;
            while (!queue.empty()){
                int u = queue.front();
                queue.pop();
                for (int k = 0; k < n; ++ k){
                    if (!mat[u][k]){
                        continue;
                    }
                    if (dis[k] != -1){
                        continue;
                    }
                    dis[k] = dis[u] + 1;
                    queue.push(k);
                }
            }
            if (dis[j] != -1){
                min = std::min(dis[j] + 1, min);
            }
            mat[i][j] = 1;
        }
    }
    min = min == INT_MAX ? -1 : min;
    printf("%d\n", min);
    return 0;
}