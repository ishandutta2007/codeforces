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

typedef bitset<1024> BS;

int N, S, D;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> S >> D;
  vector<BS> A(S);
  for(int i=0; i<S; i++){
    int c, x;
    cin >> c;
    for(int j=0; j<c; j++){
      cin >> x;
      x--;
      A[i].set(x);
    }
  }
  unordered_map<BS, int> M;
  int fstCnt = min(S, 18);
  for(int m=0; m<1<<(fstCnt); m++){
    BS cur;
    for(int i=0; i<fstCnt; i++){
      if((m>>i) & 1){
        cur ^= A[i];
      }
    }
    if(M.count(cur)){
      M[cur] = min(M[cur], __builtin_popcount(m));
    }
    else
      M[cur] = __builtin_popcount(m);
  }
  vector<pair<BS,int>> Z;
  for(int m=0; m<1<<(S-fstCnt); m++){
    BS cur;
    for(int i=0; i<S-fstCnt; i++){
      if((m>>i) & 1){
        cur ^= A[fstCnt+i];
      }
    }
    Z.emplace_back(cur, __builtin_popcount(m));
  }
  for(int d=0; d<D; d++){
    int bst = 1e9;
    BS cur;
    int c, x;
    cin >> c;
    for(int i=0; i<c; i++){
      cin >> x; x--;
      cur.set(x);
    }
    for(auto [bs, cnt] : Z){
      BS b2 = bs ^ cur;
      if(M.count(b2)){
        bst = min(bst, cnt + M[b2]);
      }
    }
    if(bst > 100000){
      cout << "-1\n";
    }
    else
      cout << bst << "\n";
  }
}