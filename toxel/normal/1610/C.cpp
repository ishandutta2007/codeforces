#include <bits/stdc++.h>

const int N = 200010;

int a[N], b[N];

bool check(int n, int mid){
    int cnt = 0;
    for (int i = 1; i <= n; ++ i){
        if (a[i] + b[i] + 1 < mid){
            continue;
        }
        if (b[i] < mid - 1 - cnt){
            continue;
        }
        if (cnt > a[i]){
            continue;
        }
        ++ cnt;
    }
    return cnt >= mid;
}

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d%d", &b[i], &a[i]);
    }
    int left = 1, right = n;
    while (left < right){
        int mid = (left + right + 1) / 2;
        if (check(n, mid)){
            left = mid;
        }
        else{
            right = mid - 1;
        }
    }
    printf("%d\n", left);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}