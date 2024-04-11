#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 2e5+10;

int N, K;
vector<vector<int>> G;
int P[n], S[n], D[n];

void dfs(int cur, int par){
  P[cur] = par;
  for(int x : G[cur]){
    if(x != par){
      D[x] = D[cur]+1;
      dfs(x, cur);
      S[cur] += S[x];
    }
  }
  S[cur]++;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;
  G.resize(N);
  for(int i=0; i<N-1; i++){
    int u, v;
    cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(0, -1);
  vector<ll> A(N);
  for(int i=0; i<N; i++){
    A[i] = D[i]-S[i]+1;
    //cout << i+1 << ": " << D[i] << " " << S[i] << " " << A[i] << endl;
  }
  sort(A.rbegin(), A.rend());
  ll res = 0;
  for(int i=0; i<K; i++){
    res += A[i];
  }
  cout << res << endl;
}