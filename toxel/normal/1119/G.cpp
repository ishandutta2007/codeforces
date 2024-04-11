#include <bits/stdc++.h>

const int N = 2000010;
typedef std::pair <int, int> pii;

int hp[N];
int a[N];
std::vector <int> e[N];
int b[N];

void dfs(int u, int id){
    if (e[u].size() == 0){
        b[u] = id;
    }
    for (auto v : e[u]){
        dfs(v, id);
    }
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++ i){
        scanf("%d", &hp[i]);
    }
    int nowp = 0;
    a[nowp] = n;
    std::vector <int> vec = {nowp};
    std::vector <std::vector <pii>> ans;
    for (int i = 0; i < m; ++ i){
        while (hp[i] >= n){
            std::vector <pii> vvec;
            for (auto u : vec){
                vvec.push_back({u, i});
            }
            ans.push_back(vvec);
            hp[i] -= n;
        }
        if (hp[i] > 0){
            std::vector <int> nvec;
            std::vector <pii> vvec;
            for (int j = 0; j < (int) vec.size(); ++ j){
                int u = vec[j];
                if (hp[i] == 0){
                    if (i == m - 1){
                        for (int k = j; k < (int) vec.size(); ++ k){
                            nvec.push_back(vec[k]);
                        }
                        break;
                    }
                    ++ i;
                }
                if (hp[i] >= a[u] || i == m - 1){
                    hp[i] -= a[u];
                    vvec.push_back({u, i});
                    nvec.push_back(u);
                }
                else{
                    e[u].push_back(++ nowp);
                    e[u].push_back(++ nowp);
                    a[nowp - 1] = hp[i];
                    a[nowp] = a[u] - hp[i];
                    vvec.push_back({nowp - 1, i});
                    vec.push_back(nowp);
                    nvec.push_back(nowp - 1);
                    hp[i] = 0;
                }
            }
            if (hp[i] > 0){
                -- i;
            }
            vec = nvec;
            ans.push_back(vvec);
        }
    }
    printf("%d\n", (int) ans.size());
    for (auto u : vec){
        printf("%d ", a[u]);
    }
    for (int i = 0; i < m - (int) vec.size(); ++ i){
        printf("%d ", 0);
    }
    puts("");
    for (auto u : ans){
        for (auto v : vec){
            b[v] = 0;
        }
        for (auto v : u){
            dfs(v.first, v.second);
        }
        for (auto v : vec){
            printf("%d ", b[v] + 1);
        }
        for (int i = 0; i < m - (int) vec.size(); ++ i){
            printf("%d ", 1);
        }
        puts("");
    }
    return 0;
}