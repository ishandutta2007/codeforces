#include <bits/stdc++.h>

const int N = 300010;

int a[N];
int ans[N];
std::deque<int> pos[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n; ++ i){
        a[i] = ans[i] = 0;
        pos[i].clear();
    }
    ans[1] = 1;
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        pos[a[i]].emplace_back(i);
    }
    for (int i = 1; i <= n; ++ i){
        if (int(pos[i].size()) != 1){
            ans[1] = 0;
        }
    }
    int curl = 1, curr = n;
    for (int i = n; i >= 2; -- i){
        int value = n + 1 - i;
        if (int(pos[value].size()) == 0){
            break;
        }
        ans[i] = 1;
        if (int(pos[value].size()) > 1){
            break;
        }
        if (pos[value][0] == curl){
            ++ curl;
        }
        else if (pos[value][0] == curr){
            -- curr;
        }
        else{
            break;
        }
    }
    for (int i = 1; i <= n; ++ i){
        printf("%d", ans[i]);
    }
    puts("");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}