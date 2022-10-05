#include <bits/stdc++.h>

using ll = long long;

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        int x, y;
        scanf("%d%d", &x, &y);
        int ans;
        if (x > y){
            ans = x + y;
        }
        else{
            ans = (y / x * x + y) / 2;
        }
        printf("%d\n", ans);
        assert(ans % x == y % ans);
    }
    return 0;
}