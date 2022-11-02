#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, M;
vector<pair<ll, int>> G[200002];
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> PQ;
bool vis[200002];
ll D[200002];

int main(){
  ios_base::sync_with_stdio(false);
  cin >> N >> M;
  int a, b;
  ll w;
  for(int i=0; i<M; i++){
    cin >> a >> b >> w;
    a--; b--;
    G[a].push_back(make_pair(2*w, b));
    G[b].push_back(make_pair(2*w, a));
  }
  for(int i=0; i<N; i++){
    cin >> w;
    PQ.push(make_pair(w, i));
  }

  while(!PQ.empty()){
    auto p = PQ.top();
    PQ.pop();
    if(vis[p.second])
      continue;
    vis[p.second] = true;
    D[p.second] = p.first;
    for(auto nxt : G[p.second]){
      PQ.push(make_pair(nxt.first + p.first, nxt.second));
    }
  }
  for(int i=0; i<N; i++){
    cout << D[i] << " ";
  }
  cout << endl;

  return 0;
}