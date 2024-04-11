#include <bits/stdc++.h>

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        int n;
        scanf("%d", &n);
        std::set <int> set;
        for (int i = 0, x; i < n; ++ i){
            scanf("%d", &x);
            set.insert(x);
        }
        printf("%d\n", int(set.size()));
    }
    return 0;
}