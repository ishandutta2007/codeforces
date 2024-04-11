#include <bits/stdc++.h>

const int N = 100010;

int a[N], b[N];
int rank[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    std::reverse(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &b[i]);
        rank[a[i]] = i;
    }
    std::reverse(b + 1, b + n + 1);
    int max = 0, ans = 0;
    for (int i = 1; i <= n; ++ i){
        if (max > rank[b[i]]){
            ++ ans;
        }
        max = std::max(max, rank[b[i]]);
    }
    printf("%d\n", ans);
    return 0;
}