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
  int T, N;
  cin >> T;
  while(T--){
    cin >> N;
    vector<int> A(N), B(N), C(N);
    for(int i=0; i<sz(A); i++)
      cin >> A[i];
    for(int i=0; i<sz(B); i++)
      cin >> B[i];
    for(int i=0; i<sz(C); i++)
      cin >> C[i];
    vector<int> P(N);
    for(int i=0; i<N; i++){
      P[i] = A[i];
      if(i && P[i] == P[i-1]){
        P[i] = B[i];
      }
    }
    if(P[0] != A[N-1] && P[N-2] != A[N-1])
      P[N-1] = A[N-1];
    else if(P[0] != B[N-1] && P[N-2] != B[N-1])
      P[N-1] = B[N-1];
    else if(P[0] != C[N-1] && P[N-2] != C[N-1])
      P[N-1] = C[N-1];
    for(int i=0; i<sz(P); i++)
      cout << P[i] << " ";
    cout << "\n";
  }
}