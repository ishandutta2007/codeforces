#include <bits/stdc++.h>

const int N = 300010;

int a[N];
int left[N], right[N];
int c[N];
int num[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        c[i] = a[i];
        left[i] = INT_MAX;
        right[i] = -1;
    }
    std::sort(c, c + n);
    int cnt = std::unique(c, c + n) - c;
    for (int i = 0; i < n; ++ i){
        a[i] = std::lower_bound(c, c + cnt, a[i]) - c;
        left[a[i]] = std::min(left[a[i]], i);
        right[a[i]] = std::max(right[a[i]], i);
    }
    num[cnt - 1] = 1;
    for (int i = cnt - 2; i >= 0; -- i){
        if (right[i] < left[i + 1]){
            num[i] = num[i + 1] + 1;
        }
        else{
            num[i] = 1;
        }
    }
    int max = 0;
    for (int i = 0; i < cnt; ++ i){
        max = std::max(max, num[i]);
    }
    printf("%d\n", cnt - max);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}