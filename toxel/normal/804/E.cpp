#include <bits/stdc++.h>

void operate(int a, int b, int c, int d){
    printf("%d %d\n", a, b);
    printf("%d %d\n", c, d);
    printf("%d %d\n", a, c);
    printf("%d %d\n", b, d);
    printf("%d %d\n", a, d);
    printf("%d %d\n", b, c);
}

void operate1(int a, int b, int c, int d){
    printf("%d %d\n", a, c);
    printf("%d %d\n", b, d);
    printf("%d %d\n", a, d);
    printf("%d %d\n", b, c);
}

void operate2(int a, int b, int c, int d, int e){
    printf("%d %d\n", a, b);
    printf("%d %d\n", b, c);
    printf("%d %d\n", a, c);
    printf("%d %d\n", a, d);
    printf("%d %d\n", d, e);
    printf("%d %d\n", a, e);
    printf("%d %d\n", b, d);
    printf("%d %d\n", c, e);
    printf("%d %d\n", b, e);
    printf("%d %d\n", c, d);
}

void solve(int n){
    if (n == 1){
        return;
    }
    if (n == 4){
        operate(1, 2, 3, 4);
        return;
    }
    solve(n - 4);
    for (int i = 1; i <= n - 5; i += 2){
        for (int j = n - 3; j <= n; j += 2){
            operate1(i, i + 1, j, j + 1);
        }
    }
    if (n % 4 == 0){
        operate(n - 3, n - 2, n - 1, n);
        return;
    }
    operate2(n - 4, n - 3, n - 2, n - 1, n);
}

int main(){
    int n;
    scanf("%d", &n);
    if (n % 4 == 2 || n % 4 == 3){
        puts("NO");
        return 0;
    }
    puts("YES");
    solve(n);
}