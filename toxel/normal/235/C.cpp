#include <bits/stdc++.h>

const int N = 1000010;
using ll = long long;

struct SAM{
    const static int N = 1000010;
    const static int MAXNODE = N << 1;
    const static int DICTSIZE = 26;

    int go[MAXNODE][DICTSIZE], link[MAXNODE], len[MAXNODE];
    bool new_right[MAXNODE];
    int last, sz, root;
    std::vector<int> e[MAXNODE]; // parent tree

    int newnode(){
        ++ sz;
        memset(go[sz], 0, sizeof(go[sz]));
        new_right[sz] = false; //
        return sz;
    }

    void init(){
        sz = 0;
        root = last = newnode();
        len[root] = link[root] = 0;
    }

    void insert(int ch){// ch - 'a'
        int cur = newnode();
        new_right[cur] = true; //
        len[cur] = len[last] + 1;
        int p = last;
        for ( ; p && !go[p][ch]; p = link[p]){
            go[p][ch] = cur;
        }
        if (!p){
            link[cur] = root;
        }
        else{
            int q = go[p][ch];
            if (len[p] + 1 == len[q]){
                link[cur] = q;
            }
            else{
                int clone = newnode();
                memcpy(go[clone], go[q], sizeof(go[q]));
                link[clone] = link[q];
                link[q] = link[cur] = clone;
                len[clone] = len[p] + 1;
                for (int i = p; i && go[i][ch] == q; i = link[i]){
                    go[i][ch] = clone;
                }
            }
        }
        last = cur;
    }

    void build(char *s){
        init();
        for (char *p = s; *p != '\0'; ++ p){
            insert(*p - 'a');
        }
    }

    void build_parent_tree(){
        for (int i = root; i <= sz; ++ i){
            e[link[i]].emplace_back(i);
        }
    }
};

char s[N];
int vis[N << 1];
int sz[N << 1];
SAM sam;

void dfs(int u){
    sz[u] = sam.new_right[u];
    for (auto v : sam.e[u]){
        dfs(v);
        sz[u] += sz[v];
    }
}

int main(){
    scanf("%s", s);
    sam.build(s);
    sam.build_parent_tree();
    dfs(sam.root);
    int test;
    scanf("%d", &test);
    for (int _ = 1; _ <= test; ++ _){
        scanf("%s", s);
        int n = strlen(s);
        ll ans = 0;
        int cur = sam.root, len = 0;
        for (int i = 0; i < 2 * n; ++ i){
            int ch = s[i % n] - 'a';
            while (cur > sam.root && !sam.go[cur][ch]){
                cur = sam.link[cur];
                len = sam.len[cur];
            }
            if (!sam.go[cur][ch]){
                continue;
            }
            cur = sam.go[cur][ch];
            ++ len;
            if (len > n){
                -- len;
                if (len == sam.len[sam.link[cur]]){
                    cur = sam.link[cur];
                }
            }
            if (len == n && vis[cur] != _){
                vis[cur] = _;
                ans += sz[cur];
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}