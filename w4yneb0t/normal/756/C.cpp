#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#define PB push_back
#define MP make_pair
#define sz(v) (in((v).size()))
#define forn(i,n) for(in i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define fors(i,s) for(auto i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
typedef vector<in> VI;
typedef vector<VI> VVI;
VI l,r,mn,tad;
void ad(in a, in b, in v, in id){
  if(b<l[id] || a>r[id])
    return;
  if(a<=l[id] && b>=r[id]){
    mn[id]+=v;
    tad[id]+=v;
    return;
  }
  if(tad[id]){
    ad(l[id],r[id],tad[id],2*id);
    ad(l[id],r[id],tad[id],2*id+1);
    tad[id]=0;
  }
  ad(a,b,v,2*id);
  ad(a,b,v,2*id+1);
  mn[id]=min(mn[2*id],mn[2*id+1]);
}
bool qr(in& tt, in id){
  if(id==1 && mn[id]>=0)
    return 0;
  if(l[id]==r[id]){
    tt=l[id];
    return 1;
  }
  if(tad[id]){
    ad(l[id],r[id],tad[id],2*id);
    ad(l[id],r[id],tad[id],2*id+1);
    tad[id]=0;
    mn[id]=min(mn[2*id],mn[2*id+1]);
  }
  if(mn[2*id+1]<0){
    qr(tt,2*id+1);
    return 1;
  }
  qr(tt,2*id);
  return 1;
} 
void build(in m){
  while(m&(m-1))
    ++m;
  l=r=tad=mn=VI(2*m);
  forn(i,m){
    l[i+m]=r[i+m]=i;
  }
  for(in i=m-1;i>=1;--i){
    l[i]=l[2*i];
    r[i]=r[2*i+1];
  }
}
VI idof;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in m;
  cin>>m;
  build(m);
  idof.resize(m);
  in p,t;
  in tt;
  forn(z,m){
    cin>>p>>t;
    --p;
    if(t==0){
      ad(0,p,1,1);
    }
    else{
      cin>>idof[p];
      ad(0,p,-1,1);
    }
    if(qr(tt,1))
      cout<<idof[tt]<<"\n";
    else
      cout<<-1<<"\n";
  }
  return 0;
}