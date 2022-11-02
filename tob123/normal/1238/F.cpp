#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 3e5+10;

int Q, N;
vector<int> G[n];
int dp[n];

int best;

void dfs(int cur, int par){
  int m1=0, m2=0;
  for(int x : G[cur]){
    if(x != par){
      dfs(x, cur);
      if(dp[x] > m1){
        m2 = m1;
        m1 = dp[x];
      }
      else if(dp[x] > m2){
        m2 = dp[x];
      }
    }
  }
  dp[cur] = 1 + m1 + max(0, sz(G[cur])-2);
  best = max(best, 1 + max(0, sz(G[cur])-2)+m1+m2);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> Q;
  while(Q--){
    cin >> N;
    for(int i=0; i<N; i++){
      G[i].clear();
    }
    best = 1;
    for(int i=0; i<N-1; i++){
      int x, y;
      cin >> x >> y;
      x--; y--;
      G[x].push_back(y);
      G[y].push_back(x);
    }
    dfs(0, -1);
    /*
    for(int i=0; i<N; i++){
      cout << i << ": " << dp[i] << endl;
    }
    */
    cout << best << "\n";
  }

  return 0;
}