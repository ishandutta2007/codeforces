#include<bits/stdc++.h>

const int N = 100010;

int ans[N];

int main(){
    int n;
    scanf("%d", &n);
    int min = INT_MAX, sit = 0;
    for (int i = 1; i <= n; ++ i){
        int value = i + (n + i - 1) / i;
        if (value < min){
            min = value;
            sit = i;
        }
    }
    for (int i = 0, j = 0, now = n; i < n; i = std::min(n - 1, i + sit - 1) + 1){
        for (j = std::min(n - 1, i + sit - 1); j >= i; -- j){
            ans[j] = now --;
        }
    }
    for (int i = 0; i < n; ++ i){
        printf("%d%c", ans[i], " \n"[i == n - 1]);
    }
    return 0;
}