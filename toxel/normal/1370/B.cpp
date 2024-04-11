#include <bits/stdc++.h>

const int N = 2010;

int a[N];

void solve(){
    int n;
    scanf("%d", &n);
    int sum = 0;
    std::vector<int> vec[2];
    for (int i = 1; i <= 2 * n; ++ i){
        scanf("%d", &a[i]);
        vec[a[i] % 2].emplace_back(i);
    }
    int cnt = 0;
    for (int i = 0; i < 2; ++ i){
        int sz = vec[i].size();
        for (int j = 0; j + 1 < sz; j += 2){
            ++ cnt;
            if (cnt == n){
                return;
            }
            printf("%d %d\n", vec[i][j], vec[i][j + 1]);
        }
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
}