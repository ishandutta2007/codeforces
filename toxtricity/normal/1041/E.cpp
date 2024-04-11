#include<bits/stdc++.h>

const int N = 1010;

int u[N], v[N];
int cnt[N];
std::vector <int> e[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++ i){
        scanf("%d%d", &u[i], &v[i]);
        if (u[i] > v[i]){
            std::swap(u[i], v[i]);
        }
    }
    for (int i = 0; i < n - 1; ++ i){
        if (v[i] != n){
            puts("NO");
            return 0;
        }
        ++ cnt[u[i]];
    }
    for (int i = n - 1; i >= 1; -- i){
        if (!cnt[i]){
            bool flag = false;
            for (int j = i + 1; j < n; ++ j){
                if (e[j].size() + 1 < cnt[j]){
                    e[j].push_back(i);
                    flag = true;
                    break;
                }
            }
            if (!flag){
                puts("NO");
                return 0;
            }
        }
    }
    for (int i = 1; i < n; ++ i){
        if (!cnt[i]) continue;
        if (e[i].size() + 1 != cnt[i]){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    for (int i = 1; i < n; ++ i){
        if (!cnt[i]) continue;
        if (e[i].empty()){
            printf("%d %d\n", i, n);
            continue;
        }
        printf("%d %d\n", i, e[i][0]);
        for (int j = 0, sz = e[i].size(); j < sz - 1; ++ j){
            printf("%d %d\n", e[i][j], e[i][j + 1]);
        }
        printf("%d %d\n", e[i].back(), n);
    }
    return 0;
}