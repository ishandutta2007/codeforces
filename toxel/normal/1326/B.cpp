#include <bits/stdc++.h>

const int N = 200010;

int a[N], b[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &b[i]);
    }
    int max = 0;
    for (int i = 0; i < n; ++ i){
        a[i] = b[i] + max;
        max = std::max(max, a[i]);
    }
    for (int i = 0; i < n; ++ i){
        printf("%d%c", a[i], " \n"[i == n - 1]);
    }
    return 0;
}