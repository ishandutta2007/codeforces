#include<bits/stdc++.h>

const int N = 100010;

int a[N], b[N];

int main(){
    int n, y1;
    scanf("%d%d", &n, &y1);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    int m, y2;
    scanf("%d%d", &m, &y2);
    for (int i = 0; i < m; ++ i){
        scanf("%d", &b[i]);
    }
    int max = 2;
    for (int i = 1; i <= 30; ++ i){
        std::map <int, int> Hash1, Hash2;
        for (int j = 0; j < n; ++ j){
            ++ Hash1[a[j] & ((1 << i) - 1)];
        }
        for (int j = 0; j < m; ++ j){
            ++ Hash2[b[j] & ((1 << i) - 1)];
        }
        for (auto u : Hash1){
            max = std::max(max, u.second + Hash2[u.first ^ (1 << (i - 1))]);
        }
        for (auto u : Hash2){
            max = std::max(max, u.second + Hash1[u.first ^ (1 << (i - 1))]);
        }
    }
    printf("%d\n", max);
    return 0;
}