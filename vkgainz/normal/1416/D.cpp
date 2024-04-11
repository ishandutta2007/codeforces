#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define f first
#define s second
const int MX = 2e5+5;
int n, m, q, c;
int par[2*MX];
int find_parent(int x) {
    if(x==par[x])
        return x;
    return par[x] = find_parent(par[x]);
}
int in[2*MX], sz[2*MX], p[2*MX];
vector<int> tree[2*MX]; //check sz
vector<int> adj[MX];
int currTime = 0;
void dfs(int curr, int par) {
    ++sz[curr];
    in[curr] = currTime++;
    for(int next : tree[curr]) {
        if(next!=par) {
            dfs(next, curr);
            sz[curr]+=sz[next];
        }
    }
}
pair<int, int> seg[4*MX+5];
void upd(int x, int v) {
    seg[x+=c] = {v, x};
    while(x>1) {
        x/=2;
        seg[x] = max(seg[2*x], seg[2*x+1]);
    }
}
pair<int, int> query(int l, int r) {
    l+=c, r+=c;
    pair<int, int> ret = {0,-1};
    while(l<r) {
        if(l%2) ret = max(ret, seg[l++]);
        if(r%2) ret = max(ret, seg[--r]);
        l/=2, r/=2;
    }
    return ret;
}
int main() {
    scanf("%d%d%d",&n,&m,&q);
    memset(p, 0, sizeof(p));
    for(int i=0;i<n;i++)
        scanf("%d",&p[i]);
    pair<int, int> e[m];
    for(int i=0;i<m;i++) {
        int u, v; scanf("%d%d",&u,&v);
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        e[i] = {u, v};
    }
    bool mark[m];
    memset(mark, 0, sizeof(mark));
    vector<pair<int, int>> queries(q);
    for(int i=0;i<q;i++) {
        scanf("%d%d",&queries[i].f, &queries[i].s);
        --queries[i].s;
        if(queries[i].f==2)
            mark[queries[i].s] = true;
    }
    for(int i=0;i<m;i++)
        if(!mark[i])
            queries.push_back({2, i});
    reverse(queries.begin(), queries.end()); //add extra
    int head[queries.size()];
    memset(head, 0, sizeof(head));
    c = n;
    for(int i=0;i<2*MX;i++)
        par[i] = i;
    vector<int> mx;
    for(int i=0;i<queries.size();i++) {
        if(queries[i].f==2) {
            int u = e[queries[i].s].f, v = e[queries[i].s].s;
            int x = find_parent(u), y = find_parent(v);
            if(x==y) {
                continue;
            }
            tree[c].push_back(x);
            tree[c].push_back(y);
            tree[x].push_back(c);
            tree[y].push_back(c);
            par[x] = c, par[y] = c;
            ++c;
        }
        else {
            mx.push_back(find_parent(queries[i].s));
        }
    }
    for(int i=c-1;i>=0;i--) {
        if(sz[i]==0) {
            dfs(i, -1);
        }
    }
    for(int i=0;i<c;i++) {
        upd(in[i], p[i]);
    }
    reverse(mx.begin(), mx.end());
    vector<int> ans;
    for(auto &it : mx) {
        pair<int, int> curr = query(in[it], in[it]+sz[it]);
        ans.push_back(curr.f);
        upd(curr.s, 0);
    }
    for(auto &it : ans)
        printf("%d\n",it);
}