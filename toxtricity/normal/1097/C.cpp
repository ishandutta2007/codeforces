#include<bits/stdc++.h>

const int N = 500010;

int cnt[N << 1];
char s[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%s", s);
        int len = strlen(s);
        int cnt = 0;
        for (int j = 0; j < len; ++ j){
            cnt += s[j] == '(' ? 1 : -1;
        }
        int begin = cnt < 0 ? -cnt : 0;
        bool flag = true;
        for (int j = 0; j < len; ++ j){
            begin += s[j] == '(' ? 1 : -1;
            if (begin < 0){
                flag = false;
                break;
            }
        }
        if (flag){
            ++ ::cnt[N + cnt];
        }
    }
    int ans = 0;
    for (int i = 0; i < N; ++ i){
        ans += std::min(cnt[i], cnt[N + N - i]);
    }
    ans += cnt[N] >> 1;
    printf("%d\n", ans);
    return 0;
}