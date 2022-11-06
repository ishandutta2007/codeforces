#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

const int MAXN = 300010;
int n;
vector<int>e1[MAXN],e2[MAXN];
int fa1[MAXN], fa2[MAXN];
int l[MAXN],r[MAXN];
int time_tag;
int hson[MAXN], sz[MAXN], chain[MAXN], id, top[MAXN];
set<int> st[MAXN];
int cnt[MAXN];
int fuck;

void dfs2(int x) {
    l[x] = ++time_tag;
    sz[x] = 1;
    hson[x] = 0;
    for (auto &t : e2[x]) {
        dfs2(t);
        sz[x] += sz[t];
        if (sz[t] > sz[hson[x]]) {
            hson[x] = t;
        }
    }
    r[x] = ++time_tag;
}

int find_in_set(int x, int is_first) {
    int id = chain[x];
    if (is_first) {
        auto it = st[id].find(x);
        if (it == st[id].begin()) return -1;
        --it;
        return (*it);
    } else {
        auto it = st[id].upper_bound(x);
        if (it == st[id].begin()) return -1;
        --it;
        return (*it);
    }
}

int find_anc(int x) {
    //printf("find %d\n",x);
    int first_round = 1;
    while(true) {
        int tmp = find_in_set(x, first_round);
        if (tmp > 0) return tmp;
        x = fa2[top[chain[x]]];
        first_round = 0;
    }
    assert(false);
}

void add(int x) {
    int id = chain[x];
    st[id].insert(x);
    if (x == 1) return;
    int anc = find_anc(x);
    fuck++;
    if (cnt[anc] == 0) fuck--;
    cnt[anc]++;
}

void erase(int x) {
    int id = chain[x];
    st[id].erase(x);
    if (x == 1) return;
    int anc = find_anc(x);
    fuck--;
    cnt[anc]--;
    if (cnt[anc] == 0) fuck++;
}

int ans;
void dfs1(int x) {
    //printf("dfs1 %d\n",x);
    add(x);
    ans = max(ans, fuck);
    for (auto &t : e1[x]) {
        dfs1(t);
    }
    erase(x);
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for (int i = 1; i <= n; i++) {
            e1[i].clear();
            e2[i].clear();
            cnt[i] = 0;
        }
        for (int i = 2; i <= n; i++) {
            scanf("%d",&fa1[i]);
            e1[fa1[i]].push_back(i);
        }
        for (int i = 2; i <= n; i++) {
            scanf("%d",&fa2[i]);
            e2[fa2[i]].push_back(i);
        }
        time_tag = 0;
        dfs2(1);
        id = 0;
        for (int i = 1; i <= n; i++) {
            if (i == 1 || i != hson[fa2[i]]) {
                chain[i] = ++id;
                top[id] = i;
            } else {
                chain[i] = chain[fa2[i]];
            }
        }
        /*
        for (int i = 1; i <= n; i++) {
            printf("%d %d\n",i,chain[i]);
        }
        for (int i = 1; i <= id; i++) {
            printf("%d %d\n",i,top[i]);
        }
        */
        for (int i = 1; i <= id; i++) {
            st[i].clear();
        }
        ans = 0;
        fuck = 1;
        dfs1(1);
        printf("%d\n",ans);
    }    
}