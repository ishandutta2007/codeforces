#include<bits/stdc++.h>

const int N = 200010;
typedef std::pair <int, int> pii;

struct op{
    int x, y, _y;

    void write(){
        printf("%d %d %d\n", x, y, _y);
    }
};

std::set <int> e[N];
int sz[N], maxsz[N];
int n;
std::vector <op> ans;

void getsz(int u, int fa){
    sz[u] = 1;
    for (auto v : e[u]){
        if (v == fa) continue;
        getsz(v, u);
        sz[u] += sz[v];
        maxsz[u] = std::max(maxsz[u], sz[v]);
    }
    maxsz[u] = std::max(maxsz[u], n - sz[u]);
}

void getdeg(int u, int fa, auto &set){
    set.insert({e[u].size(), u});
    for (auto v : e[u]){
        if (v == fa) continue;
        getdeg(v, u, set);
    }
}

void solve(int u, int fa){
    std::set <pii> set;
    e[u].erase(fa);
    getdeg(u, fa, set);
    int sz = set.size();
    int nowx = fa, nowy = u;
    std::vector <int> vec;
    for (int i = 0; i < sz - 1; ++ i){
        auto it = set.begin();
        int v = it -> second;
        set.erase(it);
        ans.push_back({nowx, nowy, v});
        nowx = v, nowy = *(e[v].begin());
        vec.push_back(v);
        pii p = *(set.lower_bound({e[nowy].size(), nowy}));
        e[nowy].erase(v);
        set.erase(p);
        -- p.first;
        set.insert(p);
    }
    vec.push_back(set.begin() -> second);
    if (sz <= 2){
        return;
    }
    int cent = vec[sz - 2];
    for (int i = sz - 4; i >= 0; -- i){
        ans.push_back({vec[i], vec[i + 1], cent});
    }
    ans.push_back({fa, vec[0], cent});
}

int main(){
    scanf("%d", &n);
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].insert(v);
        e[v].insert(u);
    }
    getsz(1, 0);
    std::vector <int> cent;
    for (int i = 1; i <= n; ++ i){
        if (maxsz[i] <= n / 2){
            cent.push_back(i);
        }
    }
    if ((int) cent.size() == 1){
        for (auto u : e[cent[0]]){
            solve(u, cent[0]);
        }
    }
    else{
        for (auto u : e[cent[0]]){
            if (u == cent[1]){
                continue;
            }
            solve(u, cent[0]);
        }
        for (auto u : e[cent[1]]){
            if (u == cent[0]){
                continue;
            }
            solve(u, cent[1]);
        }
    }
    printf("%d\n", (int) ans.size());
    for (auto u : ans){
        u.write();
    }
    return 0;
}