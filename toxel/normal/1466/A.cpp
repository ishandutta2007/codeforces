#include <bits/stdc++.h>

const int N = 110;

int x[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &x[i]);
    }
    std::set <int> set;
    for (int i = 0; i < n; ++ i){
        for (int j = i + 1; j < n; ++ j){
            set.insert(x[j] - x[i]);
        }
    }
    printf("%d\n", int(set.size()));
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}