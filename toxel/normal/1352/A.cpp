#include <bits/stdc++.h>

void solve(){
    int n;
    scanf("%d", &n);
    int prod = 1;
    std::vector<int> ans;
    while (n){
        while (n % 10 == 0){
            n /= 10;
            prod *= 10;
        }
        ans.emplace_back(n % 10 * prod);
        n /= 10;
        prod *= 10;
    }
    int sz = ans.size();
    printf("%d\n", sz);
    for (int i = 0; i < sz; ++ i){
        printf("%d%c", ans[i], " \n"[i == sz - 1]);
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}