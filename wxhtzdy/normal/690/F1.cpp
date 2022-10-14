#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  scanf("%i", &N);
  vector<vector<int>> g(N);
  int deg[N];
  for(int i=0;i<N;i++)deg[i]=0;
  for(int i=0;i<N-1;i++){
    int u,v;
    scanf("%i%i",&u,&v);
    --u; --v;
    ++deg[u]; ++deg[v];
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int res=0;
  for(int i=0;i<N;i++){
    for(auto c:g[i]){
      res+=deg[c]-1;
    }
  }
  printf("%i",res/2);
}