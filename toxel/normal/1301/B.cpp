#include <bits/stdc++.h>

const int N = 100010;

int a[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    std::vector <int> vec;
    for (int i = 0; i < n; ++ i){
        if (a[i] != -1){
            if ((i - 1 >= 0 && a[i - 1] == -1) || (i + 1 < n && a[i + 1] == -1)){
                vec.emplace_back(a[i]);
            }
        }
    }
    if (vec.empty()){
        puts("0 0");
        return;
    }
    int min = *std::min_element(vec.begin(), vec.end());
    int max = *std::max_element(vec.begin(), vec.end());
    for (int i = 0; i < n; ++ i){
        if (a[i] == -1){
            a[i] = (min + max) / 2;
        }
    }
    int ans = 0;
    for (int i = 0; i < n - 1; ++ i){
        ans = std::max(ans, std::abs(a[i] - a[i + 1]));
    }
    printf("%d %d\n", ans, (min + max) / 2);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}