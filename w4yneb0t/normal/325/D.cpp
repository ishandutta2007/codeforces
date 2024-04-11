#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cstdio>
#include<queue>
#include<cassert>
using namespace std;
typedef long long in;
in tm[1000];
const in ct=3001;
bool tk[9090009];
in dt[8][2]={{-1,-1},{-1,0},{-1,1},{0,1},{0,-1},{1,-1},{1,0},{1,1}};
in n,r,c;
struct eg{
  in dt;
  in of;
};
eg pr[9090009];
in ht[9090009];
eg find(in a){
  in ta=a;
  in tof=0;
  while(pr[a].dt!=a){
    tof+=pr[a].of;
    a=pr[a].dt;
  }
  eg r;
  r.dt=a;
  r.of=tof;
  a=ta;
  tof=0;
  while(pr[a].dt!=a){
    a=pr[a].dt;
    pr[ta].dt=r.dt;
    in ttf=pr[ta].of;
    pr[ta].of=r.of-tof;
    tof+=ttf;
    ta=a;
  }
  return r;
}
void uni(in a, in b, in cof){//a.x=b.x+cof
  //cout<<a<<" "<<b<<" "<<cof<<endl;
  eg ta=find(a);
  eg tb=find(b);
  if(ta.dt==tb.dt)
    return;
  if(ht[ta.dt]>ht[tb.dt]){
    uni(b,a,-cof);
    return;
  }
  pr[ta.dt].dt=tb.dt;
  if(ht[ta.dt]==ht[tb.dt])
    ht[tb.dt]++;
  pr[ta.dt].of=tb.of-ta.of+cof;
}
bool ist(in a, in b, in cof){
  //cout<<a<<" "<<b<<" "<<cof<<endl;
  eg ta=find(a);
  eg tb=find(b);
  //cout<<ta.dt<<" "<<tb.dt<<endl;
  if(ta.dt!=tb.dt)
    return false;
  in rdb=tb.of-ta.of+cof;
  if(rdb%c!=0){
    cout<<rdb<<" "<<c<<" "<<rdb%c<<endl;
    assert(false);
  }
  return rdb!=0;
}
bool ok(in x, in y){
  //cout<<x<<" "<<y<<endl;
  in tx,ty,a1,a2;
  if(c==1)
    return false;
  if(c==2){
    for(in i=-1;i<=1;i++){
      tx=(x+1)%c;
      ty=y+i;
      if(ty<0 || ty>=r)
        continue;
      a1=tx*ct+ty;
      if(!tk[a1])
        continue;
      return false;
    }
    return true;
  }
  for(in i=0;i<8;i++){
    tx=(x+dt[i][0]+c)%c;
    ty=y+dt[i][1];
    if(ty<0 || ty>=r)
      continue;
    a1=tx*ct+ty;
    if(!tk[a1])
      continue;
    for(in j=i+1;j<8;j++){
      tx=(x+dt[j][0]+c)%c;
      ty=y+dt[j][1];
      if(ty<0 || ty>=r)
        continue;
      a2=tx*ct+ty;
      if(!tk[a2])
        continue;
      if(ist(a1,a2,dt[i][0]-dt[j][0])){
        //if(x==2 && y==1)
          //cout<<"wut "<<a1<<" "<<a2<<endl;
        return false;
      }
    }
  }
  return true;
}
void add(in x, in y){
  in p=x*ct+y;
  in tx,ty,a1,a2;
  for(in i=0;i<8;i++){
    tx=(x+dt[i][0]+c)%c;
    ty=y+dt[i][1];
    if(ty<0 || ty>=r)
      continue;
    a1=tx*ct+ty;
    if(!tk[a1])
      continue;
    uni(p,a1,-dt[i][0]);
  }
  in rla=x*ct+y;
  tk[rla]=true;
}
int main(){
  bool debug=false;
  in x,y;
  cin>>r>>c>>n;
  in ntk=0;
  in ta;
  for(in i=0;i<r;i++){
    for(in j=0;j<c;j++){
      ta=j*ct+i;
      pr[ta].dt=ta;
      pr[ta].of=0;
      ht[ta]=0;
    }
  }
  for(in i=0;i<n;i++){
    if(debug){
      y=rand()%r+1;
      x=rand()%c+1;
    }
    else
      cin>>y>>x;
    x--;
    y--;
    if(ok(x,y)){
      //cout<<"yep"<<endl;
      add(x,y);
      ntk++;
    }
    //else
      //cout<<"nope"<<endl;
  }
  cout<<ntk<<endl;
  return 0;
}