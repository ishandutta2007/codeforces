#include <bits/stdc++.h>

const int N = 200010;

void solve(){
    int n;
    scanf("%d", &n);
    std::vector<bool> vis(n);
    for (int i = 0; i < n; ++ i){
        int a;
        scanf("%d", &a);
        vis[((a + i) % n + n) % n] = true;
    }
    for (int i = 0; i < n; ++ i){
        if (!vis[i]){
            puts("NO");
            return;
        }
    }
    puts("YES");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}