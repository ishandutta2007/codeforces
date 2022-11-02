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

ll M;
int N;

ll ch[404][404];
ll dp[404][404];
ll dp2[404][404];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  dp2[1][0] = 1;
  for(int l=2; l<=N; l++){
    dp2[l][0] = 1;
    for(int k=1; k<l; k++){
      for(int j=0; j<k; j++){
        dp2[l][k] += dp2[l-1][j];
      }
      dp2[l][k] %= M;
    }
  }

  ch[0][0] = 1;
  for(int i=1; i<=N; i++){
    ch[i][0] = 1;
    for(int j=1; j<=i; j++){
      ch[i][j] = (ch[i-1][j]+ch[i-1][j-1])%M;
    }
  }
  for(int i=1; i<=N; i++){
    for(int j=0; j<i; j++)
      dp[i][i] += dp2[i][j];
    dp[i][i] %= M;
    //cout << i << " -> " << dp[i][i] << endl;
  }
  for(int l=2; l<=N; l++){
    for(int cnt=2; cnt<l; cnt++){
      for(int cur=1; cur<cnt; cur++){
        (dp[l][cnt] += dp[cur][cur]*dp[l-cur-1][cnt-cur]%M*ch[cnt][cur]) %= M;
      }
    }
  }
  /*
  for(int l=1; l<=N; l++){
    for(int cnt=0; cnt<=N; cnt++){
      cout << dp[l][cnt] << " ";
    }
    cout << endl;
  }
  */
  ll res = 0;
  for(int i=1; i<=N; i++){
    res += dp[N][i];
  }
  res %= M;
  cout << res << endl;
}