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
const in mdl=1000000007LL;
struct fenw{
  VI fw;
  in n;
  in tot;
  void ini(in pn){
    n=pn;
    tot=0;
    fw.clear();
    fw.resize(n,0);
  }
  void ad(in l, in x){
    tot+=x;
    tot%=mdl;
    while(l<n){
      fw[l]+=x;
      fw[l]%=mdl;
      l|=(l+1);
    }
  }
  in sm(in l){
    if(l>=n)
      l=n-1;
    in r=0;
    while(l>=0){
      r+=fw[l];
      l&=(l+1);
      --l;
    }
    return r;
  }
  in lftof(in a){
    return sm(a-1)%mdl;
  }
  in rgtof(in a){
    return (tot-sm(a))%mdl;
  }
};
void nrm(in& a){
  a%=mdl;
  if(a<0)
    a+=mdl;
}
VI bllft,blrgt;

struct segel{
  in bas,tot,fc;
  segel(in a=0, in b=0){
    bas=a;
    fc=b;
    tot=0;
    tot%=mdl;
  }
  segel& operator+=(const segel& cp){
    tot+=cp.tot+fc*cp.bas;
    fc+=cp.fc;
    bas+=cp.bas;
    bas%=mdl;
    tot%=mdl;
    return *this;
  }
};
struct seg{
  in MX;
  vector<segel> mxp;
  VI lft,rgt;
  bool hfp;
  in rn;
  void flp(in& a){
    a=rn-1-a;
  }
  void mxin(in r, segel& s, in id=1){
    if(r<lft[id])
      return;
    if(r>=rgt[id]){
      s+=mxp[id];
      return;
    }
    mxin(r,s,2*id+1);
    mxin(r,s,2*id);
  }
  void st(in x, segel v, in id=1){
    if(x<lft[id] || x>rgt[id])return;
    if(lft[id]!=rgt[id]){
      st(x,v,2*id);
      st(x,v,2*id+1);
      mxp[id]=mxp[2*id+1];
      mxp[id]+=mxp[2*id];
    }
    else
      mxp[id]=v;
  }
  void sat(in loc, in bs, in f){
    if(hfp)
      flp(loc);
    segel c(bs,f);
    st(loc,c,1);
  }
  segel smp(in loc){
    if(hfp)
      flp(loc);
    segel c(0,0);
    mxin(loc,c,1);
    return c;
  }
  void ini(in n, in flp){
    rn=n;
    hfp=flp;
    MX=1;
    while(MX<n)
      MX*=2;
    mxp=vector<segel>(2*MX,segel());
    lft=rgt=VI(2*MX);
    forn(i,MX)
      lft[i+MX]=rgt[i+MX]=i;
    for(in i=MX-1;i>=1;--i){
      lft[i]=lft[2*i];
      rgt[i]=rgt[2*i+1];
    }
  }
};


struct sru{
  VI locs;
  seg clft,crgt;
  void ini(VI a){
    locs=a;
    in n=sz(a);
    clft.ini(n,0);
    crgt.ini(n,1);
  }
  in ad(in rlloc, in fc){
    in smchg=0;
    in id=lower_bound(all(locs),rlloc)-locs.begin();
    assert(locs[id]==rlloc);
    in mlft=bllft[rlloc];
    smchg+=mlft*crgt.smp(id+1).tot;
    smchg%=mdl;
    in mrgt=blrgt[rlloc];
    smchg+=mrgt*clft.smp(id-1).tot;
    smchg%=mdl;
    smchg+=clft.smp(id-1).bas*crgt.smp(id+1).bas;
    smchg%=mdl;
    //cout<<rlloc<<" "<<fc<<" "<<mlft<<" "<<mrgt<<" "<<smchg<<"     "<<crgt.smp(id+1).fc<<" "<<crgt.smp(id+1).bas<<" "<<crgt.smp(id+1).tot<<"    "<<clft.smp(id-1).fc<<" "<<clft.smp(id-1).bas<<" "<<clft.smp(id-1).tot<<endl;
    if(fc==-1){
      clft.sat(id,0,0);
      crgt.sat(id,0,0);
    }
    else{
      clft.sat(id,mlft,1);
      crgt.sat(id,mrgt,1);
    }
    smchg%=mdl;
    return smchg*fc;
  }
};
vector<sru> mv;
VVI tat;
VI mar;
fenw mbl;
in ads(in a, in fc){
  return mv[mar[a]].ad(a,fc);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m;
  cin>>n;
  mar.resize(n);
  bllft.resize(n);
  blrgt.resize(n);
  map<in,in> comp;
  forn(i,n){
    cin>>mar[i];
    comp[mar[i]];
  }
  in cc=0;
  fors(i,comp)
    i->second=cc++;
  mv.resize(cc);
  tat.resize(cc);
  forn(i,n){
    mar[i]=comp[mar[i]];
    tat[mar[i]].PB(i);
  }
  mbl.ini(n);
  forn(i,n){
    bllft[i]=mbl.lftof(mar[i]+1);
    mbl.ad(mar[i],1);
  }
  mbl.ini(n);
  for(in i=n-1;i>=0;--i){
    blrgt[i]=mbl.lftof(mar[i]+1);
    mbl.ad(mar[i],1);
  }
  forn(i,cc)
    mv[i].ini(tat[i]);
  cin>>m;
  in sm=0;
  forn(i,n){
    sm+=ads(i,1);
    sm%=mdl;
  }
  in ttyp,tl;
  forn(z,m){
    cin>>ttyp>>tl;
    --tl;
    in fc=1;
    if(ttyp==1)
      fc=-1;
    sm+=ads(tl,fc);
    nrm(sm);
    cout<<sm<<"\n";
  }
  return 0;
}