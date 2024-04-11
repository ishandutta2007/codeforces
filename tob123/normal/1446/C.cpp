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

int solve2(vector<int>&B);


int solve(vector<int>& A){
  //print(A);
  if(sz(A) <= 1)
    return 0;
  vector<vector<int>> B(33);
  for(int i=0; i<sz(A); i++){
    int ind = A[i] == 0 ? 0 : 32-__builtin_clz(A[i]);
    B[ind].push_back(A[i]);
  }
  int cnt = 0;
  for(int i=0; i<sz(B); i++){
    cnt += max(0, sz(B[i])-1);
  }
  int bst = cnt;
  int vis = 0;
  for(int i=0; i<sz(B); i++){
    if(sz(B[i])){
      int offs = cnt+max(0, vis-1)-(sz(B[i])-1);
      if(offs < bst)
        bst = min(bst, solve2(B[i])+offs);
      vis++;
    }
  }
  return bst;
}

int solve2(vector<int>& B){
  if(sz(B) <= 1)
    return 0;
  vector<int> A;
  //print(B);
  for(int x : B){
    A.push_back(x^(1<<(31-__builtin_clz(x))));
  }
  //print(A);
  //cout << endl;
  return solve(A);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  cout << solve(A) << "\n";
}