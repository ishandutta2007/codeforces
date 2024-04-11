#include <bits/stdc++.h>

const int N = 5010;
const int M = 1 << 20;
const int K = 30;

char s[N];
int vis[K];
bool dp[M];
int cnt[K], l[K], r[K];

int main(){
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    scanf("%s", s);
    memset(vis, -1, sizeof(vis));
    int id = 0;
    for (int i = 0; i < n; ++ i){
        if (vis[s[i] - 'a'] != -1){
            continue;
        }
        vis[s[i] - 'a'] = id;
        l[id] = i;
        for (int j = i; j < n; ++ j){
            if (s[j] == s[i]){
                r[id] = j;
                ++ cnt[id];
            }
        }
        if (1ll * a * (r[id] - l[id] + 1) <= 1ll * cnt[id] * b){
            dp[1 << id] = true;
        }
        ++ id;
    }
    for (int i = 3; i < (1 << id) - 1; ++ i){
        if (__builtin_popcount(i) <= 1){
            continue;
        }
        for (int j = 1; j < id; ++ j){
            int x = i & ((1 << j) - 1);
            int y = i ^ x;
            if (x < i && y < i){
                if (dp[x] && dp[y]){
                    dp[i] = true;
                    break;
                }
            }
        }
        if (dp[i]){
            continue;
        }
        int left = INT_MAX, right = INT_MIN;
        int ccnt = 0;
        for (int j = 0; j < id; ++ j){
            if (i >> j & 1){
                left = std::min(left, l[j]);
                right = std::max(right, r[j]);
                ccnt += cnt[j];
            }
        }
        if (1ll * a * (right - left + 1) <= 1ll * ccnt * b){
            for (int j = 0; j < id; ++ j){
                if (i >> j & 1){
                    if (dp[i ^ 1 << j]){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
    }
    dp[0] = true;
    std::vector <char> ans;
    for (int i = 0; i < 26; ++ i){
        if (vis[i] == -1){
            continue;
        }
        if (dp[((1 << id) - 1) ^ (1 << vis[i])]){
            ans.emplace_back('a' + i);
        }
    }
    printf("%d", int(ans.size()));
    for (auto u : ans){
        printf(" %c", u);
    }
    puts("");
    return 0;
}