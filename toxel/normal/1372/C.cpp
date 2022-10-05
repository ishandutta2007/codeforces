#include <bits/stdc++.h>

const int N = 200010;

int a[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    bool flag = true;
    for (int i = 1; i <= n; ++ i){
        if (a[i] != i){
            flag = false;
            break;
        }
    }
    if (flag){
        puts("0");
        return;
    }
    std::vector<int> vec;
    for (int i = 1; i <= n; ++ i){
        if (a[i] != i){
            vec.emplace_back(i);
        }
    }
    for (int i = 0, sz = vec.size(); i < sz - 1; ++ i){
        if (vec[i] + 1 != vec[i + 1]){
            puts("2");
            return;
        }
    }
    puts("1");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}