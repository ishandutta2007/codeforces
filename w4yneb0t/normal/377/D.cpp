#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#define MX (1LL<<19)
#define PB push_back
#define sz(v) ((v).size())
using namespace std;
typedef long long in;
in best=0;
in bestx,besty;
struct wkr{
  in l,v,r;
};
struct evt{
  bool ads;
  in loc;
  in l,r;
  bool operator<(const evt cp)const{
    if(loc!=cp.loc)
      return loc<cp.loc;
    if(ads!=cp.ads)
      return ads;
    return l<cp.l;
  }
};
wkr wkrs[100009];
evt evts[200009];
in n;
int llm[2*MX];
int rlm[2*MX];
int tov[2*MX];
int bev[2*MX];
void upd(in i){
  if(i==0)
    return;
  bev[i]=(bev[2*i]>bev[2*i+1]?bev[2*i]:bev[2*i+1]);
  bev[i]+=tov[i];
  upd(i/2);
}
bool ckbest(){
  if(bev[1]>best){
    best=bev[1];
    in i=1;
    while(i<MX){
      i*=2;
      if(bev[i+1]>bev[i])
	i++;
    }
    bestx=i-MX;
    return 1;
  }
  return 0;
}
void ad(in i, in l, in r, in fc){
  if(llm[i]>r || rlm[i]<l)
    return;
  if(llm[i]>=l  && rlm[i]<=r){
    tov[i]+=fc;
    bev[i]+=fc;
    upd(i/2);
    return;
  }
  ad(2*i,l,r,fc);
  ad(2*i+1,l,r,fc);
}
void proc(evt tv){
  in fc=(tv.ads?1:-1);
  ad(1,tv.l,tv.r,fc);
}
in sol[100009];
in solc=0;
int main(){
  for(in i=MX;i<2*MX;i++){
    llm[i]=rlm[i]=i-MX;
  }
  for(in i=MX-1;i>=1;i--){
    llm[i]=llm[2*i];
    rlm[i]=rlm[2*i+1];
  }
  for(in i=1;i<2*MX;i++){
    tov[i]=0;
    bev[i]=0;
  }
  cin>>n;
  for(in i=0;i<n;i++)
    cin>>wkrs[i].l>>wkrs[i].v>>wkrs[i].r;
  for(in i=0;i<n;i++){
    evt stt;
    stt.loc=wkrs[i].v;
    stt.ads=1;
    stt.l=wkrs[i].l;
    stt.r=wkrs[i].v;
    evts[2*i]=stt;
    stt.ads=0;
    stt.loc=wkrs[i].r;
    evts[2*i+1]=stt;
  }
  sort(evts,evts+2*n);
  for(in i=0;i<2*n;i++){
    proc(evts[i]);
    if(ckbest())
      besty=evts[i].loc;
  }
  for(in i=0;i<n;i++){
    if(wkrs[i].l<=bestx && wkrs[i].r>=besty && wkrs[i].v>=bestx && wkrs[i].v<=besty)
      sol[solc++]=i+1;
  }
  cout<<solc<<endl;
  for(in i=0;i<solc;i++){
    cout<<sol[i];
    if(i!=solc-1)
      cout<<" ";
  }
  cout<<endl;
  return 0;
}