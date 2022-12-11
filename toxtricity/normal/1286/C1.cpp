#include <bits/stdc++.h>

const int N = 210;

char tmp[N];
int cnt[N][N], cnt1[N];

std::string ask(int l, int r){
    memset(cnt, 0, sizeof(cnt));
    printf("? %d %d\n", l, r);
    fflush(stdout);
    int n = r - l + 1;
    for (int i = 0; i < n * (n + 1) / 2; ++ i){
        scanf("%s", tmp);
        int len = strlen(tmp);
        for (int j = 0; j < len; ++ j){
            ++ cnt[len][tmp[j]];
        }
    }
    for (int i = N - 1; i >= 2; -- i){
        for (int j = 0; j < N; ++ j){
            cnt[i][j] -= cnt[i - 1][j];
        }
    }
    memset(tmp, 0, sizeof(tmp));
    for (int i = 1; i < N - 1; ++ i){
        for (int j = 0; j < N; ++ j){
            cnt[i][j] -= cnt[i + 1][j];
        }
    }
    for (int i = 1; i <= (n + 1) / 2; ++ i){
        int pos1 = i - 1, pos2 = n - i;
        for (int j = 0; j < N; ++ j){
            if (cnt[i][j] == 2){
                tmp[pos1] = tmp[pos2] = j;
            }
            else if (cnt[i][j] == 1){
                if (tmp[pos1] == '\0'){
                    tmp[pos1] = j;
                }
                else{
                    tmp[pos2] = j;
                }
            }
        }
    }
    return tmp;
}

int main(){
    int n;
    scanf("%d", &n);
    std::string ans = ask(1, n);
    if (n == 1){
        printf("! %s\n", ans.c_str());
        return 0;
    }
    std::string ans1 = ask(1, n - 1);
    memset(tmp, 0, sizeof(tmp));
    for (auto u : ans){
        ++ cnt1[u];
    }
    for (auto u : ans1){
        -- cnt1[u];
    }
    for (int i = 0; i < N; ++ i){
        if (cnt1[i]){
            tmp[n - 1] = i;
        }
    }
    for (int i = 0, j = n - 2; i <= j; ++ i, -- j){
        tmp[i] = ans[i] ^ ans[n - 1 - i] ^ tmp[n - 1 - i];
        if (i < j){
            tmp[j] = ans1[j] ^ ans1[n - 2 - j] ^ tmp[n - 2 - j];
        }
    }
    printf("! %s\n", tmp);
    return 0;
}