#include <iostream>
#include <queue>
using namespace std;
const int nmax=401;
int way[nmax][nmax];
int n,i,j,m,u,v,x;
int step[nmax];
queue <int> q;
main(){
 cin>>n>>m;
 x=1;
 for (i=1;i<=m;i++){
  cin>>u>>v;
  way[u][v]=way[v][u]=1;
  if (u==1 && v==n || u==n && v==1) x=0;               
 }
 step[1]=0;
 for (i=2;i<=n;i++) step[i]=-1;
 q.push(1); 
 while (q.size()>0){
  u=q.front(); q.pop();
  for (v=1;v<=n;v++)
   if (way[u][v]==x)
    if (step[v]==-1){
     step[v]=step[u]+1;            
     q.push(v); 
    }   
 }
 cout<<step[n]<<endl;
}