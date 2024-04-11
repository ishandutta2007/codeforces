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

const int n = 5e5;

int N, K;
vector<int> A;
ll dp[n]; //0:open, 1:not necessarily open
int cnt[n];

int solve(int c){
  cnt[1] = 1; dp[1] = c;
  for(int i=2; i<=N; i++){
    dp[i] = dp[i-1]+A[i]-A[i-1]; cnt[i] = cnt[i-1];
    if(dp[i] > dp[i-1]+c)
      dp[i] = dp[i-1]+c, cnt[i] = cnt[i-1]+1;
  }
  return cnt[N];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;
  A.resize(N+1);
  for(int i=0; i<N; i++){
    cin >> A[i+1];
  }
  int lo=0, hi=1e9;
  while(lo<hi){
    int m = (lo+hi)/2;
    if(solve(m) > K)
      lo = m+1;
    else
      hi = m;
  }
  solve(hi);
  //cout << lo << " " << hi << " " << dp[N] << endl;
  cout << dp[N]-hi*K << endl;
}