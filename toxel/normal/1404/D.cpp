#include <bits/stdc++.h>

const int N = 1000010;

std::vector<int> e[N], pos[N], group[N];
int a[N], col[N];
bool vis[N];

void dfs(int u){
    vis[u] = true;
    for (auto v : e[u]){
        if (vis[v]){
            continue;
        }
        col[v] = col[u] ^ 1;
        dfs(v);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    if (n % 2 == 0){
        puts("First");
        fflush(stdout);
        for (int i = 1; i <= 2 * n; ++ i){
            printf("%d%c", i % n + 1, " \n"[i == 2 * n]);
        }
        fflush(stdout);
    }
    else{
        puts("Second");
        fflush(stdout);
        std::vector<int> vec1, vec2;
        for (int i = 1; i <= 2 * n; ++ i){
            scanf("%d", &a[i]);
            pos[i % n].emplace_back(i);
            group[a[i] - 1].emplace_back(i);
        }
        for (int i = 0; i < n; ++ i){
            e[group[i][0]].emplace_back(group[i][1]);
            e[group[i][1]].emplace_back(group[i][0]);
            e[pos[i][0]].emplace_back(pos[i][1]);
            e[pos[i][1]].emplace_back(pos[i][0]);
        }
        for (int i = 1; i <= 2 * n; ++ i){
            if (!vis[i]){
                dfs(i);
            }
        }
        for (int i = 1; i <= 2 * n; ++ i){
            if (col[i]){
                vec1.emplace_back(i);
            }
            else{
                vec2.emplace_back(i);
            }
        }
        std::sort(vec1.begin(), vec1.end());
        std::sort(vec2.begin(), vec2.end());
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; ++ i){
            sum1 = (sum1 + vec1[i]) % (2 * n);
            sum2 = (sum2 + vec2[i]) % (2 * n);
        }
        if (sum2 == 0){
            vec1 = vec2;
        }
        for (int i = 0; i < n; ++ i){
            printf("%d%c", vec1[i], " \n"[i == n - 1]);
        }
        fflush(stdout);
    }
    int result;
    scanf("%d", &result);
    return 0;
}