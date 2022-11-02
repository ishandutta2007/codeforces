#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

const int n = 2e5+10;
const int offset = 256*1024 - 1;
const int size = 2*offset+1;

struct node{
  bool pos;
  int a, b;
};

struct chash {
    int operator()(pair<int,int> x) const { return x.first* 31 + x.second; }
};
struct chash2 {
    int operator()(tuple<int,int,int> x) const { return get<0>(x)*307 + 53*get<1>(x) + get<2>(x); }
};

int N, Q;
int P[n];
node S[size];

vector<int> G[n];
//gp_hash_table<pair<int,int>, int, chash> LM;
//gp_hash_table<tuple<int,int,int>, int, chash2> LP;

//for lca
int curNum = 0;
int num[n];
int numToNode[n];
int ind[n];
vector<int> V;
int ST[20][n*2];
pair<int,int> pw[n*2];

void dfs(int cur){
  numToNode[curNum] = cur;
  num[cur] = curNum++;
  ind[cur] = V.size();
  V.push_back(num[cur]);
  for(int x : G[cur]){
    dfs(x);
    V.push_back(num[cur]);
  }
}

void calcLCA(){
  dfs(0);
  int sz = V.size();
  pw[1] = {1, 0};
  for(int i=0; i<sz; i++){
    ST[0][i] = V[i];
  }

  int p = 1;
  for(int i=1; p<=n; i++){
    p *= 2;
    pw[p] = {p, i};
    for(int j=0; j<sz-p/2; j++){
      ST[i][j] = min(ST[i-1][j], ST[i-1][j+p/2]);
    }
  }
  for(int i=2; i<=sz; i++){
    if(pw[i] == make_pair(0,0))
      pw[i] = pw[i-1];
  }
}

int lca(int a, int b){
  int ia = ind[a], ib = ind[b];
  //cout << a << ", " << b << endl;
  if(ia > ib)
    swap(ia, ib);
  //cout << " -> " << ia << " - " << ib << endl;
  pair<int,int> p = pw[ib-ia+1];
  //cout << "pw: " << p.first << ", " << p.second << endl;
  return numToNode[min(ST[p.second][ia], ST[p.second][ib-p.first+1])];
}

bool onUpPath(int u, int anc, int k){
  /*
  if(LP.find(make_tuple(u, anc, k)) != LP.end())
    return LP[make_tuple(u, anc, k)];
    */
  bool res = (lca(u, k) == k) && (lca(k, anc) == anc);
  //LP[make_tuple(u, anc, k)] = res;
  return res;
}

bool onPath(int u, int v, int k){
  int anc = lca(u, v);
  bool res = onUpPath(u, anc, k) || onUpPath(v, anc, k);
  return res;
}

node combine(node a, node b){
  node res = {false, -1, -1};
  if(!a.pos || !b.pos)
    return move(res);
  if(a.a == -1)
    return b;
  if(b.a == -1)
    return a;
  int start[] = {a.a, a.b, b.a, b.b};
  for(int i=0; i<4; i++){
    for(int j=i+1; j<4; j++){
      bool pos = true;
      for(int k=0; k<4; k++){
        pos &= k==i || k==j || onPath(start[i], start[j], start[k]);
      }
      if(pos){
        res.pos = true;
        res.a = start[i];
        res.b = start[j];
        return move(res);
      }
    }
  }
  return move(res);
}

inline int left(int x){
  return 2*x+1;
}
inline int right(int x){
  return 2*x+2;
}
inline int par(int x){
  return (x-1)/2;
}

void update(int x){
  S[offset+P[x]] = {true, x, x};
  x = P[x]+offset;
  while(x != 0){
    x = par(x);
    S[x] = combine(S[left(x)], S[right(x)]);
  }
}

int query(int curl=0, int curr=offset, int cur=0, node combNode = {true, -1, -1}){
  if(curl == curr){
    node newCmb = combine(combNode, S[cur]);
    if(newCmb.pos){
      return curl-1;
    }
    return curl;
  }
  int m = (curl+curr)/2;
  node newCmb = combine(combNode, S[left(cur)]);
  if(newCmb.pos){
    return query(m+1, curr, right(cur), newCmb);
  }
  else{
    return query(curl, m, left(cur), combNode);
  }
}

void printLCA(){
  cout << "V: ";
  for(int i=0; i<V.size(); i++){
    cout << V[i] << " ";
  }
  cout << endl;
  cout << "num: ";
  for(int i=0; i<N; i++){
    cout << num[i] << " ";
  }
  cout << endl;
  cout << "numToNode: ";
  for(int i=0; i<N; i++){
    cout << numToNode[i] << " ";
  }
  cout << endl;
  cout << "ind: ";
  for(int i=0; i<N; i++){
    cout << ind[i] << " ";
  }
  cout << endl;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      //cout << lca(i, j) << " ";
      lca(i, j);
    }
    cout << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> P[i];
  }
  for(int i=1; i<N; i++){
    int x;
    cin >> x;
    x--;
    G[x].push_back(i);
  }
  calcLCA();
  //printLCA();
  for(int i=N-1; i>=0; i--){
    S[offset+P[i]] = {true, i, i};
  }
  for(int i=offset-1; i>=0; i--){
    S[i] = combine(S[left(i)], S[right(i)]);
  }
  vector<int> res;
  cin >> Q;
  for(int i=0; i<Q; i++){
    int t;
    cin >> t;
    if(t == 1){
      int a, b;
      cin >> a >> b;
      a--; b--;
      swap(P[a], P[b]);
      update(a);
      update(b);
    }
    else{
      res.push_back(query());
    }
  }
  for(const int x : res)
    cout << x << "\n";

  return 0;
}