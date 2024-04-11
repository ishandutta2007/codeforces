#include <bits/stdc++.h>

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        int n, m;
        scanf("%d%d", &n, &m);
        if (n % m == 0){
            puts("YES");
        }
        else{
            puts("NO");
        }
    }
    return 0;
}