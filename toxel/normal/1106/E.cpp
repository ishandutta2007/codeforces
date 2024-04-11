#include<bits/stdc++.h>

typedef std::pair <int, int> pii;
typedef std::pair <pii, int> piii;
const int N = 100010;
const int M = 210;
typedef long long ll;

std::vector <pii> vec[N];
int id[N];
ll dp[N][M];
int s[N], t[N], d[N], w[N];

int main(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; ++ i){
        scanf("%d%d%d%d", &s[i], &t[i], &d[i], &w[i]);
        vec[s[i]].push_back({i, 1});
        vec[t[i] + 1].push_back({i, 0});
    }
    std::set <piii> set;
    for (int i = 1; i <= n; ++ i){
        for (auto u : vec[i]){
            int id = u.first;
            if (u.second){
                set.insert({{-w[id], -d[id]}, id});
            }
            else{
                set.erase({{-w[id], -d[id]}, id});
            }
        }
        if (set.empty()){
            id[i] = -1;
        }
        else{
            id[i] = set.begin() -> second;
        }
    }
    for (int i = n; i >= 1; -- i){
        for (int j = 0; j <= m; ++ j){
            dp[i][j] = dp[id[i] == -1 ? i + 1 : d[id[i]] + 1][j] + (id[i] == -1 ? 0 : w[id[i]]);
            if (!j) continue;
            dp[i][j] = std::min(dp[i][j], dp[i + 1][j - 1]);
        }
    }
    printf("%lld\n", dp[1][m]);
    return 0;
}