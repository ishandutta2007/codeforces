#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#define PB push_back
#define sz(v) ((v).size())
using namespace std;
typedef long long in;
bool sbb=1;
struct stu{
  in b, c, id;
  bool operator<(const stu cp)const{
    if(sbb){
      if(b!=cp.b)
	return b>cp.b;
      return c<cp.c;
    }
    if(c!=cp.c)
      return c>cp.c;
    return b<cp.b;
  }
};
stu stus[100009];
struct pqe{
  in id;
  pqe(in a){
    id=a;
  }
  bool operator<(const pqe cp)const{
    return stus[id]<stus[cp.id];
  }
};
struct bg{
  in a,id;
  bool operator<(const bg cp)const{
    return a>cp.a;
  }
};
in n,m,s;
bg bgs[100009];
in shd[100009];
in opt[100009];
bool cnd(in d){
  sbb=0;
  priority_queue<pqe> pq;
  in lf=0;
  in crs;
  in sf=0;
  in csf=0;
  for(in nd=0;nd<m;){
    if(lf>0){
      shd[nd]=crs;
      lf--;
      nd++;
      continue;
    }
    while(sf<n && stus[sf].b>=bgs[nd].a){
      pq.push(pqe(sf));
      sf++;
    }
    if(pq.empty())
      return 0;
    crs=pq.top().id;
    pq.pop();
    lf+=d;
    csf+=stus[crs].c;
  }
  if(csf>s)
    return 0;
  return 1;
}
int main(){
  cin>>n>>m>>s;
  for(in i=0;i<m;i++){
    cin>>bgs[i].a;
    bgs[i].id=i;
  }
  sort(bgs,bgs+m);
  for(in i=0;i<n;i++){
    cin>>stus[i].b;
    stus[i].id=i+1;
  }
  for(in i=0;i<n;i++)
    cin>>stus[i].c;
  sort(stus,stus+n);
  bool doable=0;
  for(in i=0;i<n;i++)
    if(stus[i].b>=bgs[0].a && stus[i].c<=s)
      doable=1;
  if(!doable){
    cout<<"NO"<<endl;
    return 0;
  }
  else
    cout<<"YES"<<endl;
  in mn=0;
  in mx=100009;
  in md;
  while(mx-mn>1){
    md=(mx+mn)/2;
    if(cnd(md))
      mx=md;
    else
      mn=md;
  }
  assert(cnd(mx));
  for(in i=0;i<m;i++){
    opt[bgs[i].id]=stus[shd[i]].id;
  }
  for(in i=0;i<m;i++){
    cout<<opt[i];
    if(i!=m-1)
      cout<<" ";
  }
  cout<<endl;
  return 0;
}