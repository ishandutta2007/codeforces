#include<bits/stdc++.h>
using namespace std;
 
map<int,int>pa, d;
 
int GP(int x){
  if (!pa.count(x)) return x;
  int aim=GP(pa[x]);
  d[x]^=d[pa[x]];
  return pa[x]=aim;
}
int GD(int x){
  if (!pa.count(x)) return 0;
  return d[x]^GD(pa[x]);
}
 
int main(){
  int T, u, v, pu, pv, t, x, ans=0;
  for (cin>>T;T--;){
    scanf("%d%d%d",&t,&u,&v);
    u^=ans; v^=ans; if (u>v) swap(u,v); --u;
    if (t==1){
      scanf("%d",&x); x^=ans;
      if ((pu=GP(u))==(pv=GP(v))) continue;
      d[pv]= x^GD(u)^GD(v);
      pa[pv]=pu;
    }else{
      if ((pu=GP(u))==(pv=GP(v))) printf("%d\n",ans=GD(u)^GD(v));
      else puts("-1"), ans=1;
    }
  }
}
//copy from zhangzy