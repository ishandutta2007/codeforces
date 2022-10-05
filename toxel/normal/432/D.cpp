#include <bits/stdc++.h>

const int N = 100010;

char s[N];
int zs[N], fail[N];
int cnt[N];

void ex_kmp(char *s, int *zs){
    int n = strlen(s);
    memset(zs, 0, sizeof(*zs) * n);
    for (int i = 1, l = 0, r = 0; i < n; ++ i){
        if (i <= r) zs[i] = std::min(zs[i - l], r - i + 1);
        while (i + zs[i] < n && s[i + zs[i]] == s[zs[i]]) ++ zs[i];
        if (i + zs[i] - 1 > r) l = i, r = i + zs[i] - 1;
    }
}

int main(){
    scanf("%s", s);
    int n = strlen(s);
    ex_kmp(s, zs);
    for (int i = 1; i < n; ++ i){
        if (i + zs[i] == n){
            -- zs[i];
        }
        ++ cnt[zs[i]];
    }
    for (int i = N - 1; i >= 0; -- i){
        cnt[i] += cnt[i + 1];
    }
    fail[0] = -1;
    for (int i = 0, j = -1; i < n; ++ i){
        while (j >= 0 && s[j] != s[i]) j = fail[j];
        fail[i + 1] = ++ j;
    }
    int now = fail[n];
    using pii = std::pair <int, int>;
    std::vector<pii> ans = {{n, 1}};
    while (now > 0){
        ans.emplace_back(now, cnt[now] + 2);
        now = fail[now];
    }
    std::reverse(ans.begin(), ans.end());
    printf("%d\n", int(ans.size()));
    for (auto u : ans){
        printf("%d %d\n", u.first, u.second);
    }
    return 0;
}