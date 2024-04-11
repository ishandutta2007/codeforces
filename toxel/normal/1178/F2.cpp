#include <bits/stdc++.h>

const int N = 1010;
const int M = 1000010;
const int moder = 998244353;
const int BIT = 21;

int a[M];
int st[M][BIT], bitcount[M];
std::vector <int> vec[N];
int begin[N], end[N];
std::map <int, int> dp[M];

struct P{
    int pos;
    bool type;

    bool operator <(const P &p)const{
        return pos == p.pos ? type > p.type : pos < p.pos;
    }
};

std::vector <P> posvec;

int getst(int l, int r){
    assert(l <= r && l >= 0);
    int bt = bitcount[r - l + 1];
    return std::min(st[l][bt], st[r - (1 << bt) + 1][bt]);
}

int dfs(int l, int r){
    if (l > r){
        return 1;
    }
    if (dp[l].count(r)){
        return dp[l][r];
    }
    int min = getst(l, r);
    int prod = 1;
    for (int i = 0, sz = vec[min].size(); i < sz - 1; ++ i){
        prod = 1ll * prod * dfs(vec[min][i] + 1, vec[min][i + 1] - 1) % moder;
    }
    int prod1 = dfs(vec[min].back() + 1, r);
    auto u = std::lower_bound(posvec.begin(), posvec.end(), (P){vec[min].back() + 1, true});
    int now = 0;
    while (true){
        if (!now){
            if (u == posvec.end() || u -> pos > r) {
                break;
            }
            prod1 = (prod1 + 1ll * dfs(vec[min].back() + 1, u -> pos - 1) * dfs(u -> pos, r)) % moder;
        }
        assert(now >= 0);
        now += u -> type ? 1 : -1;
        ++ u;
    }
    int prod2 = dfs(l, vec[min][0] - 1);
    u = std::upper_bound(posvec.begin(), posvec.end(), (P){vec[min][0] - 1, false});
    if (u != posvec.begin()) {
        now = 0;
        -- u;
        while (true) {
            if (!now){
                if (u -> pos < l){
                    break;
                }
                prod2 = (prod2 + 1ll * dfs(l, u -> pos) * dfs(u -> pos + 1, vec[min][0] - 1)) % moder;
            }
            assert(now <= 0);
            now += u -> type ? 1 : -1;
            if (u == posvec.begin()){
                break;
            }
            -- u;
        }
    }
    int ans = 1ll * prod * prod1 % moder * prod2 % moder;
    dp[l][r] = ans;
    return ans;
}

int main(){
    for (int i = 2; i < M; ++ i){
        bitcount[i] = bitcount[i >> 1] + 1;
    }
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++ i){
        scanf("%d", &a[i]);
        -- a[i];
        if (i && a[i] == a[i - 1]){
            -- i, -- m;
        }
    }
    for (int i = 0; i < BIT; ++ i){
        for (int j = 0; j < m; ++ j){
            if (i == 0){
                st[j][i] = a[j];
            }
            else{
                int npos = j + (1 << (i - 1));
                if (npos >= M){
                    st[j][i] = st[j][i - 1];
                }
                else{
                    st[j][i] = std::min(st[j][i - 1], st[npos][i - 1]);
                }
            }
        }
    }
    for (int i = 0; i < m; ++ i){
        vec[a[i]].push_back(i);
    }
    for (int i = 0; i < n; ++ i){
        begin[i] = vec[i][0];
        end[i] = vec[i].back();
        if (getst(begin[i], end[i]) < i){
            puts("0");
            return 0;
        }
        posvec.push_back({begin[i], true});
        posvec.push_back({end[i], false});
    }
    std::sort(posvec.begin(), posvec.end());
    printf("%d\n", dfs(0, m - 1));
}