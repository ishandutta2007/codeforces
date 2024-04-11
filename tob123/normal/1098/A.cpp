#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int n = 1e5+10;
const ll INF = 1e18;

int N;
ll S[n];
int P[n];
vector<int> G[n];
ll res = 0;

void dfs(int cur){
  ll m = INF;
  ll cnt = 0;
  for(int x : G[cur]){
    dfs(x);
    if(S[x] != INF){
      cnt++;
      if(S[x] < m){
        m = S[x];
      }
    }
  }
  if(S[cur] > m){
    cout << -1 << endl;
    exit(0);
  }
  if(S[cur] == -1){
    if(cnt > 0){
      S[cur] = m;
      res -= cnt * m;
      res += S[cur];
    }
    else{
      S[cur] = INF;
    }
  }
  else{
    if(cnt > 0){
      res -= cnt * S[cur];
      res += S[cur];
    }
    else{
      res += S[cur];
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for(int i=1; i<N; i++){
    cin >> P[i];
    P[i]--;
    G[P[i]].push_back(i);
  }
  for(int i=0; i<N; i++){
    cin >> S[i];
  }
  dfs(0);
  /*
  for(int i=0; i<N; i++){
    cout << S[i] << " ";
  }
  cout << endl;
  */
  cout << res << endl;

  return 0;
}