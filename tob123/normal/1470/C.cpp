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
ll K;

ll query(int x){
  x = ((x%N)+N)%N + 1;
  cout << "? " << x << endl;
  int y;
  cin >> y;
  return y;
}

void finish(int x){
  x = ((x%N)+N)%N + 1;
  cout << "! " << x << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;
  /*
  vector<int> A(N, K);
  vector<int> B(N);
  for(int x=0; x<10; x++){
    print(A);
    fill(B.begin(), B.end(), 0);
    for(int i=1; i<N; i++){
      B[(i+1)%N] += (A[i]+1)/2;
      B[(i-1)%N] += (A[i])/2;
    }
    B[1] += A[0];
    swap(A, B);
  }
  */
  int st=0, cur=0;
  while(true){
    ll x = query(cur);
    if(x != K)
      break;
    st++;
    cur += st;
  }
  ll x = query(cur);
  if(x < K){
    int l = cur;
    int r = cur+N/2;
    while(l < r){
      int m = (l+r)/2;
      ll z = query(m);
      if(z < K)
        l = m+1;
      else
        r = m;
    }
    finish(l);
  }
  else{
    int l = cur-N/2+1;
    int r = cur+1;
    while(l < r){
      int m = (l+r+1)/2;
      ll z = query(m);
      if(z > K)
        r = m-1;
      else
        l = m;
    }
    finish(l);
  }
}