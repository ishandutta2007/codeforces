#include <bits/stdc++.h>

const int N = 100010;

char a[N], b[N];

void solve(){
    int n;
    scanf("%d%s%s", &n, a, b);
    std::vector<int> ans1, ans2;
    for (int i = 0; i < n - 1; ++ i){
        if (a[i] != a[i + 1]){
            ans1.emplace_back(i);
        }
    }
    if (a[n - 1] != b[n - 1]){
        ans1.emplace_back(n - 1);
    }
    for (int i = 0; i < n - 1; ++ i){
        if (b[i] != b[i + 1]){
            ans2.emplace_back(i);
        }
    }
    std::reverse(ans2.begin(), ans2.end());
    for (auto u : ans2){
        ans1.emplace_back(u);
    }
    int sz = ans1.size();
    printf("%d", sz);
    for (auto u : ans1){
        printf(" %d", u + 1);
    }
    puts("");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
}