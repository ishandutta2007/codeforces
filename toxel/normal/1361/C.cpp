#include <bits/stdc++.h>

inline int low(int x, int y){
    return x & ((1 << y) - 1);
}

const int BIT = 20;
const int N = 1 << BIT;

struct Edge{
    int to, begin_v, to_v;
    bool vis;
};

int a[N], b[N];
Edge edge[N];
std::vector<int> e[N];
std::vector<int> ans;
std::vector<int> stack;
int n;

void dfs(int u){
    while (true){
        while (!e[u].empty() && edge[e[u].back()].vis){
            e[u].pop_back();
        }
        if (e[u].empty()){
            break;
        }
        int go = e[u].back();
        edge[go].vis = edge[go ^ 1].vis = true;
        stack.push_back(go);
        dfs(edge[go].to);
    }
    if (!stack.empty()){
        ans.emplace_back(stack.back());
        stack.pop_back();
    }
}

bool check(int mid){
    for (int i = 0; i < N; ++ i){
        e[i].clear();
    }
    int ecnt = 0;
    for (int i = 0; i < n; ++ i){
        int x = low(a[i], mid);
        int y = low(b[i], mid);
        edge[ecnt] = {y, 2 * i, 2 * i + 1, false};
        e[x].emplace_back(ecnt ++);
        edge[ecnt] = {x, 2 * i + 1, 2 * i, false};
        e[y].emplace_back(ecnt ++);
    }
    for (int i = 0; i < N; ++ i){
        if (e[i].size() % 2 == 1){
            return false;
        }
    }
    ans.clear();
    stack.clear();
    for (int i = 0; i < N; ++ i){
        if (!e[i].empty()){
            dfs(i);
            break;
        }
    }
    return int(ans.size()) == n;
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d%d", &a[i], &b[i]);
    }
    int left = 0, right = BIT;
    while (left < right){
        int mid = (left + right + 1) / 2;
        if (check(mid)){
            left = mid;
        }
        else{
            right = mid - 1;
        }
    }
    check(left);
    printf("%d\n", left);
    std::reverse(ans.begin(), ans.end());
    for (int i = 0; i < n; ++ i){
        printf("%d %d%c", edge[ans[i]].begin_v + 1, edge[ans[i]].to_v + 1, " \n"[i == n - 1]);
    }
    return 0;
}