#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 1010;

int N;
vector<pii> G[n];
vector<pii> G2[n];
vector<tuple<int,int,int>> R;

/*
void buildG2(int cur, int par, int lst){
  int newL = cur;
  if(sz(G[cur]) == 2){
    newL = lst;
  }
  for(auto x : G[cur]){
    if(x.first != par){
      buildG2(x.first, cur, newL);
    }
    else if(sz(G[cur]) != 2 && lst != -1){
      G2[cur].push_back({lst, x.second});
      G2[lst].push_back({cur, x.second});
    }
  }
}
*/
void buildG2(int cur, int par, int lst){
  for(int i=0; i<N; i++){
    G2[i] = G[i];
  }
}

int s2(int cur, int par){
  if(sz(G2[cur]) == 1)
    return cur;
  if(G2[cur][0].first == par)
    return s2(G2[cur][1].first, cur);
  else
    return s2(G2[cur][0].first, cur);
}

pair<int,int> search(int cur, int par){
  int cnt = 0;
  vector<int> res;
  for(auto p : G2[cur]){
    if(p.first == par)
      continue;
    if(cnt == 2)
      break;
    res.push_back(s2(p.first, cur));
    cnt++;
  }
  return make_pair(res[0], res[1]);
}

void rem(int u, int v, int w){
  if(sz(G2[u]) == 1 && sz(G2[v]) == 1){
    R.push_back({u, v, -w});
    return;
  }
  if(sz(G2[u]) == 1){
    pair<int,int> x = search(v, u);
    R.push_back({u, x.first, -w/2});
    R.push_back({u, x.second, -w/2});
    R.push_back({x.first, x.second, w/2});
    return;
  }
  if(sz(G2[v]) == 1){
    rem(v, u, w);
    return;
  }
  pair<int,int> x1 = search(u, v);
  pair<int,int> x2 = search(v, u);
  R.push_back({x1.first, x1.second, w/2});
  R.push_back({x2.first, x2.second, w/2});
  R.push_back({x1.first, x2.second, -w/2});
  R.push_back({x2.first, x1.second, -w/2});
}

int main(){
  cin >> N;
  for(int i=0; i<N-1; i++){
    int u, v, x;
    cin >> u >> v >> x;
    u--; v--;
    G[u].push_back({v, x});
    G[v].push_back({u, x});
  }
  for(int i=0; i<N; i++){
    if(sz(G[i]) == 2){
      if(G[i][0].second != G[i][1].second){
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  for(int i=0; i<N; i++){
    if(sz(G[i]) == 1){
      buildG2(i, -1, -1);
      break;
    }
  }
  for(int i=0; i<N; i++){
    for(auto p : G2[i]){
      if(p.first < i){
        rem(i, p.first, p.second);
      }
    }
  }

  cout << "YES" << endl;
  cout << sz(R) << endl;
  for(auto t : R){
    int a, b, c;
    tie(a, b, c) = t;
    cout << a+1 << " " << b+1 << " " << -c << "\n";
  }
  cout << endl;

  return 0;
}