#include<bits/stdc++.h>

const int N = 110;

int s[N], cnt[N], ccnt[N];
int ans[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &s[i]);
        ++ cnt[s[i]];
    }
    for (int i = 0; i < N; ++ i){
        ++ ccnt[std::min(cnt[i], 3)];
    }
    if ((ccnt[1] & 1) && !ccnt[3]){
        puts("NO");
        return 0;
    }
    bool flag = ccnt[1] & 1;
    int now = 0;
    for (int i = 0; i < N; ++ i){
        if (cnt[i] >= 2){
            if (flag && cnt[i] >= 3){
                bool first = true;
                for (int j = 0; j < n; ++ j){
                    if (s[j] == i){
                        ans[j] = first;
                        first = false;
                    }
                }
                flag = false;
            }
            else{
                for (int j = 0; j < n; ++ j){
                    if (s[j] == i){
                        ans[j] = 1;
                    }
                }
            }
        }
        else if (cnt[i] == 1){
            for (int j = 0; j < n; ++ j){
                if (s[j] == i){
                    ans[j] = now;
                }
            }
            now ^= 1;
        }
    }
    puts("YES");
    for (int i = 0; i < n; ++ i){
        putchar('A' + ans[i]);
    }
    putchar('\n');
    return 0;
}