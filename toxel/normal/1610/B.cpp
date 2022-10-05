#include <bits/stdc++.h>

const int N = 200010;

int a[N];

bool check(int n, int del){
    std::vector <int> vec;
    for (int i = 1; i <= n; ++ i){
        if (a[i] != del){
            vec.emplace_back(a[i]);
        }
    }
    int sz = vec.size();
    for (int i = 0; i < sz; ++ i){
        if (vec[i] != vec[sz - 1 - i]){
            return false;
        }
    }
    return true;
}

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int l = 1, r = n; l < r; ++ l, -- r){
        if (a[l] != a[r]){
            if (check(n, a[l])){
                puts("YES");
                return;
            }
            if (check(n, a[r])){
                puts("YES");
                return;
            }
            puts("NO");
            return;
        }
    }
    puts("YES");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}