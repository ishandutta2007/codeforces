#include <bits/stdc++.h>

const int N = 200010;

int a[N], pre[N];
int max1[N], max2[N];

void solve(){
    memset(max1, -1, sizeof(max1));
    memset(max2, -1, sizeof(max2));
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++ i){
        pre[i] = pre[i - 1] + (a[i] == 1 ? 1 : -1);
    }
    for (int i = 0; i <= n; ++ i){
        int &u = max1[pre[i] + n];
        u = std::max(u, i);
    }
    std::reverse(a + 1, a + 2 * n + 1);
    for (int i = 1; i <= n; ++ i){
        pre[i] = pre[i - 1] + (a[i] == 1 ? 1 : -1);
    }
    for (int i = 0; i <= n; ++ i){
        int &u = max2[pre[i] + n];
        u = std::max(u, i);
    }
    int ans = 0;
    for (int i = -n; i <= n; ++ i){
        if (max1[i + n] == -1 || max2[-i + n] == -1){
            continue;
        }
        ans = std::max(ans, max1[i + n] + max2[-i + n]);
    }
    printf("%d\n", 2 * n - ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
}