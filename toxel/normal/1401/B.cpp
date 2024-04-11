#include <bits/stdc++.h>

void sub(int &a, int &b){
    int x = std::min(a, b);
    a -= x, b -= x;
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        int a0, a1, a2;
        scanf("%d%d%d", &a0, &a1, &a2);
        int b0, b1, b2;
        scanf("%d%d%d", &b0, &b1, &b2);
        int x = std::min(a2, b1);
        int ans = 2 * x;
        sub(a2, b1);
        sub(a1, b1);
        sub(a2, b2);
        sub(a0, b1);
        sub(a0, b2);
        sub(b0, a1);
        sub(b0, a2);
        ans -= 2 * std::min(a1, b2);
        printf("%d\n", ans);
    }
    return 0;
}