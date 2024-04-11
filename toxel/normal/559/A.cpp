#include<bits/stdc++.h>

inline int sqr(int n){return n * n;}

int main(){
    int a1, a2, a3, a4, a5, a6;
    scanf("%d%d%d%d%d%d", &a1, &a2, &a3, &a4, &a5, &a6);
    printf("%d\n", sqr(a1 + a2 + a6) - sqr(a2) - sqr(a4) - sqr(a6));
    return 0;
}