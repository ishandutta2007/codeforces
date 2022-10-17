#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  int n,m;
  cin >> n >> m;
  vector<pair<int,int>> e(m);
  vector<vector<int>> g(n);
  int u,v;
  for(int i=0;i<m;i++){
    cin >> u >> v;
    e[i]={u-1,v-1};
    g[u-1].push_back(v-1);
    g[v-1].push_back(u-1);
  }
  queue<pair<int,int>> q;
  vector<int> c(n,-1);
  q.push({0,0});
  c[0]=0;
  while(!q.empty()){
    pair<int,int> p=q.front();
    q.pop();
    for(auto ed:g[p.first]){
      if(c[ed]==-1){
        c[ed]=1-p.second;
        q.push({ed,c[ed]});
      }else{
        if(c[ed]==p.second){
          cout << "NO" << endl;
          return 0;
        }
      }
    }
  }
  cout << "YES" << endl;
  for(int i=0;i<m;i++){
    if(c[e[i].first]==0){
      printf("1");
    }else{
      printf("0");
    }
  }
  printf("\n");
  return 0;
}