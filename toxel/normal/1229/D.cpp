#include <bits/stdc++.h>

const int N = 200010;
const int K = 200;
typedef std::vector <std::vector <int>> vvi;
typedef long long ll;

int trans[K][K], trans1[K][K], cnt[K];
std::map <std::vector <int>, int> id;
std::map <std::vector <int>, int> groupid;
vvi allperm;
int a[N];
std::vector <int> vec[K];
std::pair <int, int> pos[N];

int getid(std::vector <int> vec){
    auto u = groupid.find(vec);
    if (u != groupid.end()){
        return u -> second;
    }
    int sz = groupid.size();
    cnt[sz] = vec.size();
    return groupid[vec] = sz;
}

std::vector <int> gene(std::vector <int> begin, int k){
    std::set <int> vis;
    std::queue <int> queue;
    vis.insert(0);
    queue.push(0);
    while (!queue.empty()){
        int u = queue.front();
        queue.pop();
        for (auto v : begin){
            int x = trans[u][v];
            if (!vis.count(x)){
                vis.insert(x);
                queue.push(x);
            }
            x = trans[v][u];
            if (!vis.count(x)){
                vis.insert(x);
                queue.push(x);
            }
        }
    }
    std::vector <int> ret;
    for (auto u : vis){
        ret.push_back(u);
    }
    return ret;
}

void init(int k){
    std::vector <int> perm(k);
    for (int i = 0; i < k; ++ i){
        perm[i] = i;
    }
    int cnt = 0;
    do{
        allperm.push_back(perm);
        id[perm] = cnt ++;
    }
    while (std::next_permutation(perm.begin(), perm.end()));
    for (int i = 0; i < cnt; ++ i){
        for (int j = 0; j < cnt; ++ j){
            std::vector <int> nperm(k);
            for (int K = 0; K < k; ++ K){
                nperm[K] = allperm[i][allperm[j][K]];
            }
            trans[i][j] = id[nperm];
        }
    }
    std::map <std::vector <int>, std::vector <int>> vis;
    vis[{0}] = {0};
    std::queue <std::vector <int>> queue;
    queue.push({0});
    while (!queue.empty()){
        auto u = queue.front();
        queue.pop();
        std::vector <int> generator = vis[u];
        int idu = getid(u);
        for (int i = 0; i < cnt; ++ i){
            generator.push_back(i);
            std::vector <int> vec = gene(generator, k);
            if (!vis.count(vec)){
                vis[vec] = generator;
                queue.push(vec);
            }
            trans1[idu][i] = getid(vec);
            generator.pop_back();
        }
    }
    //printf("%d\n", (int) vis.size());
}

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    init(k);
    gene({2, 4}, k);
    for (int i = 0; i < n; ++ i){
        std::vector <int> perm(k);
        for (int j = 0; j < k; ++ j){
            scanf("%d", &perm[j]);
            -- perm[j];
        }
        a[i] = id[perm];
    }
    int tot = allperm.size();
    for (int i = n - 1; i >= 0; -- i){
        vec[a[i]].push_back(i);
    }
    ll ans = 0;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < tot; ++ j){
            if (!vec[j].empty() && i > 0 && vec[j].back() == i - 1){
                vec[j].pop_back();
            }
            if (!vec[j].empty()){
                pos[j] = {vec[j].back(), j};
            }
            else{
                pos[j] = {-1, j};
            }
        }
        std::sort(pos, pos + tot);
        int cur = 0;
        for (int j = 0; j < tot; ++ j){
            if (pos[j].first == -1){
                continue;
            }
            cur = trans1[cur][pos[j].second];
            int next = j == tot - 1 ? n : pos[j + 1].first;
            ans += 1ll * cnt[cur] * (next - pos[j].first);
        }
    }
    printf("%lld\n", ans);
    return 0;
}