#include <bits/stdc++.h>
using namespace std;
const int N=1005;
vector<vector<int>> g(N);
bool ok=1;
void DFS(int v){
  int cnt=0;
  for(auto c:g[v]){
    if(g[c].size()==0)cnt++;
    else DFS(c);
  }
  if(cnt<3)ok=0;
}
int main(){
  int n;
  cin>>n;
  for(int i=0;i<n-1;i++){
    int u;
    cin>>u;
    --u;
    g[u].push_back(i+1);
  }  
  DFS(0);
  if(ok)cout<<"Yes";
  else cout<<"No";
}