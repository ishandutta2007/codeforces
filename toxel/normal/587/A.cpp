#include<bits/stdc++.h>

const int N = 10000100;

int cnt[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0, x; i < n; ++ i){
        scanf("%d", &x);
        ++ cnt[x];
    }
    for (int i = 0; i < N - 1; ++ i){
        cnt[i + 1] += cnt[i] >> 1;
        cnt[i] &= 1;
    }
    int ans = 0;
    for (int i = 0; i < N; ++ i){
        ans += cnt[i];
    }
    printf("%d\n", ans);
    return 0;
}