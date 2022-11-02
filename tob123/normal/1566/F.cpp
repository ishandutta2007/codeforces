#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
typedef long long ll;
typedef pair<ll,ll> pii;
template<class T> void print(T & x){ cout << x; }
template<class T,class U> void print(pair<T,U> & p){cout << "("; print(p.first); cout << ", "; print(p.second); cout << ")"; }
template<class T> void print(vector<T> & v) {
  cout << "{";
  if (sz(v)) print(v[0]);
  for (int i = 1; i < sz(v); i++) cout << ", ", print(v[i]);
  cout << "}\n";
}

ll INF = 1e11;

ll solve(vector<vector<ll>> dp){
  //print(dp);
  if(sz(dp) == 1){
    ll res = INF;
    for(int i=0; i<4; i++)
      res = min(res, dp[0][i]);
    return res;
  }
  vector<vector<ll>> res;
  for(int i=0; i<sz(dp)-1; i+=2){
    vector<ll> cur(4, INF);
    for(int a=0; a<2; a++){
      for(int b=0; b<2; b++){
        for(int c=0; c<2; c++){
          int i1 = 2*a+b;
          int i2 = 2*b+c;
          int ri = 2*a + c;
          cur[ri] = min(cur[ri], dp[i][i1] + dp[i+1][i2]);
        }
      }
    }
    res.push_back(cur);
  }
  if(sz(dp)%2)
    res.push_back(dp.back());
  return solve(res);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T, N, M;
  cin >> T;
  while(T--){
    cin >> N >> M;
    vector<ll> A(N+2);
    vector<pii> s(M);
    for(int i=1; i<=N; i++){
      cin >> A[i];
    }
    A[0] = -1e11;
    A[N+1] = 1e11;
    for(int i=0; i<M; i++){
      cin >> s[i].first >> s[i].second;
      s[i].second *= -1;
    }
    sort(A.begin(), A.end());
    sort(s.begin(), s.end());
    vector<pii> s2;
    for(auto [a, b] : s){
      b *= -1;
      while(sz(s2) && s2.back().second >= b)
        s2.pop_back();
      s2.emplace_back(a, b);
    }
    //print(s);
    s = move(s2);
    //print(s);
    int si = 0;
    vector<vector<ll>> dp(N+1, vector<ll>(4, INF));
    for(int i=0; i<=N; i++){
      while(si < sz(s) && s[si].first <= A[i])
        si++;
      ll lst = -INF;
      while(si < sz(s) && s[si].second < A[i+1]){
        ll c1 = max(0ll, lst - A[i]);
        ll c2 = A[i+1] - s[si].second;
        for(int j=0; j<2; j++){
          for(int k=0; k<2; k++){
            ll c = (2-j)*c1 + (k+1)*c2;
            dp[i][2*j+k] = min(dp[i][2*j+k], c);
          }
        }
        lst = s[si].first;
        si++;
      }
      for(int j=0; j<2; j++){
        for(int k=0; k<2; k++){
          ll c1 = max(0ll, lst-A[i]);
          ll c2 = 0;
          ll c = (2-j)*c1 + (k+1)*c2;
          dp[i][2*j+k] = min(dp[i][2*j+k], c);
        }
      }
    }
    //print(dp);
    cout << solve(dp) << "\n";
  }
}