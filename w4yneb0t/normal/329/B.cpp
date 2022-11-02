#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<vector>
using namespace std;
typedef long long in;
const in inf=1000000000000LL;
char mar[1009][1009];
bool vis[1009][1009];
in btm[1009][1009];
in d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
in r,c;
struct spt{
  in x,y,t;
  bool operator<(const spt cp)const{
    if(t!=cp.t)
      return t>cp.t;
    if(mar[y][x]=='S')
      return true;
    return false;
  }
};
int main(){
  cin>>r>>c;
  in res=0;
  spt tp,pp;
  for(in i=0;i<r;i++){
    cin>>mar[i];
    for(in j=0;j<c;j++){
      vis[i][j]=false;
      btm[i][j]=inf;
      if(mar[i][j]=='E'){
        tp.x=j;
        tp.y=i;
        tp.t=0;
      }
    }
  }
  priority_queue<spt> pq;
  pq.push(tp);
  while(!pq.empty()){
    tp=pq.top();
    pq.pop();
    if(vis[tp.y][tp.x])
      continue;
    if(mar[tp.y][tp.x]=='S')
      break;
    if(mar[tp.y][tp.x]!='E')
      res+=mar[tp.y][tp.x]-'0';
    vis[tp.y][tp.x]=true;
    for(in i=0;i<4;i++){
      pp.x=tp.x+d[i][0];
      pp.y=tp.y+d[i][1];
      pp.t=tp.t+1;
      if(pp.x<0 || pp.x>=c || pp.y<0 || pp.y>=r || mar[pp.y][pp.x]=='T' || btm[pp.y][pp.x]<=pp.t)
        continue;
      btm[pp.y][pp.x]=pp.t;
      pq.push(pp);
    }
  }
  cout<<res<<endl;
  return 0;
}