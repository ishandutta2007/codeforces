#include <bits/stdc++.h>

const int N = 1010;

int ask(std::vector<int> vec){
    printf("? %d", int(vec.size()));
    for (auto u : vec){
        printf(" %d", u);
    }
    puts("");
    fflush(stdout);
    int x;
    scanf("%d", &x);
    if (x == -1){
        exit(0);
    }
    return x;
}

int ask(int l, int r){
    std::vector<int> vec;
    for (int i = l; i <= r; ++ i){
        vec.emplace_back(i);
    }
    return ask(vec);
}

std::vector<int> vec[N];

int solve(int l, int r, int max){
    if (l == r){
        return l;
    }
    int mid = (l + r) / 2;
    if (ask(l, mid) == max){
        return solve(l, mid, max);
    }
    return solve(mid + 1, r, max);
}

void solve(){
    for (int i = 0; i < N; ++ i){
        vec[i].clear();
    }
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; ++ i){
        int x;
        scanf("%d", &x);
        for (int j = 0; j < x; ++ j){
            int y;
            scanf("%d", &y);
            vec[i].emplace_back(y);
        }
    }
    int max = ask(1, n);
    int result = solve(1, n, max);
    std::vector<int> ans(k);
    for (int i = 0; i < k; ++ i){
        bool flag = true;
        for (auto u : vec[i]){
            if (u == result){
                flag = false;
                break;
            }
        }
        if (flag){
            ans[i] = max;
        }
        else{
            std::vector<bool> vis(n + 1);
            for (auto u : vec[i]){
                vis[u] = true;
            }
            std::vector<int> vec1;
            for (int j = 1; j <= n; ++ j){
                if (!vis[j]){
                    vec1.emplace_back(j);
                }
            }
            ans[i] = ask(vec1);
        }
    }
    printf("!");
    for (auto u : ans){
        printf(" %d", u);
    }
    puts("");
    fflush(stdout);
    char s[100];
    scanf("%s", s);
    if (strcmp(s, "Correct") != 0){
        exit(0);
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