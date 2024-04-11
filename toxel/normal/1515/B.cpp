#include <bits/stdc++.h>

const int INF = 1.1e9;

int main(){
    std::set <int> set;
    for (int i = 1; ; ++ i){
        set.insert(2 * i * i);
        if (2 * i * i > INF){
            break;
        }
    }
    for (int i = 1; ; ++ i){
        set.insert(4 * i * i);
        if (4 * i * i > INF){
            break;
        }
    }
    int test;
    scanf("%d", &test);
    while (test --){
        int n;
        scanf("%d", &n);
        puts(set.count(n) ? "YES" : "NO");
    }
    return 0;
}