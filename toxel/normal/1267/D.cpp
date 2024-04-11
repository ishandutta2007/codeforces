#include <bits/stdc++.h>

const int N = 300;

struct Server{
    int in, out, id;

    bool operator <(const Server &server)const{
        if (in != server.in){
            return in > server.in;
        }
        if (out != server.out){
            return out > server.out;
        }
        return id < server.id;
    }
};

std::vector <Server> server[N];
int in[N], out[N];
bool vis[N], ans[N];
int bitcnt[N];

int main(){
    bitcnt[1] = bitcnt[2] = bitcnt[4] = 1;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < 3; ++j){
            int x;
            scanf("%d", &x);
            in[i] = in[i] << 1 | x;
        }
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < 3; ++ j){
            int x;
            scanf("%d", &x);
            out[i] = out[i] << 1 | x;
        }
        server[in[i]].push_back({in[i], in[i] & out[i], i});
    }
    vis[7] = true;
    ans[0] = true;
    using pii = std::pair <int, int>;
    std::vector <pii> output;
    for (int i = 1; i < (int) server[7].size(); ++ i){
        output.emplace_back(server[7][0].id, server[7][i].id);
    }
    for (int i = 7; i >= 0; -- i){
        if (vis[i]){
            for (auto u : server[i]){
                if (!vis[u.out]){
                    vis[u.out] = true;
                    ans[u.id] = true;
                    for (auto v : server[u.out]){
                        output.emplace_back(u.id, v.id);
                    }
                }
            }
        }
    }
    std::vector <Server> visited;
    for (int i = 0; i < 8; ++ i){
        if (!vis[i]){
            continue;
        }
        for (auto u : server[i]){
            visited.push_back(u);
        }
    }
    for (auto u : visited){
        for (auto v : visited){
            if (bitcnt[u.out] == 1 && bitcnt[v.out] == 1 && u.out != v.out){
                int x = u.out | v.out;
                if (!vis[x] && !server[x].empty()){
                    vis[x] = true;
                    ans[u.id] = ans[v.id] = true;
                    output.emplace_back(u.id, server[x][0].id);
                    output.emplace_back(v.id, server[x][0].id);
                    for (int k = 1; k < (int) server[x].size(); ++ k){
                        output.emplace_back(server[x][0].id, server[x][k].id);
                    }
                }
            }
        }
    }
    for (int i = 1; i < 8; ++ i){
        if (!vis[i] && !server[i].empty()){
            puts("Impossible");
            return 0;
        }
    }
    puts("Possible");
    for (int i = 0; i < n; ++ i){
        printf("%d%c", (int) ans[i], " \n"[i == n - 1]);
    }
    printf("%d\n", (int) output.size());
    for (auto u : output){
        printf("%d %d\n", u.first + 1, u.second + 1);
    }
    return 0;
}