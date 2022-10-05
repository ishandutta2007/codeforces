#include<bits/stdc++.h>

int main(){
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a < x){
        puts("NO");
        return 0;
    }
    a -= x;
    b += a;
    if (b < y){
        puts("NO");
        return 0;
    }
    b -= y;
    c += b;
    if (c < z){
        puts("NO");
        return 0;
    }
    puts("YES");
    return 0;
}