#include <bits/stdc++.h>

const int N = 50010;

std::map <int, std::vector <int>> e[N];
int u[N], v[N], t[N];

struct twoSat{   //for 2-sat MAXN is two times large
    static const int MAXN = 200010;

    int col[MAXN];
    std::vector<int> vec[MAXN << 1];
    int dfn[MAXN << 1], low[MAXN << 1], bel[MAXN << 1], ncnt, scnt;
    bool vis[MAXN << 1];
    std::stack<int> stack;

    void clear(){
        memset(col, 0, sizeof(col));
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        memset(bel, 0, sizeof(bel));
        memset(vis, 0, sizeof(vis));
        for (auto &u : vec){
            u.clear();
        }
        while (!stack.empty()){
            stack.pop();
        }
        ncnt = scnt = 0;
    }

    void tarjan(int u){
        dfn[u] = low[u] = ++ ncnt;
        stack.push(u);
        vis[u] = true;
        for(auto v : vec[u]){
            if(!dfn[v]){
                tarjan(v);
                low[u] = std::min(low[u], low[v]);
            }
            else if(vis[v]){
                low[u] = std::min(low[u], dfn[v]);
            }
        }
        if(low[u] == dfn[u]){
            int v; ++ scnt;
            do{
                v = stack.top(); stack.pop();
                vis[v] = false;
                bel[v] = scnt;
            }while(v != u);
        }
    }

    void addedge(int u, int v){
        ++ u, ++ v;
        vec[u].push_back(v);
    }

    bool solve(int n){ //tarjan + topsort
        memset(dfn, 0, sizeof(dfn));
        memset(vis, 0, sizeof(vis));
        ncnt = scnt = 0;
        for(int i = 1; i <= n + n; ++ i){
            if(!dfn[i]){
                tarjan(i);
            }
        }
        for(int i = 1; i <= n; ++ i){
            if(bel[i] == bel[i + n]){
                return false;
            }
        }
        for(int i = 1; i <= n; ++ i){
            col[i] = (bel[i] < bel[i + n]);
        }

        return true;
    }
};

twoSat two_sat;

bool check(int mid, int n, int m){
    two_sat.clear();
    int tot = 3 * m;
    for (int i = 0; i < m; ++ i){
        if (t[i] > mid){
            two_sat.addedge(i, i + tot);
        }
    }
    int pcnt = m;
    for (int i = 1; i <= n; ++ i){
        std::vector <int> vec;
        for (auto &u : e[i]){
            if ((int) u.second.size() == 2){
                two_sat.addedge(u.second[0] + tot, u.second[1]);
                two_sat.addedge(u.second[1] + tot, u.second[0]);
            }
            for (auto v : u.second){
                vec.push_back(v);
            }
        }
        int prev = -1;
        for (auto u : vec){
            if (prev >= 0){
                two_sat.addedge(prev, pcnt);
                two_sat.addedge(pcnt + tot, prev + tot);
                two_sat.addedge(u, prev + tot);
                two_sat.addedge(prev, u + tot);
            }
            two_sat.addedge(u, pcnt);
            two_sat.addedge(pcnt + tot, u + tot);
            prev = pcnt ++;
        }
    }
    return two_sat.solve(tot);
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++ i){
        int c;
        scanf("%d%d%d%d", &u[i], &v[i], &c, &t[i]);
        e[u[i]][c].push_back(i);
        e[v[i]][c].push_back(i);
    }
    for (int i = 1; i <= n; ++ i){
        int cnt = 0;
        for (auto &u : e[i]){
            if ((int) u.second.size() > 2){
                puts("No");
                return 0;
            }
            cnt += (int) u.second.size() == 2;
        }
        if (cnt > 1){
            puts("No");
            return 0;
        }
    }
    int left = 0, right = *std::max_element(t, t + m);
    while (left < right){
        int mid = (left + right) / 2;
        if (check(mid, n, m)){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    if (check(left, n, m)){
        puts("Yes");
        std::vector <int> ans;
        for (int i = 1; i <= m; ++ i){
            if (two_sat.col[i]){
                ans.push_back(i);
            }
        }
        int sz = ans.size();
        printf("%d %d\n", left, sz);
        for (int i = 0; i < sz; ++ i){
            printf("%d%c", ans[i], " \n"[i == sz - 1]);
        }
    }
    else{
        puts("No");
    }
    return 0;
}