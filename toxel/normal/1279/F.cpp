#include <bits/stdc++.h>

const int N = 1000010;
using ll = long long;

char s[N];
ll dp[N], cnt[N];
int a[N];

void calc(int n, int l, int mid){
    for (int i = 1; i <= n; ++ i){
        dp[i] = dp[i - 1] + (a[i - 1] == 1);
        cnt[i] = cnt[i - 1];
        ll value = (i - l <= 0 ? 0 : dp[i - l]) - mid;
        ll ncnt = (i - l <= 0 ? 0 : cnt[i - l]) + 1;
        if (value < dp[i]){
            dp[i] = value;
            cnt[i] = ncnt;
        }
        else if (value == dp[i]){
            cnt[i] = std::min(cnt[i], ncnt);
        }
    }
}

int solve(int n, int k, int l){
    int left = -n - 10, right = 0;
    while (left < right){
        int mid = (left + right + 1) >> 1;
        calc(n, l, mid);
        if (cnt[n] > k){
            right = mid - 1;
        }
        else{
            left = mid;
        }
    }
    calc(n, l, left);
    return dp[n] + 1ll * left * k;
}

int main(){
    int n, k, l;
    scanf("%d%d%d", &n, &k, &l);
    scanf("%s", s);
    for (int i = 0; i < n; ++ i){
        a[i] = isupper(s[i]) != 0;
    }
    int ans = solve(n, k, l);
    for (int i = 0; i < n; ++ i){
        a[i] = islower(s[i]) != 0;
    }
    ans = std::min(solve(n, k, l), ans);
    printf("%d\n", ans);
    return 0;
}