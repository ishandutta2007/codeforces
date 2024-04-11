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

const int INF = 1e7;
string S;
int T, N;

int cst(int x, int val){
  if((S[(x+N)%N]=='R') ^ val)
    return 1;
  else
    return 0;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> N;
    cin >> S;
    vector<int> dp(N);
    vector<int> A;
    for(int i=0; i<N; i++){
      if(S[i] == 'R' && S[(i+1)%N] == 'L'){
        A.push_back(i);
      }
    }
    int res = 0;
    for(int i=0; i<sz(A); i++){
      if((A[i]+2)%N == A[(i+1)%sz(A)])
        continue;
      int j1 = (A[i]+2)%N, j2 = A[(i+1)%sz(A)];
      int l=0, r=0;
      for(int k=j1; k!=j2; k=(k+1)%N){
        if(S[k] == 'L')
          l++;
        else
          r++;
      }
      res += (l+1)/3 + (r+1)/3;
    }
    if(sz(A) == 0)
      res = (N+2)/3;
    cout << res << "\n";
  }
}