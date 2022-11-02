#include <bits/stdc++.h>
using namespace std;

typedef tuple<int,int,int> ti;

const int n = 1e5+10;

int N, M, K, res;
int X[n];
vector<ti> E;
int D[n];
int sz[n], cmp[n];

int find(int x){
  if(cmp[x] != x)
    cmp[x] = find(cmp[x]);
  return cmp[x];
}

void merge(int a, int b){
  sz[find(b)] += sz[find(a)];
  cmp[find(a)] = find(b);
}

int main(){
  cin >> N >> M >> K;
  for(int i=0; i<K; i++){
    cin >> X[i];
    X[i]--;
  }

  for(int i=0; i<N; i++){
    cmp[i] = i;
  }
  for(int i=0; i<K; i++){
    sz[X[i]] = 1;
  }

  for(int i=0; i<M; i++){
    int u, v, w;
    cin >> u >> v >> w;
    u--; v--;
    E.push_back(make_tuple(w, u, v));
  }
  sort(E.begin(), E.end());
  for(int i=0; i<M; i++){
    int w, u, v;
    tie(w, u, v) = E[i];
    if(find(u) != find(v)){
      if(sz[find(u)] + sz[find(v)] == K){
        res = w;
        break;
      }
      merge(u, v);
    }
  }
  
  for(int i=0; i<K; i++){
    cout << res << " ";
  }
  cout << endl;

  return 0;
}