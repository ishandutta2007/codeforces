#include <bits/stdc++.h>

const int N = 41;
using ll = long long;

int n, k;
ll mask[N];
int perm[N][N];
std::vector <int> update[N];
std::vector <int> sort[N];

void no(){
    puts("REJECTED");
    exit(0);
}

void dfs(int id){
    if (id == k){
        for (int i = 0; i < n - 1; ++ i){
            if (perm[id - 1][i] > perm[id - 1][i + 1]){
                no();
            }
        }
        return;
    }
    int sz = update[id].size();
    int sz1 = sort[id].size();
    for (int i = 0; i <= sz; ++ i){
        if (id > 0){
            memcpy(perm[id], perm[id - 1], sizeof(perm[0]));
        }
        for (int j = 0; j < sz; ++ j){
            perm[id][update[id][j]] = j < i ? 1 : 0;
        }
        int cnt = 0;
        for (int j = 0; j < sz1; ++ j){
            cnt += perm[id][sort[id][j]];
        }
        for (int j = 0; j < sz1; ++ j){
            perm[id][sort[id][j]] = j < sz1 - cnt ? 0 : 1;
        }
        dfs(id + 1);
    }
}

int main(){
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; ++ i){
        int num;
        scanf("%d", &num);
        mask[i] = 0;
        for (int j = 0; j < num; ++ j){
            int x;
            scanf("%d", &x);
            -- x;
            mask[i] |= 1ll << x;
        }
        if (num == 1){
            -- i;
            -- k;
        }
    }
    if (n == 1){
        puts("ACCEPTED");
        return 0;
    }
    ll sum = 0;
    for (int i = 0; i < k; ++ i){
        sum |= mask[i];
    }
    if (sum != (1ll << n) - 1){
        no();
    }
    ll cur = 0;
    for (int i = 0; i < k; ++ i){
        ll to_update = mask[i] & ~cur;
        for (int j = 0; j < n; ++ j){
            if (to_update >> j & 1){
                update[i].emplace_back(j);
            }
            if (mask[i] >> j & 1){
                sort[i].emplace_back(j);
            }
        }
        cur |= mask[i];
    }
    dfs(0);
    puts("ACCEPTED");
    return 0;
}