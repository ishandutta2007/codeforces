#include<bits/stdc++.h>

int main(){
    int prea = 0, preb = 0, ans = 1;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        int a, b;
        scanf("%d%d", &a, &b);
        ans += std::max(std::min(a, b) - std::max(prea, preb) + 1, 0);
        if (prea == preb){
            -- ans;
        }
        prea = a, preb = b;
    }
    printf("%d\n", ans);
    return 0;
}