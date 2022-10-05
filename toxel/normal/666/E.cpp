#include <bits/stdc++.h>

const int N = 500'010;
const int M = 5'000'010;
const int BIT = 18;
using ll = long long;
using pii = std::pair <int, int>;

pii seg[M];
int ch[M][2];
int node_sz = 0;

int new_node(){
    return ++ node_sz;
}

int merge(int p, int q, int depth = 0){
    if (!p || !q){
        return p | q;
    }
    int n_node = new_node();
    for (int pos = 0; pos < 2; ++ pos){
        ch[n_node][pos] = merge(ch[p][pos], ch[q][pos], depth + 1);
    }
    if (depth == BIT){
        seg[n_node].first = seg[p].first + seg[q].first;
        seg[n_node].second = seg[p].second;
    }
    else{
        seg[n_node] = std::max(seg[ch[n_node][0]], seg[ch[n_node][1]]);
    }
    return n_node;
}

void insert(int root, int sit){
    int p = root;
    std::vector<int> path;
    for (int i = BIT - 1; i >= 0; -- i){
        path.emplace_back(p);
        int pos = sit >> i & 1;
        int cur = ch[p][pos];
        p = ch[p][pos] = new_node();
        seg[p] = seg[cur];
        memcpy(ch[p], ch[cur], sizeof(ch[0]));
    }
    seg[p].first += 1;
    seg[p].second = -sit;
    std::reverse(path.begin(), path.end());
    for (auto sit : path){
        seg[sit] = std::max(seg[ch[sit][0]], seg[ch[sit][1]]);
    }
}

pii query(int root, int ql, int qr, int l, int r){
    if (!root || ql > r || qr < l){
        return {0, 0};
    }
    if (ql <= l && qr >= r){
        return seg[root];
    }
    int mid = (l + r) / 2;
    return std::max(query(ch[root][0], ql, qr, l, mid),
                    query(ch[root][1], ql, qr, mid + 1, r));
}

pii query(int root, int l, int r){
    return query(root, l, r, 0, (1 << BIT) - 1);
}

struct SAM{
    const static int N = 50010;
    const static int MAXNODE = N << 1;
    const static int DICTSIZE = 26;

    int go[MAXNODE][DICTSIZE], link[MAXNODE], len[MAXNODE];
    std::vector<int> right[MAXNODE];
    int last, sz, root;
    std::vector<int> e[MAXNODE]; // parent tree
    int son[MAXNODE], ssz[MAXNODE], rt[MAXNODE];
    int fa[MAXNODE][BIT];

    int newnode(){
        ++ sz;
        memset(go[sz], 0, sizeof(go[sz]));
        right[sz].clear(); //
        return sz;
    }

    void init(){
        sz = 0;
        root = last = newnode();
        len[root] = link[root] = 0;
    }

    int split(int p, int q, int ch){
        int clone = newnode();
        memcpy(go[clone], go[q], sizeof(go[q]));
        link[clone] = link[q];
        link[q] = clone;
        len[clone] = len[p] + 1;
        for (int i = p; i && go[i][ch] == q; i = link[i]){
            go[i][ch] = clone;
        }
        return clone;
    }

    void insert(int ch){
        if (go[last][ch]){ // generalized SAM
            int q = go[last][ch];
            last = len[last] + 1 == len[q] ? q : split(last, q, ch);
            return;
        }
        int cur = newnode();
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
            link[cur] = len[p] + 1 == len[q] ? q : split(p, q, ch);
        }
        last = cur;
    }

    void build(char *s, int id){ // must init() first
        for (char *p = s; *p != '\0'; ++ p){
            insert(*p - 'a');
            right[last].emplace_back(id);
        }
        last = root;
    }

    void dfs(int u){
        ssz[u] = right[u].size();
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
        for (auto v : right[u]){
            ::insert(rt[u], v);
        }
    }

    void build_parent_tree(){
        for (int i = 0; i <= sz; ++ i){
            e[i].clear();
        }
        for (int i = root; i <= sz; ++ i){
            e[link[i]].emplace_back(i);
        }
        dfs1(root, 0);
    }

    void dfs1(int u, int _fa){
        fa[u][0] = _fa;
        for (int i = 1; i < BIT; ++ i){
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }
        for (auto v : e[u]){
            dfs1(v, u);
        }
    }
};

char s[N], t[N];
SAM sam;
int left[N], pos[N];

void solve(){
    int l, r, pl, pr;
    scanf("%d%d%d%d", &pl, &pr, &l, &r);
    -- l, -- r, -- pl, -- pr;
    if (left[r] < r - l + 1){
        printf("%d %d\n", pl + 1, 0);
        return;
    }
    int cur = pos[r];
    for (int i = BIT - 1; i >= 0; -- i){
        if (sam.len[sam.fa[cur][i]] >= r - l + 1){
            cur = sam.fa[cur][i];
        }
    }
    pii p = query(sam.rt[cur], pl, pr);
    if (p.first == 0){
        printf("%d %d\n", pl + 1, 0);
        return;
    }
    printf("%d %d\n", -p.second + 1, p.first);
}

int main(){
    sam.init();
    scanf("%s", s);
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; ++ i){
        scanf("%s", t);
        sam.build(t, i);
    }
    int n = strlen(s);
    int cur = sam.root, len = 0;
    for (int i = 0; i < n; ++ i){
        int ch = s[i] - 'a';
        while (cur > sam.root && !sam.go[cur][ch]){
            cur = sam.link[cur];
            len = sam.len[cur];
        }
        if (!sam.go[cur][ch]){
            left[i] = 0;
            continue;
        }
        cur = sam.go[cur][ch];
        ++ len;
        left[i] = len;
        pos[i] = cur;
    }
    sam.build_parent_tree();
    sam.dfs(sam.root);
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}