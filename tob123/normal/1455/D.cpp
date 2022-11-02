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

const int n = 505;

bool mon[n][n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while(T--){
    int N, X;
    cin >> N >> X;
    vector<int> A(N+1, 0);
    for(int i=1; i<=N; i++)
      cin >> A[i];
    for(int i=1; i<=N; i++){
      mon[i][i] = true;
      for(int j=i+1; j<=N; j++){
        mon[i][j] = mon[i][j-1] && A[j] >= A[j-1];
      }
    }
    int op = 0;
    bool pos = true;
    for(int i=1; i<=N; i++){
      if(A[i] >= A[i-1] && mon[i][N]){
        break;
      }
      if(X < A[i]){
        swap(A[i], X);
        op++;
      }
      pos &= A[i] >= A[i-1];
    }
    if(pos){
      cout << op << "\n";
    }
    else
      cout << -1 << "\n";
  }
}