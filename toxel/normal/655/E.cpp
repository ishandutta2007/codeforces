#include<bits/stdc++.h>

const int N = 1000010;
const int M = 30;
const int moder = (int) 1e9 + 7;
typedef std::pair <int, int> pii;

char s[N];
int dp[M], rank[M];
pii p[M];

inline void add(int &a, int b){a += b; a -= a >= moder ? moder : 0;}

int main(){
    int n, k;
    scanf("%d%d%s", &n, &k, s);
    int m = strlen(s);
    int nowrank = 0;
    for (int i = 0; i < m; ++ i){
        add(dp[s[i] - 'a'], 1);
        for (int j = 0; j < k; ++ j){
            if (j == s[i] - 'a') continue;
            add(dp[s[i] - 'a'], dp[j]);
        }
        rank[s[i] - 'a'] = ++ nowrank;
    }
    for (int i = 0; i < k; ++ i){
        p[i] = {rank[i], i};
    }
    std::sort(p, p + k);
    for (int i = 0; i < n; ++ i){
        int now = p[i % k].second;
        add(dp[now], 1);
        for (int j = 0; j < k; ++ j){
            if (j == now) continue;
            add(dp[now], dp[j]);
        }
    }
    int ans = 1;
    for (int i = 0; i < k; ++ i){
        add(ans, dp[i]);
    }
    printf("%d\n", ans);
    return 0;
}