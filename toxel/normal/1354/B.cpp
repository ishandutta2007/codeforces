#include <bits/stdc++.h>

const int N = 200010;

char s[N];
int cnt[N];

void solve(){
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < 3; ++ i){
        cnt[i] = 0;
    }
    int min = INT_MAX;
    for (int i = 0, j = 0; i < n; ++ i){
        while (j < n && (!cnt[0] || !cnt[1] || !cnt[2])){
            ++ cnt[s[j] - '1'];
            ++ j;
        }
        if (cnt[0] && cnt[1] && cnt[2]){
            min = std::min(min, j - i);
        }
        -- cnt[s[i] - '1'];
    }
    if (min == INT_MAX){
        min = 0;
    }
    printf("%d\n", min);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}