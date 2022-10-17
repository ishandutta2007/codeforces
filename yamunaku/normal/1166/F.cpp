#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repp(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perr(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl

typedef long long LL;
typedef long double LD;

class UnionFind{
private:
  vector<int> node;
  vector<set<int>> st;

public:
  UnionFind(int n){
    node = vector<int>(n);
    st =vector<set<int>>(n);
    for(int i = 0; i < n; i++){
      node[i] = -1;
    }
  }

  int root(int x){
    if(node[x] < 0) return x;
    else return node[x] = root(node[x]);
  }

  int size(int x){
    return -node[root(x)];
  }

  bool eql(int x, int y){
    if(root(x) == root(y)) return true;
    else return false;
  }

  bool uni(int x, int y){
    x = root(x);
    y = root(y);
    if(x == y) return false;
    if(node[x] > node[y]) swap(x, y);
    node[x] += node[y];
    node[y] = x;
    if(st[x].size()<st[y].size()) swap(st[x],st[y]);
    for(auto &xx:st[y]) st[x].insert(xx);
    st[y].clear();
    return true;
  }

  void add(int x,int a){
    x=root(x);
    st[x].insert(a);
  }

  bool find(int x,int a){
    x=root(x);
    return st[x].find(a)!=st[x].end();
  }
};



int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n,m,cc,q;
  cin >> n >> m >> cc >> q;
  UnionFind uf(n);
  vector<map<int,int>> mp(n);

  int u,v,w;
  rep(i,m){
    cin >> u >> v >> w;
    u--,v--;
    auto itr = mp[v].find(w);
    if(itr!=mp[v].end()) uf.uni(u,itr->second);
    else mp[v][w]=u;
    itr = mp[u].find(w);
    if(itr!=mp[u].end()) uf.uni(v,itr->second);
    else mp[u][w]=v;
    uf.add(u,v);
    uf.add(v,u);
  }
  char c;
  rep(t,q){
    cin >> c;
    if(c=='+'){
      cin >> u >> v >> w;
      u--,v--;
      auto itr = mp[v].find(w);
      if(itr!=mp[v].end()) uf.uni(u,itr->second);
      else mp[v][w]=u;
      itr = mp[u].find(w);
      if(itr!=mp[u].end()) uf.uni(v,itr->second);
      else mp[u][w]=v;
      uf.add(u,v);
      uf.add(v,u);
      continue;
    }
    cin >> u >> v;
    u--,v--;
    if(uf.eql(u,v)){
      CYES;
      continue;
    }
    if(uf.find(u,v)) CYES;
    else CNO;
    continue;
  }
  return 0;
}