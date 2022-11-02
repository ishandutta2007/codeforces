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

ll inv[50][2];

void solve(vector<int> A, int b){
  if(b < 0 || sz(A) == 0)
    return;
  vector<vector<int>> B(2);
  for(int i=0; i<sz(A); i++){
    B[(A[i]>>b)&1].push_back(i);
  }
  int i0=0, i1=0;
  ll I = 0;
  while(i0 < sz(B[0]) || i1 < sz(B[1])){
    if(i0 == sz(B[0]) || (i1 < sz(B[1]) && B[1][i1] < B[0][i0])){
      i1++;
    }
    else{
      I += sz(B[1])-i1;
      i0++;
    }
  }
  inv[b][1] += I;
  inv[b][0] += ((ll) sz(B[0]))*sz(B[1]) - I;
  for(int i=0; i<2; i++){
    for(int j=0; j<sz(B[i]); j++)
      B[i][j] = A[B[i][j]];
  }
  solve(B[0], b-1);
  solve(B[1], b-1);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i=0; i<N; i++)
    cin >> A[i];
  solve(A, 30);
  /*
  for(int i=0; i<3; i++){
    for(int j=0; j<2; j++)
      cout << inv[i][j] << " ";
    cout << endl;
  }
  */

  int res = 0;
  ll RI = 0;
  for(int i=0; i<=30; i++){
    if(inv[i][1] < inv[i][0]){
      res |= 1<<i;
    }
    RI += min(inv[i][0], inv[i][1]);
  }
  cout << RI << " " << res << endl;
}