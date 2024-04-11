#include <bits/stdc++.h>

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        int l, r;
        scanf("%d%d", &l, &r);
        if (2 * l > r){
            puts("-1 -1");
            continue;
        }
        printf("%d %d\n", l, 2 * l);
    }
    return 0;
}