#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 505;
const int maxm = 10005;
template<typename T>
struct Dinic {
    struct edge {
        int v, nxt;
        T f, c;
    }es[maxm];
    int head[maxn], cur[maxn], d[maxn], tot = 0;
    const T inf = numeric_limits<T>::max();
    void init() {
        memset(head, -1, sizeof(head));
        tot = 0;
    }
    void adde(int u, int v, T w) {
        es[tot] = {v, head[u], 0, w}; head[u] = tot++;
        es[tot] = {u, head[v], 0, 0}; head[v] = tot++;
    }
    T maxflow(int s, int t, int n) {
        auto bfs = [&]() -> int {
            for(int i = 0; i <= n; ++i) d[i] = -1;
            queue<int> q;
            q.push(s);
            d[s] = 0;
            while(!q.empty()) {
                int u = q.front(); q.pop();
                for(int i = head[u]; ~i; i = es[i].nxt) {
                    if(d[es[i].v] == -1 && es[i].f < es[i].c) {
                        d[es[i].v] = d[u] + 1;
                        q.push(es[i].v);
                        if(es[i].v == t) return 1;
                    }
                }
            }
            return 0;
        };
        function<T(int,T)> dfs = [&](int u, T f) {
            if(u == t || !f) return f;
            T ret = 0;
            for(int &i = cur[u]; ~i; i = es[i].nxt) {
                if(d[es[i].v] == d[u] + 1 && es[i].c - es[i].f) {
                    T tmp = dfs(es[i].v, min(f, es[i].c - es[i].f));
                    if(!tmp) {
                        d[es[i].v] = 0;
                        continue;
                    }
                    es[i].f += tmp;
                    es[i^1].f -= tmp;
                    f -= tmp;
                    ret += tmp;
                    if(!f) break;
                }
            }
            return ret;
        };
        T ans = 0;
        while(bfs()) {
            for(int i = 0; i <= n; ++i) cur[i] = head[i];
            ans += dfs(s, inf);
        }
        return ans;
    }
    void clearflow() {
        for(int i = 0; i < tot; ++i) es[i].f = 0;
    }
    vector<int> getcut(int s, int n) {
        for(int i = 0; i <= n; ++i) d[i] = 0;
        queue<int> q;
        q.push(s);
        d[s] = 1;
        vector<int> ret;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            ret.push_back(u);
            for(int i = head[u]; ~i; i = es[i].nxt) {
                if(!d[es[i].v] && es[i].c > es[i].f) {
                    d[es[i].v] = 1;
                    q.push(es[i].v);
                }
            }
        }
        return ret;
    }
};

struct edge {
    int u,v,w,use,ord;
    bool operator < (const edge & e) const {
        return w > e.w;
    }
};
int par[maxn];
int find(int x) {return x==par[x]?x:par[x]=find(par[x]);}

int p[maxn], f[maxn];
Dinic<int> d;
int main() {
    int n, m;
    cin >> n >> m;
    d.init();
    for(int i=1;i<=m;++i) {
        int u,v,w;
        cin>>u>>v>>w;
        d.adde(u,v,w);
        d.adde(v,u,w);
    }
    for(int i=2;i<=n;++i) p[i]=1;
    for(int i=2;i<=n;++i) {
        f[i]=d.maxflow(i,p[i],n);
        vector<int> cut=d.getcut(i,n);
        d.clearflow();
        for(int j:cut) if(j>i && p[j]==p[i]) p[j]=i;
    }
    vector<edge> es;
    int ans=0;
    for(int i=2;i<=n;++i) {
        es.push_back({p[i],i,f[i]});
    }
    sort(es.begin(),es.end());
    int cnt=0;
    for(int i=1;i<=n;++i) par[i]=i;
    for(auto &p:es) {
        if(find(p.u)!=find(p.v)) {
            p.use=1;
            p.ord=++cnt;
            ans+=p.w;
            par[find(p.u)]=find(p.v);
        }
    }
    sort(es.begin(),es.end(),[&](edge e1,edge e2){return e1.ord<e2.ord;});
    for(int i=1;i<=n;++i) par[i]=i;
    vector<int> s(n+1),t(n+1),nxt(n+1);
    for(int i=1;i<=n;++i) s[i]=t[i]=i;
    for(auto p:es) {
        if(!p.use) continue;
        int lft=find(p.u),rht=find(p.v);
        par[lft]=rht;
        nxt[t[lft]]=s[rht];
        s[rht]=s[lft];
    }
    int x=find(1),cur=s[x];
    cout<<ans<<'\n';
    while(cur) {
        cout<<cur<<" ";
        cur=nxt[cur];
    }
    cout<<endl;
}