#include <bits/stdc++.h>

const int N = 1000010;

int a[N];

int main(){
    int n;
    scanf("%d", &n);
    if (n % 2 == 0){
        puts("NO");
        return 0;
    }
    puts("YES");
    a[0] = 0;
    for (int i = 1; i < n; ++ i){
        a[i] = a[i - 1] + (i & 1 ? 3 : 1);
    }
    for (int i = n; i < 2 * n; ++ i){
        a[i] = a[i - n] ^ 1;
    }
    for (int i = 0; i < 2 * n; ++ i){
        printf("%d%c", a[i] + 1, " \n"[i == 2 * n - 1]);
    }
    return 0;
}