#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
typedef long long ll;
typedef pair<int,int> pii;
template<class T> void print(T & x){ cout << x+1; }
template<class T,class U> void print(pair<T,U> & p){cout << "("; print(p.first); cout << ", "; print(p.second); cout << ")"; }
template<class T> void print(vector<T> & v) {
  cout << "{";
  if (sz(v)) print(v[0]);
  for (int i = 1; i < sz(v); i++) cout << ", ", print(v[i]);
  cout << "}\n";
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N;
  vector<vector<int>> A(N);
  for(int i=0; i<N; i++){
    int c;
    cin >> c;
    A[i].resize(c);
    for(int j=0; j<c; j++){
      cin >> A[i][j];
    }
  }
  cin >> M;
  set<vector<int>> S;
  bool someBst = false;
  for(int i=0; i<M; i++){
    vector<int> b(N);
    bool bst = true;
    for(int j=0; j<N; j++){
      cin >> b[j];
      bst &= b[j] == sz(A[j]);
      b[j]--;
    }
    S.insert(b);
    someBst |= bst;
  }
  if(!someBst){
    for(int i=0; i<N; i++){
      cout << sz(A[i]) << " ";
    }
    cout << endl;
    return 0;
  }
  ll bst = 0; 
  vector<int> B;
  for(auto b : S){
    ll sum = 0;
    for(int i=0; i<N; i++){
      sum += A[i][b[i]];
    }
    for(int i=0; i<N; i++){
      if(b[i] > 0){
        ll cur = sum - A[i][b[i]];
        b[i]--;
        cur += A[i][b[i]];
        if(S.count(b) == 0 && cur > bst){
          bst = cur;
          B = b;
        }
        b[i]++;
      }
    }
  }
  for(int x : B){
    cout << x+1 << " ";
  }
  cout << endl;
}