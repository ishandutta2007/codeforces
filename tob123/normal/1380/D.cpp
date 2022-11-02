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
  int N, M, K;
  ll X, Y;
  cin >> N >> M;
  cin >> X >> K >> Y;
  vector<int> A(N+1);
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  A[N] = 0;
  vector<int> B(M+2);
  for(int i=1; i<=M; i++){
    cin >> B[i];
  }
  B[M+1] = 0;
  int ai=0;
  ll C = 0;
  for(int i=1; i<=M+1; i++){
    int st = ai;
    int m = -1;
    while(ai <= N && A[ai] != B[i]){
      m = max(m, A[ai]);
      ai++;
    }
    if(ai == N+1){
      cout << -1 << endl; return 0;
    }
    ll cnt = ai-st;
    if(m > B[i-1] && m > B[i]){
      if(cnt < K){
        cout << -1 << endl; return 0;
      }
      C += X;
      cnt -= K;
    }
    if(Y*K <= X){
      C += Y*cnt;
    }
    else{
      C += cnt/K*X + cnt%K*Y;
    }
    ai++;
  }
  cout << C << "\n";
}