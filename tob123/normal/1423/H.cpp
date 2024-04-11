#include <bits/stdc++.h>
using namespace std;
//#define sz(x) ((int) (x).size())
typedef long long ll;
typedef pair<int,int> pii;
template<class T> void print(T & x){ cout << x; }
template<class T,class U> void print(pair<T,U> & p){cout << "("; print(p.first); cout << ", "; print(p.second); cout << ")"; }
template<class T> void print(vector<T> & v) {
  cout << "{";
  if (sz(v)) print(v[0]);
  for (int i = 1; i < sz(v); i++) cout << ", ", print(v[i]);
  cout << "}\n";
}

struct DSU {
  vector<int> hist, lst = {0}, par, sz;
  DSU(int n) : par(n+1), sz(n+1) {
    iota(par.begin(), par.end(), 0);
    fill(sz.begin(), sz.end(), 1);
  }
  int qry(int x) {
    return par[x] == x ? x : qry(par[x]);
  }
  void join(int x, int y) {
    if ((x=qry(x)) == (y=qry(y))) {
        hist.push_back(-1);
      return;
    }
    if (sz[y] < sz[x])
      swap(x, y);
    sz[par[x] = y] += sz[x];
    hist.push_back(x);
  }
  void snapshot() {
    lst.push_back((int)hist.size());
  }
  void rollback() {
    while (hist.size() != lst.back()) {
      int u = hist.back();
      if (0 <= u){
        //cout << "roll back " << u << par[u] << endl;
        sz[par[u]] -= sz[u], par[u] = u;
      }
      hist.pop_back();
    }
    lst.pop_back();
  }
  int querySz(int x){
    x = qry(x);
    return sz[x];
  }
};

const int n = 1e6+10;

int N, Q, K;

const int siz = 1024*1024*4;
const int offset = siz/2 - 1;
vector<pii> S[siz];
DSU d(n);
map<pii, int> M;
vector<int> qry[siz/2];

int left(int x){
  return 2*x+1;
}
int right(int x){
  return 2*x+2;
}

void update(int l, int r, pii upd, int curl=0, int curr=offset, int cur=0){
  if(l <= curl && r >= curr){
    S[cur].push_back(upd);
    return;
  }
  if(l > curr || r < curl){
    return;
  }
  int m = (curl+curr)/2;
  update(l, r, upd, curl, m, left(cur));
  update(l, r, upd, m+1, curr, right(cur));
}

bool f = false;

void dfs(int cur){
  d.snapshot();
  for(auto [a, b] : S[cur]){
    //cout << "join " << a << " " << b << endl;
    d.join(a, b);
  }
  /*
  if(!f)
    cout << cur-offset << endl;
    */
  if(cur >= offset){
    f = true;
    for(int q : qry[cur-offset]){
      //cout << cur-offset << ": " << q << " -> ";
      cout << d.querySz(q) << endl;
    }
  }
  else{
    dfs(left(cur));
    dfs(right(cur));
  }
  d.rollback();
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> Q >> K;
  int day = 0;
  int op = 0;
  vector<int> lastOp(Q+K+n, -1);
  vector<tuple<int,int,int,pii>> Upd;
  for(int q=0; q<Q; q++){
    int t, u, v;
    cin >> t;
    lastOp[day] = op;
    if(t == 1){
      cin >> u >> v;
      u--; v--;
      if(u > v)
        swap(u,v);
      int lst = -1;
      pii ind = make_pair(u,v);
      if(M.count(ind)){
        lst = M[ind];
      }
      M[ind] = day+K-1;
      if(lst >= day){
        Upd.emplace_back(-1, lst+1, day+K-1, ind);
      }
      else{
        Upd.emplace_back(op, -1, day+K-1, ind);
      }
    }
    else if(t == 2){
      cin >> u;
      u--;
      qry[op].push_back(u);
    }
    else{
      day++;
    }
    op++;
  }
  for(auto [a, b, to, upd] : Upd){
    //cout << a << "(" << b << ")" << " - " << to << endl;
    if(a == -1 && lastOp[b-1] != -1)
      a = lastOp[b-1]+1;
    if(a == -1)
      a = Q+10;
    to = lastOp[to];
    if(to == -1)
      to = Q+10;
    //cout << a << " - " << to;
    //print(upd);
    //cout << endl;
    update(a, to, upd);
  }
  dfs(0);
}