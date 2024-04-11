#include <bits/stdc++.h>

void solve(){
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    int x, y, x1, y1, x2, y2;
    scanf("%d%d%d%d%d%d", &x, &y, &x1, &y1, &x2, &y2);
    if (x1 == x2 && a + b > 0){
        puts("NO");
        return;
    }
    if (y1 == y2 && c + d > 0){
        puts("NO");
        return;
    }
    x += b - a;
    y += d - c;
    if (x1 <= x && x <= x2 && y1 <= y && y <= y2){
        puts("YES");
    }
    else{
        puts("NO");
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}