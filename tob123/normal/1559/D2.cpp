#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
typedef long long ll;
typedef pair<int,int> pii;
template<class T> void print(T & x){ cout << x; }
template<class T,class U> void print(pair<T,U> & p){cout << "("; print(p.first); cout << ", "; print(p.second); cout << ")"; }
template<class T> void print(set<T> & v) {
  cout << "{";
  for (auto x : v) cout << ", ", print(x);
  cout << "}\n";
}
template<class T> void print(vector<T> & v) {
  cout << "{";
  if (sz(v)) print(v[0]);
  for (int i = 1; i < sz(v); i++) cout << ", ", print(v[i]);
  cout << "}\n";
}

#define MAXN 100100

int m[2];
int n, p[2][MAXN];
vector<set<int>> s[2];
vector<pii> res;
set<pii> setS[2];

void init() {
  for(int k=0; k<2; k++){
    s[k].resize(n);
    for (int i = 0; i < n; i++){
      p[k][i] = i, s[k][i].insert(i);
      setS[k].emplace(1, i);
    }
  }
}

int findSet(int k, int i) {
  return p[k][i];
}

bool inSameSet(int k, int i, int j) {
  return findSet(k, i) == findSet(k, j);
}

void unionSet(int k, int i, int j) {
  i = findSet(k, i), j = findSet(k, j);
  if (i != j) {
    setS[k].erase(make_pair(sz(s[k][i]), i));
    setS[k].erase(make_pair(sz(s[k][j]), j));
    if (sz(s[k][i]) < sz(s[k][j]))
      swap(i, j);
    for(int x : s[k][j]){
      s[k][i].insert(x);
      p[k][x] = i;
    }
    s[k][j].clear();
    setS[k].emplace(make_pair(sz(s[k][i]), i));
  }
}

void unionSet2(int i, int j){
  res.emplace_back(i, j);
  if(inSameSet(0, i, j) || inSameSet(1, i, j))
    cerr << "fail " << inSameSet(0, i, j) << endl;
  unionSet(0, i, j);
  unionSet(1, i, j);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m[0] >> m[1];
  init();
  for(int k=0; k<2; k++){
    for(int i=0; i<m[k]; i++){
      int u, v;
      cin >> u >> v;
      u--; v--;
      unionSet(k, u, v);
    }
  }
  if(m[0] < m[1]){
    swap(m[0], m[1]);
    swap(s[0], s[1]);
    swap(p[0], p[1]);
    swap(setS[0], setS[1]);
  }
  while(sz(setS[0]) > 1){
    //cout << "----------------------\n";
    //print(s[0]);
    //print(s[1]);
    auto [cnt, ind] = *(setS[0].begin());
    int s1=-1, i1, s2=-1, i2;
    for(int x : s[0][ind]){
      int in = p[1][x];
      if(s1 == -1){
        s1 = in; i1 = x;
      }
      if(in != s1){
        s2 = in; i2 = x;
      }
    }
    //cout << "setInd: " << ind << endl;
    //cout << "s,i: " << s1 << " " << i1 << " " << s2 << " " << i2 << endl;
    if(s2 == -1){
      auto x = setS[1].begin()->second;
      auto y = (++setS[1].begin())->second;
      if(x == s1)
        x = y;
      int nxt = *s[1][x].begin();
      unionSet2(i1, nxt);
    }
    else{
      auto [cnt2, ind2] = *(++(setS[0].begin()));
      int x = *s[0][ind2].begin();
      if(p[1][x] == s1){
        unionSet2(i2, x);
      }
      else{
        unionSet2(i1, x);
      }
    }
  }
  cout << sz(res) << endl;
  for(auto [x, y] : res){
    cout << x+1 << " " << y+1 << "\n";
  }
}