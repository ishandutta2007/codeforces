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

int N;
vector<int> A;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  set<int> X;
  A.resize(N);
  for(int i=0; i<N; i++){
    cin >> A[i];
    X.insert(A[i]);
  }
  int lo = 0;
  vector<int> res;
  for(int i=0; i<N; i++){
    if(i == 0 || A[i] == A[i-1]){
      while(X.count(lo)) lo++;
      res.push_back(lo++);
    }
    else{
      res.push_back(A[i-1]);
    }
  }
  for(int x : res)
    cout << x << " ";
  cout << endl;
}