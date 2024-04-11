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

const int n = 1e6+20;
const ll INF = 1e17;

int N;
ll r1, r2, r3, d;
ll A[n];
ll dp[n][2];
ll c[n][2];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> r1 >> r2 >> r3 >> d;
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  r1 = min(r1, r3);
  dp[N][0] = -d;
  dp[N][1] = INF;
  for(int i=N-1; i>=0; i--){
    c[i][0] = A[i]*r1+r3;
    c[i][1] = min((A[i]+2)*r1, min(r2+r1, c[i][0]));
  }
  dp[N-2][0] = min(c[N-1][0] + c[N-2][0] + d,
      min(c[N-1][1] + c[N-2][1] + 3*d, c[N-1][0] + c[N-2][1] + 2*d));
  dp[N-2][1] = min(dp[N-2][0]+d, c[N-2][1]+c[N-1][0] + 2*d);
  for(int i=N-3; i>=0; i--){
    dp[i][0] = min(c[i][0]+d+dp[i+1][0], c[i][1]+2*d+dp[i+1][1]);
    dp[i][1] = min(dp[i][0]+d, c[i][1]+2*d+dp[i+1][0]);
  }
  cout << dp[0][0] << "\n";
}