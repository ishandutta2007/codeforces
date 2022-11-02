#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
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

const ll MOD = 1e9+7;
const int MAX_LEV = 20;
const int OFFSET = (1<<MAX_LEV)-1;
const int H_OFF[2] = {0, 2*(MAX_LEV+1)};

vector<ll> randomNums;

const int NUM_HASHES = 1;

struct hashValue{
  ll h[NUM_HASHES];

  hashValue(){
    for(int i=0; i<NUM_HASHES; i++)
      h[i] = 0;
  }

  void setOne(){
    for(int i=0; i<NUM_HASHES; i++)
      h[i] = 1;
  }

  void calc(hashValue& l, hashValue& r, int lev){
    for(int i=0; i<NUM_HASHES; i++){
      h[i] = (l.h[i]*randomNums[H_OFF[i]+2*lev] + r.h[i]*randomNums[H_OFF[i]+2*lev+1]) % MOD;
    }
  }

  bool operator==(const hashValue& x) const{
    bool f = true;
    for(int i=0; i<NUM_HASHES; i++){
      f &= h[i] == x.h[i];
    }
    return f;
  }
};

vector<int> L, R;
vector<hashValue> S;
vector<int> emptyTrees;
vector<hashValue> fullHashLev;

void calcRes(int cur, ll& res){
  if(L[cur] == -1){
    res *= 2;
    res += S[cur].h[0];
    res %= MOD;
  }
  else{
    calcRes(R[cur], res);
    calcRes(L[cur], res);
  }
}

void calcHash(int ind, int lev){
  S[ind].calc(S[L[ind]], S[R[ind]], lev);
}

void init(){
  for(int i=2; sz(randomNums)<2*NUM_HASHES*(MAX_LEV+1); i++){
    bool f = true;
    for(int j=2; j<i; j++)
      f &= i%j != 0;
    if(f)
      randomNums.push_back(i);
  }
  fullHashLev.resize(MAX_LEV+1);
  fullHashLev[0].setOne();
  for(int l=1; l<=MAX_LEV; l++){
    fullHashLev[l].calc(fullHashLev[l-1], fullHashLev[l-1], l);
  }

  S.resize(MAX_LEV+1);
  L.push_back(-1);
  R.push_back(-1);
  emptyTrees.push_back(0);
  for(int l=1; l<=MAX_LEV; l++){
    L.push_back(l-1);
    R.push_back(l-1);
    calcHash(sz(L)-1, l);
    emptyTrees.push_back(l);
  }
}

int searchZeroRightOf(int ind, int cur, int lev=MAX_LEV, int l=0, int r=OFFSET){
  if(l == r)
    return S[cur].h[0] == 0 ? l : -1;
  int m = (l+r)/2;
  if(ind > m)
    return searchZeroRightOf(ind, R[cur], lev-1, m+1, r);
  if(ind < l){
    if(S[L[cur]] == fullHashLev[lev-1])
      return searchZeroRightOf(ind, R[cur], lev-1, m+1, r);
    else
      return searchZeroRightOf(ind, L[cur], lev-1, l, m);
  }
  else{
    int res = searchZeroRightOf(ind, L[cur], lev-1, l, m);
    if(res == -1)
      res = searchZeroRightOf(ind, R[cur], lev-1, m+1, r);
    return res;
  }
}

int setToZero(int l, int r, int cur, int lev=MAX_LEV, int curl=0, int curr=OFFSET){
  if(l > curr || r < curl)
    return cur;
  if(l <= curl && r >= curr){
    return emptyTrees[lev];
  }
  int newInd = sz(S);
  S.push_back(S[cur]);
  L.push_back(L[cur]);
  R.push_back(R[cur]);
  int m = (curl+curr)/2;
  int x = setToZero(l, r, L[newInd], lev-1, curl, m);
  L[newInd] = x;
  x = setToZero(l, r, R[newInd], lev-1, m+1, curr);
  R[newInd] = x;
  calcHash(newInd, lev);
  return newInd;
}

int pointUpdate(int x, int cur, int lev=MAX_LEV, int curl=0, int curr=OFFSET){
  int newInd = sz(S);
  S.push_back(S[cur]);
  L.push_back(L[cur]);
  R.push_back(R[cur]);
  if(lev == 0){
    S[newInd].setOne();
    return newInd;
  }
  int m = (curl+curr)/2;
  if(x <= m){
    int newl = pointUpdate(x, L[newInd], lev-1, curl, m);
    L[newInd] = newl;
  }
  else{
    int newr = pointUpdate(x, R[newInd], lev-1, m+1, curr);
    R[newInd] = newr;
  }
  calcHash(newInd, lev);
  return newInd;
}

ll getD(int n){
  ll res = 0;
  calcRes(n, res);
  return res;
}

int addPower(int root, int pw){
  int k = searchZeroRightOf(pw, root);
  root = setToZero(pw, k-1, root);
  root = pointUpdate(k, root);
  return root;
}

bool compareTrees(int cur1, int cur2){
  if(L[cur1] == -1){
    return S[cur1].h[0] > S[cur2].h[0];
  }
  if(!(S[R[cur1]] == S[R[cur2]])){
    return compareTrees(R[cur1], R[cur2]);
  }
  else
    return compareTrees(L[cur1], L[cur2]);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, M, s, t;
  cin >> N >> M;
  vector<vector<pii>> G(N);
  for(int i=0; i<M; i++){
    int u, v, w;
    cin >> u >> v >> w;
    u--; v--;
    G[u].emplace_back(v, w);
    G[v].emplace_back(u, w);
  }
  cin >> s >> t;
  s--; t--;
  init();
  auto cmp = [](pii x, pii y){ return compareTrees(x.first, y.first); };
  priority_queue<pii, vector<pii>, decltype(cmp)> PQ(cmp);
  vector<int> D(N, -1);
  vector<int> from(N, -1);
  vector<bool> vis(N);
  D[s] = emptyTrees[MAX_LEV];
  PQ.emplace(D[s], s);
  while(!PQ.empty()){
    auto [d, cur] = PQ.top();
    PQ.pop();
    if(d != D[cur])
      continue;
    for(auto [x, w] : G[cur]){
      if(vis[x])
        continue;
      int newD = addPower(D[cur], w);
      if(D[x] == -1 || compareTrees(D[x], newD)){
        D[x] = newD;
        PQ.emplace(D[x], x);
        from[x] = cur;
      }
    }
  }
  if(s!=t && from[t] == -1){
    cout << -1 << endl;
    return 0;
  }
  vector<int> res;
  res.push_back(t);
  while(res.back() != s){
    int nxt = from[res.back()];
    res.push_back(nxt);
  }
  cout << getD(D[t]) << endl;
  cout << sz(res) << endl;
  for(int i=sz(res)-1; i>=0; i--){
    cout << res[i]+1 << " ";
  }
  cout << endl;
}