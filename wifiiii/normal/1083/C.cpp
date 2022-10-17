#include<bits/stdc++.h>

typedef long long ll;
typedef long long LL;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 mrand(42);
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int,int> pii;

const int maxn = 200005;
int a[maxn], ra[maxn];
vector<int> g[maxn];
int son[maxn], f[maxn], tp[maxn], sz[maxn], dep[maxn];
void dfs(int u,int fa) {
    sz[u] = 1;f[u] = fa;
    for(int v : g[u]) {
        if(v == fa) continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
        sz[u] += sz[v];
        if(sz[v] > sz[son[u]]) son[u] = v;
    }
}
void dfs2(int u,int fa,int t) {
    tp[u] = t;
    if(son[u]) dfs2(son[u], u, t);
    for(int v:g[u]) {
        if(v==fa || v==son[u]) continue;
        dfs2(v, u, v);
    }
}
int lca(int u,int v) {
    while(tp[u] != tp[v]) {
        if(dep[tp[u]] > dep[tp[v]]) u = f[tp[u]];
        else v = f[tp[v]];
    }
    if(dep[u] > dep[v]) return v;
    return u;
}
struct node {
    int u, v;
}tr[maxn<<2];

node merge(node &a, node &b) {
    if(a.u == -2) return b;
    if(a.u == -1 || b.u == -1) return node{-1, -1};
//    cout << a.u << " " << a.v << " + " << b.u << " " << b.v << endl;
    vector<int> v{a.u, b.u};
    if(a.v != a.u) v.push_back(a.v);
    if(b.v != b.u) v.push_back(b.v);
    for(int i=0;i<v.size();++i) {
        for(int j=i+1;j<v.size();++j) {
            int ok = 1;
            int l = lca(v[i], v[j]);
            for(int k=0;k<v.size();++k) {
                if(v[i] == v[k] || v[k] == v[j]) continue;
                if(lca(l, v[k]) == l && (lca(v[i], v[k]) == v[k] || lca(v[j], v[k]) == v[k]));
                else {
                    ok = 0;
                    break;
                }
            }
            if(ok) {
//                cout << " = " << v[i] << " " << v[j] << endl;
                return node{v[i], v[j]};
            }
        }
    }
//    cout << " = -1 -1\n";
    return node{-1, -1};
}
void build(int l,int r,int rt) {
    if(l == r) {
        tr[rt].u = tr[rt].v = a[l];
        return;
    }
    int m = (l+r)>>1;
    build(l, m, rt<<1);
    build(m+1, r, rt<<1|1);
    tr[rt] = merge(tr[rt<<1], tr[rt<<1|1]);
}
void update(int pos,int val,int l,int r,int rt) {
    if(l == r) {
        tr[rt].u = tr[rt].v = val;
        return;
    }
    int m=(l+r)>>1;
    if(pos <= m) update(pos, val, l, m, rt<<1);
    else update(pos, val, m+1, r, rt<<1|1);
    tr[rt] = merge(tr[rt<<1], tr[rt<<1|1]);
}
int query(node cur, int l,int r,int rt) {
    if(merge(cur, tr[rt]).u != -1) return r;
    if(l == r) return -1;
    int m = (l + r) / 2;
    node tmp = merge(cur, tr[rt<<1]);
    if(tmp.u == -1) return query(cur, l, m, rt<<1);
    int res = query(tmp, m+1, r, rt<<1|1);
    if(res == -1) return m;
    return res;
}
inline int read()
{
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x*f;
}
int main() {
    int n=read();
    for(int i=1;i<=n;++i) {
        int x=read();
        ++x;
        a[x]=i;
        ra[i]=x;
    }
    for(int i=2;i<=n;++i) {
        int x=read();
        g[x].push_back(i);
    }
    dfs(1,0);
    dfs2(1,0,1);
    build(1,n,1);
    int m=read();
    node s{-2, -2};
    while(m--) {
        int op=read();
        if(op == 1) {
            int u=read(),v=read();
            int x = ra[u], y = ra[v];
            update(ra[u], v, 1, n, 1);
            update(ra[v], u, 1, n, 1);
            swap(a[x], a[y]);
            swap(ra[u], ra[v]);
        } else {
            printf("%d\n", query(s,1,n,1));
        }
    }
}