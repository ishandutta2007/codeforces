#include <bits/stdc++.h>

const int N = 6;

int a[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < N; ++ i){
        a[i] = n % 2;
        n /= 2;
    }
    std::swap(a[0], a[4]);
    std::swap(a[2], a[3]);
    int ans = 0;
    for (int i = N - 1; i >= 0; -- i){
        ans = ans * 2 + a[i];
    }
    printf("%d\n", ans);
    return 0;
}