#include<bits/stdc++.h>

const int N = 1010;

std::vector <int> e[N];
int u[N], v[N], w[N];

struct Ans{
    int u, v, w;
};

std::vector <Ans> ans;

void print(int u, int v, int w){
    ans.push_back({u, v, w});
}

int containLeaf(int u, int fa, int leaf){
    int ret = -1;
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        if (ret != leaf){
            ret = containLeaf(v, u, leaf);
        }
    }
    if (ret == -1){
        ret = u;
    }
    return ret;
}

void add(int u, int leaf, int w){
    std::vector <int> vec;
    for (auto v : e[u]){
        int ret = containLeaf(v, u, leaf);
        if (ret != leaf){
            vec.push_back(ret);
        }
    }
    print(leaf, vec[0], w / 2);
    print(leaf, vec[1], w / 2);
    print(vec[0], vec[1], -w / 2);
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++ i){
        scanf("%d%d%d", &u[i], &v[i], &w[i]);
        e[u[i]].push_back(v[i]);
        e[v[i]].push_back(u[i]);
    }
    if (n == 2){
        puts("YES\n1");
        printf("%d %d %d\n", 1, 2, w[0]);
        return 0;
    }
    for (int i = 1; i <= n; ++ i){
        if (e[i].size() == 2){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    for (int i = 0; i < n - 1; ++ i){
        if (e[v[i]].size() == 1){
            std::swap(u[i], v[i]);
        }
        if (e[u[i]].size() == 1){
            add(v[i], u[i], w[i]);
        }
        else{
            int leaf = containLeaf(v[i], u[i], 0);
            add(u[i], leaf, w[i]);
            add(v[i], leaf, -w[i]);
        }
    }
    printf("%d\n", (int) ans.size());
    for (auto u : ans){
        printf("%d %d %d\n", u.u, u.v, u.w);
    }
    return 0;
}