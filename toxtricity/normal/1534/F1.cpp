#include <bits/stdc++.h>

const int N = 400010;
using pii = std::pair <int, int>;
const int max_N = N;

int a[N];
std::string s[N];
int fa[N];
char input[N];
int n, m;
std::vector <int> next[N];

std::vector<int>vec[max_N+21];

int dfn[max_N+21],low[max_N+21],cnt;

int sccno[max_N+21],scc_cnt;

std::stack<int>st;

int deg[N];

void dfs(int x){
    st.push(x);
    dfn[x]=low[x]=++cnt;
    for(auto&y:vec[x]){
        if(!dfn[y]){
            dfs(y);
            low[x]=std::min(low[x],low[y]);
        }
        else if(!sccno[y]){
            low[x]=std::min(low[x],dfn[y]);
        }
    }
    if(dfn[x]==low[x]){
        sccno[x]=++scc_cnt;
        while(st.top()!=x){
            sccno[st.top()]=scc_cnt;
            st.pop();
        }
        st.pop();
    }
}

int find(int u){
    return fa[u] == u ? u : (fa[u] = find(fa[u]));
}

void unite(int u, int v){
    u = find(u), v = find(v);
    if (u == v) return;
    fa[u] = v;
}

int encode(int u, int v){
    return u * m + v;
}

bool check(int u, int v){
    return u >= 0 && u < n && v >= 0 && v < m && s[u][v] == '#';
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        scanf("%s", input);
        s[i] = input;
    }
    for (int i = 0; i < m; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < N; ++ i){
        fa[i] = i;
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            if (check(i, j) && check(i + 1, j)){
                unite(encode(i, j), encode(i + 1, j));
            }
            if (check(i, j) && check(i, j + 1)){
                unite(encode(i, j), encode(i, j + 1));
            }
        }
    }
    for (int i = 0; i < m; ++ i){
        next[i] = std::vector <int> (n, -1);
        for (int j = n - 1; j >= 0; -- j){
            if (s[j][i] == '#'){
                next[i][j] = j;
            }
            else{
                if (j < n - 1){
                    next[i][j] = next[i][j + 1];
                }
            }
        }
    }
    for (int i = 0; i < m; ++ i){
        int prev = -1;
        for (int j = 0; j < n; ++ j){
            if (s[j][i] == '#'){
                if (prev != -1){
                    vec[find(encode(prev, i))].emplace_back(find(encode(j, i)));
                }
                prev = j;
            }
        }
    }
    for (int i = 0; i < m - 1; ++ i){
        for (int j = 0; j < n; ++ j){
            if (s[j][i] == '#' && next[i + 1][j] != -1){
                vec[find(encode(j, i))].emplace_back(find(encode(next[i + 1][j], i + 1)));
            }
            if (s[j][i + 1] == '#' && next[i][j] != -1){
                vec[find(encode(j, i + 1))].emplace_back(find(encode(next[i][j], i)));
            }
        }
    }
    for (int i = 0; i < n * m; ++ i){
        if (find(i) != i){
            continue;
        }
        if (s[i / m][i % m] == '.'){
            continue;
        }
        if (!dfn[i]){
            dfs(i);
        }
    }
    for (int i = 0; i < n * m; ++ i){
        for (auto u : vec[i]){
            if (sccno[i] == sccno[u]){
                continue;
            }
            ++ deg[sccno[u]];
        }
    }
    int ans = 0;
    for (int i = 1; i <= scc_cnt; ++ i){
        if (deg[i] == 0){
            ++ ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}

/*
5 5
..#.#
....#
#...#
.##.#
...##
1 1 2 1 5

5 17
####.........####
...#.........#...
####.........####
#...............#
#################
4 3 3 4 1 1 1 1 1 1 1 1 1 4 3 3 4
 */