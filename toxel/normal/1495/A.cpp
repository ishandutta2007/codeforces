#include <bits/stdc++.h>

void solve(){
    int n;
    scanf("%d", &n);
    std::vector <int> vec1, vec2;
    for (int i = 0; i < 2 * n; ++ i){
        int x, y;
        scanf("%d%d", &x, &y);
        if (x == 0){
            vec2.emplace_back(std::abs(y));
        }
        else{
            vec1.emplace_back(std::abs(x));
        }
    }
    std::sort(vec1.begin(), vec1.end());
    std::sort(vec2.begin(), vec2.end());
    double ans = 0;
    for (int i = 0; i < n; ++ i){
        ans += std::sqrt(1ll * vec1[i] * vec1[i] + 1ll * vec2[i] * vec2[i]);
    }
    printf("%.15f\n", ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}