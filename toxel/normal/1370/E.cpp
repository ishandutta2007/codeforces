#include <bits/stdc++.h>

const int N = 1000010;

char s[N], t[N], tmp[N];
int cnt[N];

int main(){
    int n;
    scanf("%d%s%s", &n, s, t);
    for (int i = 0; i < n; ++ i){
        ++ cnt[s[i]];
        -- cnt[t[i]];
    }
    if (cnt['0'] || cnt['1']){
        puts("-1");
        return 0;
    }
    int len = 0;
    for (int i = 0; i < n; ++ i){
        if (s[i] != t[i]){
            tmp[len ++] = s[i];
        }
    }
    /*for (int i = 0; i < len - 1; ++ i){
        if (tmp[i] != tmp[i + 1]){
            std::rotate(tmp, tmp + i + 1, tmp + len);
            break;
        }
    }*/
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < len; ++ i){
        if (tmp[i] == '0'){
            if (cnt2 > 0){
                -- cnt2;
            }
            ++ cnt1;
        }
        else{
            if (cnt1 > 0){
                -- cnt1;
            }
            ++ cnt2;
        }
    }
    printf("%d\n", cnt1 + cnt2);
    return 0;
}