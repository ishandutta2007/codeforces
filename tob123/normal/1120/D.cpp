#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int n=200020;

ll N;
vector<ll> G[n];
ll C[n];
ll dp[n][2]; //one left,covered
vector<ll> R;

void printDP(){
  for(int i=0; i<N; i++){
    cout << i << ": " << dp[i][0] << " " << dp[i][1] << endl;
  }
}

void dfs1(int cur, int par){
  if(cur != 0 && G[cur].size() == 1){
    dp[cur][0] = 0;
    dp[cur][1] = C[cur];
    return;
  }
  ll mx = 0;
  for(int x : G[cur]){
    if(x != par){
      dfs1(x, cur);
      ll df = dp[x][1]-dp[x][0];
      if(df > mx){
        mx = df;
      }
      dp[cur][1] += dp[x][1];
    }
  }
  dp[cur][0] = dp[cur][1] - mx;
  dp[cur][1] = min(dp[cur][1], dp[cur][0]+C[cur]);
}

void dfs2(int cur, int par, bool noCPos, bool covPos){
  if(cur != 0 && G[cur].size() == 1){
    if(covPos){
      R.push_back(cur);
    }
    return;
  }
  ll mx = -1;
  ll cnt = 0;
  dp[cur][0] = 0;
  dp[cur][1] = 0;
  for(int x : G[cur]){
    if(x == par){
      continue;
    }
    ll df = dp[x][1]-dp[x][0];
    if(df == mx)
      cnt++;
    else if(df > mx){
      cnt = 1;
      mx = df;
    }
    dp[cur][1] += dp[x][1];
  }
  dp[cur][0] = dp[cur][1] - mx;
  if(covPos && dp[cur][0] + C[cur] <= dp[cur][1]){
    R.push_back(cur);
    noCPos = true;
    if(dp[cur][0]+C[cur] < dp[cur][1]){
      covPos = false;
    }
  }

  for(int x : G[cur]){
    if(x == par)
      continue;
    bool nc, c;
    if(dp[x][1]-dp[x][0] == mx){
      nc = noCPos && cnt > 1;
      c = covPos || cnt > 1;
    }
    else{
      nc = noCPos;
      c = true;
    }
    dfs2(x, cur, nc, c);
  }
  dp[cur][1] = min(dp[cur][1], dp[cur][0]+C[cur]);
}

int main(){
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> C[i];
    if(C[i] == 0)
      R.push_back(i);
  }
  ll a, b;
  for(int i=0; i<N-1; i++){
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs1(0, -1);
  dfs2(0, -1, false, true);
  sort(R.begin(), R.end());
  R.erase(unique(R.begin(), R.end()), R.end());
  //printDP();
  cout << dp[0][1] << " " << R.size() << endl;
  for(ll x : R){
    cout << x+1 << " ";
  }
  cout << endl;

  return 0;
}