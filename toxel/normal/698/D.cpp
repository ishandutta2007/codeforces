#include<bits/stdc++.h>

typedef std::pair <int, int> pii;
typedef long long ll;
const int N = 1010;
const int M = 10;

pii operator +(const pii &p1, const pii &p2){
    return {p1.first + p2.first, p1.second + p2.second};
}

pii operator -(const pii &p1, const pii &p2){
    return {p1.first - p2.first, p1.second - p2.second};
}

ll operator ^(const pii &p1, const pii &p2){
    return 1ll * p1.first * p2.second - 1ll * p1.second * p2.first;
}

ll operator %(const pii &p1, const pii &p2){
    return 1ll * p1.first * p2.first + 1ll * p1.second * p2.second;
}

bool onWay(pii stone, pii p1, pii p2){
    return !((p1 - stone) ^ (p2 - stone)) && ((p1 - stone) % (p2 - p1)) > 0;
}

pii bear[N], stone[M];
std::vector <int> vec[N][M];
bool vis[N], shoot[N];
int k, n;

bool dfs(int now, int id, std::vector <int> toshoot){
    std::set <int> set;
    for (auto u : toshoot){
        if (!shoot[u]){
            set.insert(u);
        }
    }
    set.erase(toshoot[0]);
    shoot[toshoot[0]] = true;
    for (auto u : vec[toshoot[0]][id]){
        if (!shoot[u]){
            set.insert(u);
        }
    }
    if (set.size() + now + 1 > k){
        shoot[toshoot[0]] = false;
        return false;
    }
    toshoot.clear();
    for (auto u : set){
        toshoot.push_back(u);
    }
    if (toshoot.empty()){
        return true;
    }
    for (int i = 0; i < k; ++ i){
        if (!vis[i]){
            vis[i] = true;
            if (dfs(now + 1, i, toshoot)){
                return true;
            }
            vis[i] = false;
        }
    }
    shoot[toshoot[0]] = false;
    return false;
}

bool solve(int n){
    for (int i = 0; i < k; ++ i){
        memset(vis, 0, sizeof(vis));
        memset(shoot, 0, sizeof(shoot));
        vis[i] = true;
        if (dfs(0, i, {n})){
            return true;
        }
        vis[i] = false;
    }
    return false;
}

int main(){
    scanf("%d%d", &k, &n);
    for (int i = 0, x, y; i < k; ++ i){
        scanf("%d%d", &x, &y);
        stone[i] = {x, y};
    }
    for (int i = 0, x, y; i < n; ++ i){
        scanf("%d%d", &x, &y);
        bear[i] = {x, y};
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            if (i == j) continue;
            for (int kk = 0; kk < k; ++ kk){
                if (onWay(stone[kk], bear[j], bear[i])){
                    if (vec[i][kk].size() < k){
                        vec[i][kk].push_back(j);
                    }
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; ++ i){
        cnt += solve(i);
    }
    printf("%d\n", cnt);
    return 0;
}