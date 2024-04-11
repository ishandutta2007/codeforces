#include<bits/stdc++.h>

int main(){
    int n;
    scanf("%d", &n);
    if (n == 1){
        puts("0");
        return 0;
    }
    std::vector <int> ans;
    for (int i = 2; i <= n; ++ i){
        int x = i;
        for (int j = 2; j <= i; ++ j){
            if (i % j == 0){
                while (x % j == 0){
                    x /= j;
                }
                break;
            }
        }
        if (x == 1){
            ans.push_back(i);
        }
    }
    printf("%d\n", (int) ans.size());
    for (int i = 0, sz = ans.size(); i < sz; ++ i){
        printf("%d%c", ans[i], " \n"[i == sz - 1]);
    }
    return 0;
}