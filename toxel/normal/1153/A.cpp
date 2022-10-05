#include <bits/stdc++.h>

int main(){
    int n, t;
    scanf("%d%d", &n, &t);
    int min = INT_MAX, sit = -1;
    for (int i = 0; i < n; ++ i){
        int s, d;
        scanf("%d%d", &s, &d);
        for ( ; s < t; s += d)
            ;
        if (min > s){
            min = s;
            sit = i + 1;
        }
    }
    printf("%d\n", sit);
    return 0;
}