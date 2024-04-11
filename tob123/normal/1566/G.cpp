#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
typedef long long ll;
typedef pair<int,int> pii;
/*
template<class T> void print(T & x){ cout << x; }
template<class T,class U> void print(pair<T,U> & p){cout << "("; print(p.first); cout << ", "; print(p.second); cout << ")"; }
template<class T> void print(multiset<T> & v){
  auto it = v.begin();
  cout << "{";
  if (sz(v)) print(*it);
  for (it++; it != v.end(); it++) cout << ", ", print(*it);
  cout << "}\n";
}
template<class T> void print(vector<T> & v) {
  cout << "{";
  if (sz(v)) print(v[0]);
  for (int i = 1; i < sz(v); i++) cout << ", ", print(v[i]);
  cout << "}\n";
}
*/
typedef tuple<ll,int,int> edge;

void pp(edge & p){
  auto [a,b,c] = p;
  cout << "(" << a << ", " << b << ", " << c << ")";
}
void pp(multiset<edge> E){
  cout << "{";
  for(auto x : E)
    pp(x), cout << ", ";
  cout << "}";
}

const ll INF = 1e11;

set<edge> E;
map<pii,ll> W;
vector<set<edge>> V, act;
set<pair<ll,int>> bestV;

void remE(edge e){
  if(E.count(e))
    E.erase(e);
}

ll getSum(int v){
  if(sz(act[v]) < 3) return -1;
  auto it = act[v].begin();
  ll sum = 0;
  for(int i=0; i<3; i++){
    sum += get<0>(*it);
    it++;
  }
  return sum;
}

void remBest(int v){
  ll sum = getSum(v);
  if(sum >= 0){
    bestV.erase(make_pair(sum, v));
  }
}

void addBest(int v){
  ll sum = getSum(v);
  if(sum >= 0){
    bestV.insert(make_pair(sum, v));
  }
}

void addAct(int v, edge e){
  act[v].insert(e);
  if(sz(act[v]) > 3){
    auto it = --(act[v].end());
    V[v].insert(*it);
    remE(*it);
    act[v].erase(it);
  }
  auto [a,b,c] = e;
  if(act[b].count(e) && act[c].count(e)){
    remE(e);
    E.insert(e);
  }
}

void addV(int v, edge e){
  addAct(v, e);
}

void remV(int v, edge e){
  if(act[v].count(e)){
    act[v].erase(e);
    if(sz(V[v])){
      addAct(v, *(V[v].begin()));
      V[v].erase(V[v].begin());
    }
  }
  else{
    V[v].erase(e);
  }
}

void ins(int u, int v, ll  w){
  tie(u, v) = make_pair(min(u,v), max(u,v));
  auto e = make_tuple(w,u,v);
  W[make_pair(u,v)] = w;
  remBest(u);
  remBest(v);
  addV(u, e);
  addV(v, e);
  addBest(u);
  addBest(v);
}
void rem(int u, int v, ll  w){
  tie(u, v) = make_pair(min(u,v), max(u,v));
  auto e = make_tuple(w,u,v);
  W.erase(make_pair(u,v));
  remE(e);
  remBest(u);
  remBest(v);
  remV(u, e);
  remV(v, e);
  addBest(u);
  addBest(v);
}

ll calc(){
  ll res = INF;
  if(sz(bestV))
    res = bestV.begin()->first;
  auto it = E.begin();
  auto [w, u, v] =  *(it++); 
  for(int i=0; i<15 && it != E.end(); i++){
    auto [w2, u2, v2] = *(it++);
    if(u != u2 && v != v2 && u != v2 && v != u2)
      res = min(res, w+w2);
  }
  auto it1 = act[v].begin();
  for(int i=0; i<5 && it1 != act[v].end(); i++,it1++){
    auto [a,b,c] = *it1;
    auto it2 = act[u].begin();
    for(int j=0; j<5 && it2 != act[u].end(); j++,it2++){
      auto [d,e,f] = *it2;
      if(b != e && b != f && c != e && c != f)
         res = min(res, a+d);
    }
  }
  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, M, Q;
  cin >> N >> M;
  V.resize(N);
  act.resize(N);
  for(int i=0; i<M; i++){
    int u, v; ll w;
    cin >> u >> v >> w; 
    u--; v--;
    ins(u,v,w);
  }
  cout << calc() << "\n";
  cin >> Q;
  for(int i=0; i<Q; i++){
    int q, u, v; ll w;
    cin >> q >> u >> v;
    u--; v--;
    if(q == 0){
      w = W[make_pair(min(u,v), max(u,v))];
      rem(u, v, w);
    }
    else{
      cin >> w;
      ins(u, v, w);
    }
    cout << calc() << "\n";
  }
}