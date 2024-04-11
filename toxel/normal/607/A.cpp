#include<bits/stdc++.h>

const int N = 100010;
typedef std::pair <int, int> pii;

int dp[N];
pii p[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0, a, b; i < n; ++ i){
        scanf("%d%d", &a, &b);
        p[i] = {a, b};
    }
    std::sort(p, p + n);
    int ans = 0;
    for (int i = 0; i < n; ++ i){
        int sit = std::lower_bound(p, p + n, (pii) {p[i].first - p[i].second, INT_MIN}) - p;
        if (!sit){
            dp[i] = 1;
        }
        else{
            dp[i] = dp[sit - 1] + 1;
        }
        ans = std::max(ans, dp[i]); 
    }
    printf("%d\n", n - ans);
    return 0;
}