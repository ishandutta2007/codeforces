#include <bits/stdc++.h>

using namespace std;

const int N=3e5+10;
const int inf=1e9+10;


int n,m;
int h[N],mark[N];
vector <int> v[N],a[N];

void add_edge(int x,int y){
  v[x].push_back(y);
}


queue <int> q;
bool check(){
  for(int i=1;i<n;i++){
    int len=min(a[i].size(),a[i+1].size());
    for(int j=0;j<len-1;j++){
      int v1=h[a[i][j]]*m+a[i][j];
      int v2=h[a[i+1][j]]*m+a[i+1][j];
      if (v1>v2) return 0;
      if (v1<v2) break;
    }
  }
  return 1;
}
void BFS(int st){
  q.push(st);
  mark[st]=1;
  while (!q.empty()){
    int x=q.front();q.pop();
    for(auto y:v[x]) if (!mark[y]){
      h[y]=0;
      mark[y]=1;
      q.push(y);
    }
  }
}
int main(){
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    int n1,val;
    cin>>n1;
    while (n1--){
      cin>>val;
      a[i].push_back(val);
    }
    a[i].push_back(0);
  }
  fill(h+1,h+m+1,1);
  for(int i=1;i<n;i++){
    int idx=0;
    int len=min(a[i].size(),a[i+1].size());
    while (idx<len-1&&a[i][idx]==a[i+1][idx]) idx++;
    if (a[i+1][idx]==0&&a[i][idx]>0){
      cout<<"No";
      return 0;
    }
    if (a[i][idx]<a[i+1][idx])
      add_edge(a[i+1][idx],a[i][idx]);
    else h[a[i][idx]]=0;
  }
  for(int i=1;i<=m;i++) if (!h[i]&&!mark[i]) BFS(i);
  if (check()){
    cout<<"Yes\n"<<count(h+1,h+m+1,0)<<'\n';
    for(int i=1;i<=m;i++) if (!h[i]) cout<<i<<" ";
  }else cout<<"No\n";
}