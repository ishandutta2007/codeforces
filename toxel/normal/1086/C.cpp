#include<bits/stdc++.h>

const int N = 1000010;
const int M = 30;

char a[N], b[N], s[N];
int id[M];
bool vis[M];
int n, k;
bool flag;

void dfs(int now, bool big, bool small){
    if (now == n){
        flag = true;
        return;
    }
    int left = big ? a[now] - 'a' : 0;
    int right = small ? b[now] - 'a' : k - 1;
    int lleft = left, rright = right;
    if (id[s[now] - 'a'] != -1){
        int x = id[s[now] - 'a'];
        left = std::max(left, x);
        right = std::min(right, x);
    }
    for (int i = left; i <= right; ++ i){
        if (vis[i] && id[s[now] - 'a'] != i) continue;
        int nbig = big, nsmall = small;
        if (i > lleft){
            nbig = false;
        }
        if (i < rright){
            nsmall = false;
        }

        bool flag1 = !vis[i];
        if (flag1){
            id[s[now] - 'a'] = i;
            vis[i] = true;
        }
        dfs(now + 1, nbig, nsmall);
        if (flag){
            return;
        }
        if (flag1){
            id[s[now] - 'a'] = -1;
            vis[i] = false;
        }
    }
}

void solve(){
    scanf("%d%s%s%s", &k, s, a, b);
    n = strlen(s);
    flag = false;
    memset(id, -1, sizeof(id));
    memset(vis, 0, sizeof(vis));
    dfs(0, true, true);
    if (!flag){
        puts("NO");
        return;
    }
    puts("YES");
    for (int i = 0; i < k; ++ i){
        if (id[i] == -1){
            for (int j = 0; j < k; ++ j){
                if (!vis[j]){
                    id[i] = j;
                    vis[j] = true;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < k; ++ i){
        putchar(id[i] + 'a');
    }
    putchar('\n');
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}