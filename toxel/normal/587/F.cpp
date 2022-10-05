#include <bits/stdc++.h>

const int N = 101000;
const int BLOCK = 320;
using ll = long long;

struct Query{
    int l, r, id;
    ll ans;
};

std::string s[N];
char tmp[N];
std::vector <Query> query[N];
ll ans[N];

struct AC_DFA{
    const static int MAXN = N;
    const static int SIGMA = 26;

    int go[MAXN][SIGMA], fail[MAXN], cnt[MAXN];
    ll a[MAXN], block[MAXN];
    std::vector <int> end[MAXN], pass[MAXN], e[MAXN];
    int pcnt, root;

    AC_DFA():go(), pcnt(1), root(1){}

    int new_node(){
        return ++ pcnt;
    }

    void insert(const char *p, int id){
        int cur = root;
        int sz = strlen(p);
        while (*p){
            int pos = *p - 'a';
            if (!go[cur][pos]){
                go[cur][pos] = new_node();
            }
            cur = go[cur][pos];
            ++ p;
            if (sz <= BLOCK){
                pass[cur].push_back(id);
            }
        }
        end[cur].push_back(id);
    }

    void build(){
        std::queue <int> queue;
        queue.push(root);
        while (!queue.empty()){
            int u = queue.front();
            queue.pop();
            for (int i = 0; i < SIGMA; ++ i){
                if (go[u][i]){
                    queue.push(go[u][i]);
                    fail[go[u][i]] = u == root ? root : go[fail[u]][i];
                }
                else{
                    go[u][i] = u == root ? root : go[fail[u]][i];
                }
            }
        }
        for (int i = root + 1; i <= pcnt; ++ i){
            e[fail[i]].push_back(i);
        }
    }

    void dfs_max(int u, int fa){
        for (auto v : e[u]){
            dfs_max(v, u);
            cnt[u] += cnt[v];
        }
    }

    void solve_max(const char *p){
        int cur = root;
        while (*p){
            int id = *p - 'a';
            cur = go[cur][id];
            ++ cnt[cur];
            ++ p;
        }
        dfs_max(1, 0);
        for (int i = 1; i <= pcnt; ++ i){
            for (auto u : end[i]){
                a[u] += cnt[i];
            }
        }
        for (int i = 1; i < N; ++ i){
            a[i] += a[i - 1];
        }
    }

    void add(int sit, int value){
        while (sit % BLOCK != 0){
            a[sit ++] += value;
        }
        sit /= BLOCK;
        while (sit < BLOCK){
            block[sit ++] += value;
        }
    }

    ll query1(int sit){
        return sit < 0 ? 0 : a[sit] + block[sit / BLOCK];
    }

    void solve_min(int u, int fa){
        for (auto v : end[u]){
            add(v, 1);
        }
        for (auto v : pass[u]){
            for (auto &w : query[v]){
                w.ans += query1(w.r) - query1(w.l - 1);
            }
        }
        for (auto v : e[u]){
            solve_min(v, u);
        }
        for (auto v : end[u]){
            add(v, -1);
        }
    }
};

AC_DFA ac_dfa;

int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++ i){
        scanf("%s", tmp);
        s[i] = tmp;
        ac_dfa.insert(s[i].c_str(), i);
    }
    ac_dfa.build();
    for (int i = 0; i < q; ++ i){
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        -- l, -- r, -- k;
        query[k].push_back({l, r, i, 0});
    }
    for (int i = 0; i < n; ++ i){
        if ((int) s[i].size() > BLOCK){
            ac_dfa.solve_max(s[i].c_str());
            for (auto &u : query[i]){
                u.ans = ac_dfa.query1(u.r) - ac_dfa.query1(u.l - 1);
            }
            memset(ac_dfa.a, 0, sizeof(ac_dfa.a));
            memset(ac_dfa.cnt, 0, sizeof(ac_dfa.cnt));
        }
    }
    ac_dfa.solve_min(1, 0);
    for (auto &u : query){
        for (auto &v : u){
            ans[v.id] = v.ans;
        }
    }
    for (int i = 0; i < q; ++ i){
        printf("%lld\n", ans[i]);
    }
    return 0;
}