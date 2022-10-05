#include<bits/stdc++.h>

const int MAX = 11;
const int N = 100010;
const int INF = 0x7f7f7f7f;

int dis[1 << MAX];
bool vis[1 << MAX];
int pre[1 << MAX];
int a[N];

struct zzh{
    int x, y, z;
};

std::vector <zzh> ans;

void print(int offset, int x){
    std::vector <int> vec;
    for (int i = 0; i < MAX; ++ i){
        if (x >> i & 1){
            vec.push_back(i);
        }
    }
    for (auto u : vec){
        int sit = offset + u;
        a[sit] ^= 1;
    }
    ans.push_back({offset + vec[0], offset + vec[1], offset + vec[2]});
}

void solve(int sit){
    int x = 0;
    for (int i = sit; i < sit + MAX; ++ i){
        x |= a[i] << (i - sit);
    }
    while (pre[x] != -1){
        print(sit, pre[x]);
        x ^= pre[x];
    }
}

void bf(int n){
    std::vector <int> trans;
    for (int i = 0; i < n; ++ i){
        for (int j = i + 1; j < n; ++ j){
            int k = j - i + j;
            if (k >= n){
                continue;
            }
            trans.push_back((1 << i) | (1 << j) | (1 << k));
        }
    }
    memset(dis, 0x7f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    std::queue <int> queue;
    queue.push(0);
    vis[0] = true;
    dis[0] = 0;
    while (!queue.empty()){
        int u = queue.front();
        queue.pop();
        for (auto v : trans){
            int x = u ^ v;
            if (!vis[x]){
                vis[x] = true;
                pre[x] = v;
                queue.push(x);
                dis[x] = dis[u] + 1;
            }
        }
    }
    int x = 0;
    for (int i = 0; i < n; ++ i){
        x |= a[i] << i;
    }
    if (dis[x] == INF){
        puts("NO");
        exit(0);
    }
    while (x){
        print(0, pre[x]);
        x ^= pre[x];
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    if (n < MAX){
        bf(n);
    }
    else{
        std::vector <int> trans;
        for (int i = 0; i < MAX; ++ i){
            for (int j = i + 1; j < MAX; ++ j){
                int k = j - i + j;
                if (k >= MAX){
                    continue;
                }
                trans.push_back((1 << i) | (1 << j) | (1 << k));
            }
        }
        memset(dis, 0x7f, sizeof(dis));
        memset(pre, -1, sizeof(pre));
        std::queue <int> queue;
        for (int i = 0; i < 1 << (MAX - 6); ++ i){
            queue.push(i);
            vis[i] = true;
            dis[i] = 0;
        }
        while (!queue.empty()){
            int u = queue.front();
            queue.pop();
            for (auto v : trans){
                int x = u ^ v;
                if (!vis[x]){
                    vis[x] = true;
                    pre[x] = v;
                    queue.push(x);
                    dis[x] = dis[u] + 1;
                }
            }
        }
        for (int i = 0; i < 1 << MAX; ++ i){
            assert(dis[i] <= 2);
        }
        for (int i = n - MAX; i >= 0; i -= 6){
            solve(i);
        }
        bf(11);
    }
    puts("YES");
    printf("%d\n", (int) ans.size());
    for (auto u : ans){
        printf("%d %d %d\n", u.x + 1, u.y + 1, u.z + 1);
    }
    return 0;
}