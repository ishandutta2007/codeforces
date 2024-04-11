#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll magic=0;
template <typename T, typename C>
class mcmf {
  public:
  static constexpr T eps = (T) 1e-9;
  struct edge {
    int from;
    int to;
    T c;
    T f;
    C cost;
  };
  vector< vector<int> > g;
  vector<edge> edges;
  vector<C> d;
  vector<int> q;
  vector<bool> in_queue;
  vector<int> pe;
  int n;
  int st, fin;
  T flow;
  C cost;
  mcmf(int _n, int _st, int _fin) : n(_n), st(_st), fin(_fin) {
    assert(0 <= st && st < n && 0 <= fin && fin < n && st != fin);
    g.resize(n);
    d.resize(n);
    in_queue.resize(n);
    pe.resize(n);
    flow = 0;
    cost = 0;
  }
  void clear_flow() {
    for (const edge &e : edges) {
      e.f = 0;
    }
    flow = 0;
  }
   
  void add(int from, int to, T forward_cap, T backward_cap, C cost) {
    //cout << "add " << from << ' ' << to << ' ' << forward_cap << ' ' << cost << endl;
    assert(0 <= from && from < n && 0 <= to && to < n);
    g[from].push_back((int) edges.size());
    edges.push_back({from, to, forward_cap, 0, cost});
    g[to].push_back((int) edges.size());
    edges.push_back({to, from, backward_cap, 0, -cost});
  }
  bool expath() {
    fill(d.begin(), d.end(), numeric_limits<C>::max());
    q.clear();
    q.push_back(st);
    d[st] = 0;
    in_queue[st] = true;
    int beg = 0;
    bool found = false;
    while (beg < (int) q.size()) {
      int i = q[beg++];
      if (i == fin) {
        found = true;
      }
      in_queue[i] = false;
      for (int id : g[i]) {
        const edge &e = edges[id];
        if (e.c - e.f > eps && d[i] + e.cost < d[e.to]) {
          d[e.to] = d[i] + e.cost;
          pe[e.to] = id;
          if (!in_queue[e.to]) {
            q.push_back(e.to);
            in_queue[e.to] = true;
          }
        }
      }
    }
    if(d[fin]>=0)
        found=0;
    if (found) {
      T push = numeric_limits<T>::max();
      int v = fin;
      while (v != st) {
        const edge &e = edges[pe[v]];
        push = min(push, e.c - e.f);
        v = e.from;
      }
      v = fin;
      while (v != st) {
        edge &e = edges[pe[v]];
        e.f += push;
        edge &back = edges[pe[v] ^ 1];
        back.f -= push;
        v = e.from;
      }
      flow += push;
      cost += push * d[fin];
    }
    return found;
  }
   
  pair<T, C> max_flow_min_cost() {
    while(expath());
    return make_pair(flow, cost);
  }
};
#define fi first
#define se second
int n1,n2,m;
ll rc,bc;
vector<int>l,r;
int ls,rs;
int id1[201];
int id2[201];
char c1[201],c2[201];
int eu[201],ev[201];
int eid[201];
int main(){
    ios::sync_with_stdio(false);
    cin >> n1 >> n2 >> m >> rc >> bc;
    for(int i=1; i<=n1 ;i++){
        cin >> c1[i];
        if(c1[i]=='U') continue;
        if(c1[i]=='R'){
            l.push_back(i);
            id1[i]=l.size();
        }
        else{
            r.push_back(i);
            id1[i]=r.size();
        }
    }
    for(int i=1; i<=n2 ;i++){
        cin >> c2[i];
        if(c2[i]=='U') continue;
        if(c2[i]=='B'){
            l.push_back(i);
            id2[i]=l.size();
        }
        else{
            r.push_back(i);
            id2[i]=r.size();
        }
    }
    ls=l.size();rs=r.size();
    magic=((ll)-1e9)*(ls+rs-1);
    //cout << magic << endl;
    mcmf<int,ll>g(ls+rs+2,0,ls+rs+1);
    for(int i=1; i<=m ;i++){
        int u,v;cin >> u >> v;
        eu[i]=u,ev[i]=v;
        if(c1[u]=='U' && c2[v]=='U') continue;
        if(c1[u]=='U'){
            if(c2[v]=='B') g.add(id2[v],ls+rs+1,1,0,bc);
            else g.add(0,id2[v]+ls,1,0,rc);
            eid[i]=g.edges.size()-1;
            continue;
        }
        if(c2[v]=='U'){
            if(c1[u]=='R') g.add(id1[u],ls+rs+1,1,0,rc);
            else g.add(0,id1[u]+ls,1,0,bc);
            eid[i]=g.edges.size()-1;
            continue;
        }
        if(c1[u]!=c2[v]){
            if(c1[u]=='R'){
                g.add(id1[u],id2[v],1,0,rc);
                g.add(id2[v],id1[u],1,0,bc);
            }
            else{
                g.add(ls+id1[u],ls+id2[v],1,0,rc);
                g.add(ls+id2[v],ls+id1[u],1,0,bc);
            }
            eid[i]=g.edges.size()-1;
            continue;
        }
        if(c1[u]=='R'){
            g.add(id1[u],ls+id2[v],1,0,rc);
        }
        else{
            g.add(id2[v],ls+id1[u],1,0,bc);
        }
        eid[i]=g.edges.size()-1;
       
    }
    for(int i=0; i<ls ;i++){
        g.add(0,i+1,1,0,-1e9);
        g.add(0,i+1,1e9,0,0);
    }
    for(int i=0; i<rs ;i++){
        g.add(ls+i+1,ls+rs+1,1,0,-1e9);
        g.add(ls+i+1,ls+rs+1,1e9,0,0);
    }
    auto duh=g.max_flow_min_cost();
    ll ans=duh.se;
    ans+=1LL*(ls+rs)*((ll)1e9);
    if(ans>=1e9) return cout << "-1\n",0;
    else cout << ans << '\n';
    for(int i=1; i<=m ;i++){
        int u=eu[i],v=ev[i];
        if(c1[u]=='U' && c2[v]=='U'){
            cout << "U";continue;
        }
        if(c1[u]=='U'){
            if(g.edges[eid[i]].f!=0) cout << c2[v];
            else cout << "U";
            continue;
        }
        if(c2[v]=='U'){
            if(g.edges[eid[i]].f!=0) cout << c1[u];
            else cout << "U";
            continue;
        }
        if(c1[u]!=c2[v]){
            if(c1[u]=='R'){
                if(g.edges[eid[i]].f!=0) cout << 'B';
                else if(g.edges[eid[i]-2].f!=0) cout << 'R';
                else cout << 'U';
            }
            else{
                if(g.edges[eid[i]].f!=0) cout << 'B';
                else if(g.edges[eid[i]-2].f!=0) cout << 'R';
                else cout << 'U';
            }
            continue;
        }
        if(c1[u]=='R'){
            if(g.edges[eid[i]].f!=0) cout << 'R';
            else cout << 'U';
        }
        else{
            if(g.edges[eid[i]].f!=0) cout << 'B';
            else cout << 'U';
        }
    }
    cout << '\n';
}