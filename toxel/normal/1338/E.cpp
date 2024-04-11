#include <bits/stdc++.h>

const int N = 8010;
using ll = long long;

char s[N][N];
bool mat[N][N];
int deg[N], type[N], deg1[N];

int main(){
    int n;
    scanf("%d", &n);
    fgets(s[0], N, stdin);
    for (int i = 0; i < n; ++ i){
        fgets(s[i], N, stdin);
        s[i][n / 4] = '\0';
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n / 4; ++ j){
            int value;
            if (isupper(s[i][j])){
                value = s[i][j] - 'A' + 10;
            }
            else{
                value = s[i][j] - '0';
            }
            for (int k = 3; k >= 0; -- k){
                mat[i][4 * j + 3 - k] = value >> k & 1;
            }
        }
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            deg[j] += mat[i][j];
        }
    }
    ll ans = 0, curn = n;
    while (true){
        bool flag = true;
        for (int i = 0; i < n; ++ i){
            if (type[i] != -1 && deg[i] == 0){
                ans += curn - 1;
                ans += 614 * n * (curn - 1);
                -- curn;
                flag = false;
                type[i] = -1;
                for (int j = 0; j < n; ++ j){
                    if (mat[i][j]){
                        -- deg[j];
                    }
                }
            }
        }
        if (flag){
            break;
        }
    }
    if (curn == 0){
        printf("%lld\n", ans);
        return 0;
    }
    int pos = -1, max = 0;
    for (int i = 0; i < n; ++ i){
        if (type[i] != -1 && deg[i] > max){
            max = deg[i];
            pos = i;
        }
    }
    type[pos] = 0;
    for (int i = 0; i < n; ++ i){
        if (type[i] == -1 || i == pos){
            continue;
        }
        if (mat[i][pos]){
            type[i] = 0;
        }
        else{
            type[i] = 1;
        }
    }
    for (int i = 0; i < n; ++ i){
        if (type[i] == -1){
            continue;
        }
        for (int j = 0; j < n; ++ j){
            if (type[i] == type[j]){
                deg1[i] += mat[j][i];
            }
        }
    }
    std::vector<int> vec[2];
    for (int i = 0; i < n; ++ i){
        if (type[i] != -1){
            vec[type[i]].emplace_back(i);
        }
    }
    ans += vec[0].size() * vec[1].size() * 3;
    auto solve = [&](const std::vector<int> &vec){
        int sz = vec.size();
        ans += sz * (sz - 1) / 2;
        for (int i = 0; i < sz; ++ i){
            for (int j = i + 1; j < sz; ++ j){
                int u = vec[i], v = vec[j];
                ans += deg[u] - deg1[u] == deg[v] - deg1[v] ? 3 : 2;
            }
        }
    };
    solve(vec[0]);
    solve(vec[1]);
    printf("%lld\n", ans);
    return 0;
}