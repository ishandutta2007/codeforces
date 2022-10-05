#include <bits/stdc++.h>

const int N = 200010;

char s[N], t[N], tmp[N];
int p[N];
bool vis[N];

int main(){
    scanf("%s%s", s, t);
    int n = strlen(s), m = strlen(t);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &p[i]);
        -- p[i];
    }
    int left = 0, right = n - m;
    while (left < right){
        int mid = (left + right + 1) / 2;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < mid; ++ i){
            vis[p[i]] = true;
        }
        int cnt = 0;
        for (int i = 0; i < n; ++ i){
            if (vis[i]){
                continue;
            }
            tmp[cnt ++] = s[i];
        }
        int match = 0;
        for (int i = 0; i < cnt && match < m; ++ match, ++ i){
            while (i < cnt && tmp[i] != t[match]){
                ++ i;
            }
            if (i == cnt){
                break;
            }
        }
        if (match == m){
            left = mid;
        }
        else{
            right = mid - 1;
        }
    }
    printf("%d\n", left);
    return 0;
}