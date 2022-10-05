#include <bits/stdc++.h>

const int N = 100010;
const int BIT = 18;

struct People{
    static const int M = 10;

    std::vector <int> a;

    People():a(){}

    explicit People(std::vector <int> vec){
        std::sort(vec.begin(), vec.end());
        if ((int) vec.size() > M){
            vec.erase(vec.begin() + M, vec.end());
        }
        a = vec;
    }

    void merge(const People &p){
        std::vector <int> vec;
        std::merge(a.begin(), a.end(), p.a.begin(), p.a.end(), std::back_inserter(vec));
        vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
        if ((int) vec.size() > M){
            vec.erase(vec.begin() + M, vec.end());
        }
        a = vec;
    }
};

std::vector <int> e[N], vec[N];
People lift[N][BIT];
int fa[N][BIT], dep[N];

void dfs(int u, int fa){
    ::fa[u][0] = fa;
    for (int i = 1; i < BIT; ++ i){
        ::fa[u][i] = ::fa[::fa[u][i - 1]][i - 1];
    }
    for (int i = 1; i < BIT; ++ i){
        lift[u][i] = lift[u][i - 1];
        lift[u][i].merge(lift[::fa[u][i - 1]][i - 1]);
    }
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}

int main(){
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= m; ++ i){
        int x;
        scanf("%d", &x);
        vec[x].push_back(i);
    }
    for (int i = 1; i <= n; ++ i){
        lift[i][0] = People(vec[i]);
    }
    dfs(1, 0);
    while (q --){
        int u, v, a;
        scanf("%d%d%d", &u, &v, &a);
        People people;
        if (dep[u] < dep[v]){
            std::swap(u, v);
        }
        for (int i = 0; i < BIT; ++ i){
            if ((dep[u] - dep[v]) >> i & 1){
                people.merge(lift[u][i]);
                u = fa[u][i];
            }
        }
        if (u == v){
            people.merge(lift[u][0]);
        }
        else{
            for (int i = BIT - 1; i >= 0; -- i){
                if (fa[u][i] != fa[v][i]){
                    people.merge(lift[u][i]);
                    people.merge(lift[v][i]);
                    u = fa[u][i];
                    v = fa[v][i];
                }
            }
            people.merge(lift[u][1]);
            people.merge(lift[v][0]);
        }
        int sz = std::min((int) people.a.size(), a);
        printf("%d", sz);
        for (int i = 0; i < sz; ++ i){
            printf(" %d", people.a[i]);
        }
        puts("");
    }
    return 0;
}