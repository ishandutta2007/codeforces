#include<bits/stdc++.h>

const int N = 100010;
typedef std::pair <int, int> pii;

std::vector <int> e[N];
int deg[N];
int pre[N][2];
bool vis[N][2], instack[N];
std::vector <int> stack;

void dfs(int u){
    instack[u] = true;
    stack.push_back(u);
    for (auto v : e[u]){
        if (instack[v]){
            puts("Draw");
            exit(0);
        }
        dfs(v);
    }
    stack.pop_back();
    instack[u] = false;
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1, k; i <= n; ++ i){
        scanf("%d", &k);
        while (k --){
            int x;
            scanf("%d", &x);
            e[i].push_back(x);
            ++ deg[i];
        }
    }
    int s;
    scanf("%d", &s);
    std::queue <pii> queue;
    vis[s][0] = true;
    queue.push({s, 0});
    while (!queue.empty()){
        pii u = queue.front();
        queue.pop();
        if (u.second == 1 && !deg[u.first]){
            puts("Win");
            std::vector <int> vec;
            while (u.first != s || u.second != 0){
                vec.push_back(u.first);
                u = {pre[u.first][u.second], u.second ^ 1};
            }
            vec.push_back(s);
            std::reverse(vec.begin(), vec.end());
            for (int i = 0, sz = vec.size(); i < sz; ++ i){
                printf("%d%c", vec[i], " \n"[i == sz - 1]);
            }
            return 0;
        }
        for (auto v : e[u.first]){
            if (!vis[v][u.second ^ 1]){
                vis[v][u.second ^ 1] = true;
                pre[v][u.second ^ 1] = u.first;
                queue.push({v, u.second ^ 1});
            }
        }
    }
    dfs(s);
    puts("Lose");
    return 0;
}