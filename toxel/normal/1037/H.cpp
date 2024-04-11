#include <bits/stdc++.h>

const int N = 200'010;
const int M = 10'000'010;
const int BIT = 19;
using ll = long long;

int seg[M], ch[M][2];
int node_sz = 0;

int new_node(){
    return ++ node_sz;
}

int merge(int p, int q){
    if (!p || !q){
        return p | q;
    }
    int n_node = new_node();
    seg[n_node] = seg[p] + seg[q];
    for (int pos = 0; pos < 2; ++ pos){
        ch[n_node][pos] = merge(ch[p][pos], ch[q][pos]);
    }
    return n_node;
}

void insert(int root, int sit){
    ++ seg[root];
    for (int i = BIT - 1; i >= 0; -- i){
        int pos = sit >> i & 1;
        int cur = ch[root][pos];
        root = ch[root][pos] = new_node();
        seg[root] = seg[cur] + 1;
        memcpy(ch[root], ch[cur], sizeof(ch[0]));
    }
}

int query(int root, int ql, int qr, int l, int r){
    if (!root || ql > r || qr < l){
        return -1;
    }
    if (l == r){
        return l;
    }
    int mid = (l + r) / 2;
    int ret = query(ch[root][1], ql, qr, mid + 1, r);
    if (ret != -1){
        return ret;
    }
    return query(ch[root][0], ql, qr, l, mid);
}

int query(int root, int l, int r){
    return query(root, l, r, 0, (1 << BIT) - 1);
}

struct SAM{
    const static int N = 1000010;
    const static int MAXNODE = N << 1;
    const static int DICTSIZE = 26;

    int go[MAXNODE][DICTSIZE], link[MAXNODE], len[MAXNODE];
    int right[MAXNODE];
    int last, sz, root;
    std::vector<int> e[MAXNODE]; // parent tree
    int son[MAXNODE], ssz[MAXNODE], rt[MAXNODE];

    int newnode(){
        ++ sz;
        memset(go[sz], 0, sizeof(go[sz]));
        right[sz] = -1; //
        return sz;
    }

    void init(){
        sz = 0;
        root = last = newnode();
        len[root] = link[root] = 0;
    }

    void insert(int ch, int pos){// ch - 'a'
        int cur = newnode();
        right[cur] = pos; //
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

    void dfs(int u){
        ssz[u] = right[u] != -1;
        for (auto v : e[u]){
            dfs(v);
            if (ssz[v] > ssz[son[u]]){
                son[u] = v;
            }
            ssz[u] += ssz[v];
        }
        rt[u] = new_node();
        seg[rt[u]] = seg[rt[son[u]]];
        memcpy(ch[rt[u]], ch[rt[son[u]]], sizeof(ch[0]));
        for (auto v : e[u]){
            if (v == son[u]){
                continue;
            }
            rt[u] = merge(rt[u], rt[v]);
        }
        if (right[u] != -1){
            ::insert(rt[u], right[u]);
        }
    }

    void build(char *s){
        init();
        for (char *p = s; *p != '\0'; ++ p){
            insert(*p - 'a', p - s);
        }
        build_parent_tree();
        dfs(root);
    }

    void build_parent_tree(){
        for (int i = 0; i <= sz; ++ i){
            e[i].clear();
        }
        for (int i = root; i <= sz; ++ i){
            e[link[i]].emplace_back(i);
        }
    }
};

char s[N];
SAM sam;

void solve(){
    int l, r;
    scanf("%d%d%s", &l, &r, s);
    int n = strlen(s);
    -- l, -- r;
    int cur = sam.root;
    std::vector<int> position = {cur};
    auto go = [&](int cur, int ch, int len){
        if (cur == 0){
            return 0;
        }
        cur = sam.go[cur][ch];
        ++ len;
        if (cur){
            int x = query(sam.rt[cur], l, r);
            if (x == -1 || x - len + 1 < l){
                return 0;
            }
        }
        return cur;
    };
    for (int i = 0; i < n; ++ i){
        int ch = s[i] - 'a';
        cur = go(cur, ch, i);
        position.emplace_back(cur);
    }
    for (int i = n; i >= 0; -- i){
        if (position[i] == 0){
            continue;
        }
        for (int j = i == n ? 'a' : s[i] + 1; j <= 'z'; ++ j){
            if (go(position[i], j - 'a', i)){
                for (int k = 0; k < i; ++ k){
                    putchar(s[k]);
                }
                putchar(char(j));
                puts("");
                return;
            }
        }
    }
    puts("-1");
}

int main(){
    scanf("%s", s);
    sam.build(s);
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}