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

const int n = 2e5+10;
//const int n = 50;
bitset<n> dp[10];
int m = n/2;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while(T--){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++){
      cin >> A[i];
      A[i] = abs(A[i]);
    }
    if(N == 1){
      if(A[0] == 0)
        cout << "YES\n";
      else
        cout << "NO\n";
      continue;
    }
    int sol = -1;
    for(int st = 0; st<N; st++){
      //cout << st << ":\n";
      for(int i=0; i<10; i++){
        dp[i].reset();
      }
      dp[0].set(m);
      int ind = 0;
      for(int i=0; i<N; i++){
        if(i == st) continue;
        dp[ind+1] = (dp[ind] << A[i]) | (dp[ind] >> A[i]) | dp[ind];
        //cout << dp[ind] << endl;
        ind++;
      }
      if(dp[N-1][m+A[st]]){
        sol = st;
      }
    }
    if(sol == -1){
      cout << "NO\n";
    }
    else{
      cout << "YES\n";
    }
  }
}