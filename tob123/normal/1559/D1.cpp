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

#define MAXN 100100

int m[2];
int n, p[2][MAXN], s[2][MAXN];

void init() {
  for (int i = 0; i < n; i++)
    p[0][i] = p[1][i] = i, s[0][i] = s[1][i] = 1;
}

int findSet(int k, int i) {
  return p[k][i] == i ? i : (p[k][i] = findSet(k, p[k][i]));
}

bool inSameSet(int k, int i, int j) {
  return findSet(k, i) == findSet(k, j);
}

int getSizeOfSet(int k, int i) {
  return s[k][findSet(k, i)];
}

void unionSet(int k, int i, int j) {
  i = findSet(k, i), j = findSet(k, j);
  if (i != j) {
    if (s[k][i] < s[k][j])
      swap(i, j);
    s[k][i] += s[k][j];
    p[k][j] = i;
  }
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
  vector<pii> res;
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      if(!inSameSet(0, i, j) && !inSameSet(1, i, j)){
        res.emplace_back(i, j);
        unionSet(0, i, j);
        unionSet(1, i, j);
      }
    }
  }
  cout << sz(res) << endl;
  for(auto [x, y] : res){
    cout << x+1 << " " << y+1 << "\n";
  }
}