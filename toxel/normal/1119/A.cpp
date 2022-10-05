#include <bits/stdc++.h>

const int N = 300010;

int max[N];
int c[N];
int pre[N], suf[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &c[i]);
        max[c[i]] = std::max(max[c[i]], i);
    }
    for (int i = 1; i <= n; ++ i){
        pre[i] = std::max(pre[i - 1], max[i]);
    }
    for (int i = n; i >= 1; -- i){
        suf[i] = std::max(suf[i + 1], max[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++ i){
        ans = std::max(ans, std::abs(i - std::max(pre[c[i] - 1], suf[c[i] + 1])));
    }
    printf("%d\n", ans);
    return 0;
}