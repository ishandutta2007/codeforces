#include <bits/stdc++.h>

using ll = long long;

const int N = 500010;
int a[N];
ll pre[N];
int max[N];

ll calc(int pos, int len){
    return pre[pos + len - 1] - pre[pos - 1];
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= (n + 1) / 2; ++ i){
        scanf("%d", &a[i]);
    }
    int x;
    scanf("%d", &x);
    for (int i = (n + 1) / 2 + 1; i <= n; ++ i){
        a[i] = x;
    }
    for (int i = 1; i <= n; ++ i){
        pre[i] = pre[i - 1] + a[i];
    }
    if (x >= 0){
        if (pre[n] > 0){
            printf("%d\n", n);
        }
        else{
            puts("-1");
        }
        return 0;
    }
    for (int i = 1; i <= (n + 1) / 2; ++ i){
        int left = n / 2, right = n - i + 1;
        while (left < right){
            int mid = (left + right + 1) / 2;
            if (calc(i, mid) <= 0){
                right = mid - 1;
            }
            else{
                left = mid;
            }
        }
        max[i] = left;
    }
    int min = INT_MAX;
    for (int ans = n; ans >= n / 2 + 1; -- ans){
        min = std::min(min, max[n + 1 - ans]);
        if (min >= ans){
            printf("%d\n", ans);
            return 0;
        }
    }
    puts("-1");
    return 0;
}