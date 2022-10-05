#include <bits/stdc++.h>

const int N = 60;

int a[N];

int main(){
    int n;
    scanf("%d", &n);
    int min = INT_MAX;
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        min = std::min(min, a[i]);
    }
    int cnt = 0;
    for (int i = 0; i < n; ++ i){
        a[i] -= min;
        cnt += a[i] > 0;
    }
    if (cnt >= n / 2){
        puts("Alice");
    }
    else{
        puts("Bob");
    }
    return 0;
}