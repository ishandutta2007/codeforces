#include <bits/stdc++.h>

void solve(){
    int a, b;
    scanf("%d%d", &a, &b);
    int n = a + b;
    std::set <int> ans;
    for (int first = 0; first <= 1; ++ first){
        for (int x11 = 0; x11 <= a; ++ x11){
            int s1 = n / 2, s2 = n / 2;
            if (n % 2 == 1){
                ++ (first ? s2 : s1);
            }
            int x21 = s1 - x11;
            int x22 = b - x21;
            int x12 = s2 - x22;
            if (x21 >= 0 && x22 >= 0 && x12 >= 0){
                ans.insert(x12 + x21);
            }
        }
    }
    std::vector <int> vec;
    for (auto u : ans){
        vec.emplace_back(u);
    }
    int sz = vec.size();
    printf("%d\n", sz);
    for (int i = 0; i < sz; ++ i){
        printf("%d%c", vec[i], " \n"[i == sz - 1]);
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