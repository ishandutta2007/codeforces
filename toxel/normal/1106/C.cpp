#include<bits/stdc++.h>

const int N = 300010;

int a[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    std::sort(a, a + n);
    long long ans = 0;
    for (int i = 0; i < n >> 1; ++ i){
        int x = a[i] + a[n - 1 - i];
        ans += x * x;
    }
    printf("%lld\n", ans);
    return 0;
}