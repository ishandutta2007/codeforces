#include<bits/stdc++.h>

const int N = 200010;
const int M = 300;
const int K = 1 << 14;
typedef std::pair <int, int> pii;

int a[N], tmpa[N], b[N], diff[N], sum[N];
int ans[N];
std::vector <int> vec[N], offset[N];
std::vector <std::vector <int>> cnt[N], rollback[N];
std::vector <pii> blockconf[N];
char s[M];
int nonzero = 0, res = 0;
int n, k, q;

void solve(int sit, int v){
    int loc = sit % k;
    auto &a = vec[loc];
    res -= ans[loc];
    ans[loc] = 0;
    nonzero -= sum[loc] != 0;
    sum[loc] ^= v;
    nonzero += sum[loc] != 0;
    sit /= k;
    int block = sit / M;
    for (int i = 0; i < block; ++ i){
        ans[loc] += cnt[loc][i][offset[loc][i]];
    }
    for (int i = block, sz = offset[loc].size(); i < sz; ++ i){
        if (i == block || i >= (int) cnt[loc].size()){
            pii p = blockconf[loc][i];
            for (int j = p.first; j <= p.second; ++ j){
                a[j] ^= offset[loc][i];
            }
            offset[loc][i] = 0;
            for (int j = std::max(p.first, sit); j <= p.second; ++ j){
                a[j] ^= v;
            }
            if (i < (int) cnt[loc].size()){
                for (auto u : rollback[loc][i]){
                    cnt[loc][i][u] = 0;
                }
                rollback[loc][i].clear();
                for (int j = p.first; j <= p.second; ++ j){
                    ++ cnt[loc][i][a[j]];
                    rollback[loc][i].push_back(a[j]);
                }
            }
            for (int j = p.first; j <= p.second; ++ j){
                ans[loc] += a[j] == 0;
            }
            continue;
        }
        offset[loc][i] ^= v;
        ans[loc] += cnt[loc][i][offset[loc][i]];
    }
    ans[loc] = a.size() - ans[loc];
    res += ans[loc];
}

int main(){
    scanf("%d%d%d", &n, &k, &q);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        tmpa[i] = a[i];
    }
    for (int i = 0; i < n; ++ i){
        scanf("%d", &b[i]);
        a[i] ^= b[i];
    }
    diff[0] = a[0];
    for (int i = 1; i <= n; ++ i){
        diff[i] = a[i] ^ a[i - 1];
    }
    for (int i = 0; i <= n; ++ i){
        vec[i % k].push_back(diff[i]);
        sum[i % k] ^= diff[i];
    }
    for (int i = 0; i < k; ++ i){
        nonzero += sum[i] != 0;
        int sz = vec[i].size();
        for (int j = 1; j < sz; ++ j){
            vec[i][j] ^= vec[i][j - 1];
        }
        for (int j = 0; j < sz; ++ j){
            ans[i] += vec[i][j] != 0;
        }
        res += ans[i];
        for (int j = 0; j < sz; j += M){
            if (j + M > sz){
                blockconf[i].push_back({j, sz - 1});
                offset[i].push_back(0);
            }
            else{
                blockconf[i].push_back({j, j + M - 1});
                offset[i].push_back(0);
                cnt[i].push_back(std::vector <int>(K));
                rollback[i].push_back(std::vector <int>());
                for (int k = j; k <= j + M - 1; ++ k){
                   ++ cnt[i].back()[vec[i][k]];
                   rollback[i].back().push_back(vec[i][k]);
                }
            }
        }
    }
    printf("%d\n", nonzero ? -1 : res);
    while (q --){
        int p, v;
        scanf("%s%d%d", s, &p, &v);
        int &x = s[0] == 'a' ? tmpa[p - 1] : b[p - 1];
        solve(p - 1, v ^ x), solve(p, v ^ x);
        x = v;
        printf("%d\n", nonzero ? -1 : res);
    }
    return 0;
}