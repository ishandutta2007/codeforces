#include <bits/stdc++.h>

const int N = 100010;

int p[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &p[i]);
    }
    std::vector<int> ans;
    for (int i = 1; i <= n; ++ i){
        if (i == 1 || i == n){
            ans.emplace_back(p[i]);
            continue;
        }
        bool flag = p[i - 1] < p[i], flag1 = p[i] < p[i + 1];
        if (flag != flag1){
            ans.emplace_back(p[i]);
        }
    }
    int k = ans.size();
    printf("%d\n", k);
    for (int i = 0; i < k; ++ i){
        printf("%d%c", ans[i], " \n"[i == k - 1]);
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
}