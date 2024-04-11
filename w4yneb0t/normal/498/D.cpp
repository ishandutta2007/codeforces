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
typedef int in;
typedef vector<in> VI;
typedef vector<VI> VVI;
struct segel{
  VI tm;
  segel(in trp=0){
    tm=VI(60,0);
    if(trp!=0){
      forn(i,60){
	tm[i]=1;
      }
      for(in i=0;i<60;i+=trp)
	tm[i]=2;
    }
  }
};
void adscar(segel& r, const segel a, const segel& b){
  forn(i,60){
    r.tm[i]=a.tm[i]+b.tm[(i+a.tm[i])%60];
  }
}
void ads(segel& r, const segel& a, const segel& b){
  forn(i,60){
    r.tm[i]=a.tm[i]+b.tm[(i+a.tm[i])%60];
  }
}
struct segtree{
  in MX;
  const segel neutr=0;
  vector<segel> mxp;
  VI lft,rgt;
  void mxin(segel& rs, in l, in r, in id=1){
    if(r<lft[id] || l>rgt[id])return;
    if(l<=lft[id] && r>=rgt[id]){
      adscar(rs,rs,mxp[id]);
      return;
    }
    mxin(rs,l,r,2*id);
    mxin(rs,l,r,2*id+1);
  }
  void st(in x, in v, in id=1){
    if(x<lft[id] || x>rgt[id])return;
    if(lft[id]!=rgt[id]){
      st(x,v,2*id);
      st(x,v,2*id+1);
      ads(mxp[id],mxp[2*id],mxp[2*id+1]);
    }
    else
      mxp[id]=v;
  }
  void ini(in n){
    MX=1;
    while(MX<n)
      MX*=2;
    mxp=vector<segel>(2*MX,0);
    lft=rgt=VI(2*MX);
    forn(i,MX)
      lft[i+MX]=rgt[i+MX]=i;
    for(in i=MX-1;i>=1;--i){
      lft[i]=lft[2*i];
      rgt[i]=rgt[2*i+1];
    }
  }
};
segtree mtr;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  mtr.ini(n);
  in tp;
  forn(i,n){
    cin>>tp;
    mtr.mxp[mtr.MX+i]=tp;
  }
  for(in i=mtr.MX-1;i>=1;--i)
    ads(mtr.mxp[i],mtr.mxp[2*i],mtr.mxp[2*i+1]);
  in q;
  cin>>q;
  char typ;
  in x,y;
  segel tpr;
  forn(z,q){
    cin>>typ>>x>>y;
    if(typ=='A'){
      tpr=0;
      mtr.mxin(tpr,x-1,y-2);
      cout<<tpr.tm[0]<<"\n";
      continue;
    }
    assert(typ=='C');
    mtr.st(x-1,y);
  }
  return 0;
}