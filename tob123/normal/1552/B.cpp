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

const int n = 100001;

int R[n][5];

int best(int a, int b){
  int cnta = 0;
  for(int i=0; i<5; i++){
    if(R[a][i] < R[b][i])
      cnta++;
  }
  return cnta >= 3 ? a : b;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while(T--){
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
      for(int j=0; j<5; j++){
        cin >> R[i][j];
      }
    }
    int bst = 0;
    for(int i=1; i<N; i++){
      bst = best(bst, i);
    }
    bool pos = true;
    for(int i=0; i<N; i++){
      if(i == bst)
        continue;
      pos &= bst == best(bst, i);
    }
    if(pos){
      cout << bst+1 << "\n";
    }
    else
      cout << -1 << "\n";
  }
}