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


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T, N, K;
  cin >> T;
  while(T--){
    cin >> N >> K;
    vector<int> A(N+1);
    int cnt = 0;
    A[0] = -1;
    for(int i=1; i<=N; i++){
      cin >> A[i];
      if(A[i] != A[i-1])
        cnt++;
    }
    if(K == 1){
      if(cnt > 1)
        cout << -1 << endl;
      else if(A[1] == 0)
        cout << 0 << endl;
      else
        cout << 1 << endl;
    }
    else{
      cout << max(1, (cnt-1+K-2)/(K-1)) << "\n";
    }
  }
}