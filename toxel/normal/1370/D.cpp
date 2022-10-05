#include <bits/stdc++.h>

const int N = 200010;

int a[N], c[N];
int dp[N][2];

void update(int &u, int v, int w){
    u = std::max(u, v + w);
}

bool check(int value, int n, int k){
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++ i){
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = dp[i - 1][1];
        if (a[i] > value){
            update(dp[i][1], dp[i - 1][0], 1);
        }
        else{
            update(dp[i][1], dp[i - 1][0], 1);
            update(dp[i][0], dp[i - 1][1], 1);
        }
    }
    return std::max(dp[n][0], dp[n][1]) >= k;
}

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        c[i] = a[i];
    }
    std::sort(c + 1, c + 1 + n);
    int cnt = std::unique(c + 1, c + 1 + n) - c;
    int left = 1, right = cnt - 1;
    while (left < right){
        int mid = (left + right) / 2;
        if (check(c[mid], n, k)){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    printf("%d\n", c[left]);
    return 0;
}