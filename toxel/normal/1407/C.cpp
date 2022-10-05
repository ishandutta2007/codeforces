#include <bits/stdc++.h>

const int N = 10010;

int query(int a, int b){
    printf("? %d %d\n", a, b);
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret;
}

int ans[N];
bool vis[N];

int main(){
    int n;
    scanf("%d", &n);
    int uncertain = 1;
    for (int i = 2; i <= n; ++ i){
        int first = query(uncertain, i);
        int second = query(i, uncertain);
        if (first > second){
            ans[uncertain] = first;
            uncertain = i;
        }
        else{
            ans[i] = second;
        }
    }
    for (int i = 1; i <= n; ++ i){
        if (ans[i]){
            vis[ans[i]] = true;
        }
    }
    for (int i = 1; i <= n; ++ i){
        if (!vis[i]){
            ans[uncertain] = i;
            break;
        }
    }
    putchar('!');
    for (int i = 1; i <= n; ++ i){
        printf(" %d", ans[i]);
    }
    puts("");
    return 0;
}