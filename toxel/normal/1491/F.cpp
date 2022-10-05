#include <bits/stdc++.h>

const int N = 2010;

bool vis[N];

int ask(int l1, int r1, int l2, int r2){
    printf("? %d %d\n", r1 - l1 + 1, r2 - l2 + 1);
    for (int i = l1; i <= r1; ++ i){
        printf("%d%c", i, " \n"[i == r1]);
    }
    for (int i = l2; i <= r2; ++ i){
        printf("%d%c", i, " \n"[i == r2]);
    }
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret;
}

void solve(){
    memset(vis, 0, sizeof(vis));
    int n;
    scanf("%d", &n);
    int second = -1;
    for (int i = 1; i < n; ++ i){
        int result = ask(1, i, i + 1, i + 1);
        if (result != 0){
            second = i + 1;
            break;
        }
    }
    vis[second] = true;
    for (int i = second + 1; i <= n; ++ i){
        int result = ask(second, second, i, i);
        if (result != 0){
            vis[i] = true;
        }
    }
    int left = 1, right = second - 1;
    while (left < right){
        int mid = (left + right) / 2;
        if (ask(left, mid, second, second) != 0){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    vis[left] = true;
    int sz = 0;
    for (int i = 1; i <= n; ++ i){
        sz += !vis[i];
    }
    printf("! %d", sz);
    for (int i = 1; i <= n; ++ i){
        if (!vis[i]){
            printf(" %d", i);
        }
    }
    puts("");
    fflush(stdout);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}