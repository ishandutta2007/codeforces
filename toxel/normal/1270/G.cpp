#include <bits/stdc++.h>

const int N = 1000010;

int a[N];
std::vector <int> e[N];
std::vector <int> stack, ans;
bool instack[N];

void dfs(int u){
    instack[u] = true;
    stack.push_back(u);
    for (auto v : e[u]){
        if (instack[v]){
            ans.push_back(v);
            while (stack.back() != v){
                int x = stack.back();
                instack[x] = false;
                ans.push_back(x);
                stack.pop_back();
            }
            return;
        }
        dfs(v);
        if (!ans.empty()){
            return;
        }
    }
}

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        e[i].push_back(i - a[i]);
    }
    for (auto u : stack){
        instack[u] = false;
    }
    stack.clear();
    ans.clear();
    dfs(1);
    for (int i = 1; i <= n; ++ i){
        std::vector <int>().swap(e[i]);
    }
    int sz = ans.size();
    printf("%d\n", sz);
    for (int i = 0; i < sz; ++ i){
        printf("%d%c", ans[i], " \n"[i == sz - 1]);
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}