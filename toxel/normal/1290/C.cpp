#include <bits/stdc++.h>

const int N = 1000010;

struct Node{
    int up{}, down{};
    bool choose{}, freeze{};
};

int fa[N];
std::vector <int> set[N], vec[N];
char s[N];
Node node[N];
int n, k;

int oppo(int id){
    return id >= k ? id - k : id + k;
}

int find(int u){
    return fa[u] == u ? u : (fa[u] = find(fa[u]));
}

int calc(int id){
    id = find(id);
    if (!node[id].freeze){
        return std::min(node[id].up, node[id].down);
    }
    if (!node[id].choose){
        id = find(oppo(id));
    }
    return node[id].up;
}

void unite(int u, int v){
    u = find(u), v = find(v);
    if (u == v){
        return;
    }
    fa[u] = v;
    node[v].up += node[u].up;
    node[v].down += node[u].down;
    if (node[u].freeze){
        node[v].freeze = true;
    }
    if (node[u].choose){
        node[v].choose = true;
    }
}

int main(){
    scanf("%d%d", &n, &k);
    scanf("%s", s + 1);
    for (int i = 0; i < k; ++ i){
        int c;
        scanf("%d", &c);
        for (int j = 0; j < c; ++ j){
            int x;
            scanf("%d", &x);
            set[i].emplace_back(x);
            vec[x].emplace_back(i);
        }
    }
    for (int i = 0; i < k; ++ i){
        fa[i] = i;
        node[i].up = 1;
    }
    for (int i = k; i < 2 * k; ++ i){
        fa[i] = i;
        node[i].down = 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++ i){
        if (vec[i].empty()){
        }
        else if (int(vec[i].size()) == 1){
            int id = vec[i][0];
            if (s[i] == '1'){
                id = oppo(id);
            }
            ans -= calc(id);
            int id1 = oppo(id);
            id = find(id), id1 = find(id1);
            node[id].freeze = node[id1].freeze = true;
            node[id].choose = true;
            node[id1].choose = false;
            ans += calc(id);
        }
        else{
            int id = vec[i][0], id1 = vec[i][1];
            bool flag = true;
            if (s[i] == '0' && find(id) == find(id1 + k)){
                flag = false;
            }
            if (s[i] == '1' && find(id) == find(id1)){
                flag = false;
            }
            if (flag){
                ans -= calc(id), ans -= calc(id1);
                if (s[i] == '0'){
                    unite(id, id1 + k);
                    unite(id + k, id1);
                }
                else{
                    unite(id, id1);
                    unite(id + k, id1 + k);
                }
                ans += calc(id);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}