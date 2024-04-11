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

int posOf(vector<int>& A, int x){
  for(int i=0; i<sz(A); i++)
    if(A[i] == x) return i;
  return -10000;
}

vector<int> doOp(vector<int> A, vector<int> op){
  vector<vector<int>> zw;
  int curI = 0;
  for(int x : op){
    zw.push_back(vector<int>());
    for(int i=0; i<x; i++){
      zw.back().push_back(A[curI++]);
    }
  }
  reverse(zw.begin(), zw.end());
  vector<int> res;
  for(auto k : zw)
    for(int x : k)
      res.push_back(x);
  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i=0; i<N; i++){
    cin >> A[i];
    A[i]--;
  }
  vector<vector<int>> res;
  for(int i=0; i<N-1; i++){
    int p = posOf(A, i);
    vector<int> op;
    if(i % 2){
      for(int j=0; j<i; j++)
        op.push_back(1);
      op.push_back(N-p-i);
      op.push_back(p);
      reverse(op.begin(), op.end());
    }
    else{
      for(int j=0; j<i; j++)
        op.push_back(1);
      op.push_back(p+1-i);
      op.push_back(N-p-1);
    }
    res.push_back(op);
    A = doOp(A, op);
    //print(op);
    //print(A);
  }
  if(!is_sorted(A.begin(), A.end())){
    vector<int> op;
    for(int i=0; i<N; i++)
      op.push_back(1);
    res.push_back(op);
  }
  vector<vector<int>> res2;
  for(auto z : res){
    int cnt = 0;
    for(int x : z)
      if(x) cnt++;
    if(cnt >= 2){
      res2.push_back(vector<int>());
      for(int x : z){
        if(x) res2.back().push_back(x);
      }
    }
  }
  cout << sz(res2) << endl;
  for(auto z : res2){
    cout << sz(z);
    for(int x : z){
      cout << " " << x;
    }
    cout << "\n";
  }
}