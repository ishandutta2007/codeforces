#include <bits/stdc++.h>

const int N = 100010;
using ll = long long;

ll a[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%lld", &a[i]);
    }
    if (n == 1){
        printf("%d %d\n", 1, 1);
        printf("%lld\n", -a[0]);
        printf("%d %d\n", 1, 1);
        printf("%d\n", 0);
        printf("%d %d\n", 1, 1);
        printf("%d\n", 0);
        return 0;
    }
    printf("%d %d\n", 1, n - 1);
    for (int i = 0; i < n - 1; ++ i){
        ll num = (a[i] % n + n) % n;
        ll add = num * (n - 1);
        printf("%lld%c", add, " \n"[i == n - 2]);
        a[i] += add;
    }
    printf("%d %d\n", n, n);
    printf("%lld\n", n - a[n - 1]);
    a[n - 1] = n;
    printf("%d %d\n", 1, n);
    for (int i = 0; i < n; ++ i){
        printf("%lld%c", -a[i], " \n"[i == n - 1]);
    }
    return 0;
}