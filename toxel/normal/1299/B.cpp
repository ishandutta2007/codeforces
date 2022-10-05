#include <bits/stdc++.h>

const int N = 100010;

int x[N], y[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d%d", &x[i], &y[i]);
    }
    if (n % 2 == 1){
        puts("NO");
        return 0;
    }
    for (int i = 0; i < n / 2; ++ i){
        if (x[i] + x[i + n / 2] != x[0] + x[n / 2]){
            puts("NO");
            return 0;
        }
        if (y[i] + y[i + n / 2] != y[0] + y[n / 2]){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}