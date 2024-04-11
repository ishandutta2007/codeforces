#include <bits/stdc++.h>

const int N = 5010;
const int M = 2000010;
using pii = std::pair <int, int>;
const int moder = (int) 1e9 + 7;

int n, a, b;
char s[N][N];
std::string str[N];
int len[N];
char tmp[M];
int left[N], right[N];
int dfn[N], low[N], dfncnt;
bool instack[N];
std::vector <int> topo, stack, scc[N];
int sccno[N], scccnt;
pii p[N];
int comb[N][N];

int getcomb(int n, int m){
    return n < m || m < 0 ? 0 : comb[n][m];
}

void dfs(int u){
    dfn[u] = low[u] = ++ dfncnt;
    stack.push_back(u);
    instack[u] = true;
    for (int i = 1; i <= n; ++ i){
        if (s[u][i] == '0'){
            continue;
        }
        if (!dfn[i]){
            dfs(i);
            low[u] = std::min(low[u], low[i]);
        }
        else if (instack[i]){
            low[u] = std::min(low[u], dfn[i]);
        }
    }
    if (low[u] == dfn[u]){
        while (true){
            int x = stack.back();
            stack.pop_back();
            instack[x] = false;
            sccno[x] = scccnt;
            scc[scccnt].push_back(x);
            if (x == u){
                break;
            }
        }
        ++ scccnt;
    }
    topo.push_back(u);
}

int main(){
    for (int i = 0; i < N; ++ i){
        comb[i][0] = 1;
        for (int j = 1; j <= i; ++ j){
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % moder;
        }
    }
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 1; i <= n; ++ i){
        scanf("%s", s[i] + 1);
    }
    for (int i = 1; i <= n; ++ i){
        int x;
        scanf("%d%s", &x, tmp);
        str[i] = tmp;
        for (int j = 0; j < x; ++ j){
            left[i] += tmp[j] == '1';
        }
        len[i] = x;
    }
    for (int i = 1; i <= n; ++ i){
        if (!dfn[i]){
            dfs(i);
        }
    }
    std::reverse(topo.begin(), topo.end());
    topo.erase(std::unique(topo.begin(), topo.end(), [&](const int &p1, const int &p2){
        return sccno[p1] == sccno[p2];
    }), topo.end());
    for (auto &u : topo){
        u = sccno[u];
    }
    for (int i = 0, sz = topo.size(); i < sz; ++ i){
        int gcd = 0;
        for (auto v : scc[topo[i]]){
            gcd = std::__gcd(gcd, len[v]);
        }
        std::vector <bool> remain(gcd);
        for (auto v : scc[topo[i]]){
            for (int j = 0; j < len[v]; ++ j){
                if (str[v][j] == '1'){
                    remain[j % gcd] = true;
                }
            }
        }
        for (auto v : scc[topo[i]]){
            for (int j = 0; j < len[v]; ++ j){
                if (remain[j % gcd]){
                    str[v][j] = '1';
                }
            }
        }
        if (i == sz - 1){
            break;
        }
        for (auto v : scc[topo[i + 1]]){
            gcd = std::__gcd(gcd, len[v]);
        }
        remain = std::vector <bool>(gcd);
        for (auto v : scc[topo[i]]){
            for (int j = 0; j < len[v]; ++ j){
                if (str[v][j] == '1'){
                    remain[j % gcd] = true;
                }
            }
        }
        for (auto v : scc[topo[i + 1]]){
            for (int j = 0; j < len[v]; ++ j){
                if (remain[j % gcd]){
                    str[v][j] = '1';
                }
            }
        }
    }
    for (int i = 1; i <= n; ++ i){
        for (auto ch : str[i]){
            right[i] += ch == '1';
        }
        p[i] = {right[i], left[i]};
    }
    std::sort(p + 1, p + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; ++ i){
        int cntleft = 0, cntright = 0;
        for (int j = 1; j < i; ++ j){
            cntleft += p[j].second > p[i].first;
        }
        for (int j = i + 1; j <= n; ++ j){
            cntright += p[j].second > p[i].first;
        }
        for (int j = 0; j <= cntright; ++ j){
            if (cntleft + cntright - j > a - b){
                continue;
            }
            ans = (ans + 1ll * getcomb(cntright, j) * getcomb(n - i - cntright, b - 1 - j)) % moder;
        }
    }
    printf("%d\n", ans);
    return 0;
}