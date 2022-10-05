#include<bits/stdc++.h>

const int N = 100010;

int a[N], col[N];
std::vector <int> vec[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        vec[a[i]].push_back(i);
    }
    int nowcol = 1;
    for (int i = 0; i < N; ++ i){
        if (vec[i].empty()) continue;
        if (vec[i].size() % (n - i)){
            puts("Impossible");
            return 0;
        }
        for (int j = 0, sz = vec[i].size() / (n - i); j < sz; ++ j){
            for (int k = 0; k < n - i; ++ k){
                col[vec[i][j * (n - i) + k]] = nowcol;
            }
            ++ nowcol;
        }
    }
    puts("Possible");
    for (int i = 1; i <= n; ++ i){
        printf("%d%c", col[i], " \n"[i == n]);
    }
    return 0;
}