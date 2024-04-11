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
struct cand{
  in v;
  int id;
  cand(in a=0, in b=0){
    id=a;
    v=b;
  }
  bool operator<(const cand& cp)const{
    return v>cp.v;
  }
};
in trt;
struct dcd{
  vector<cand> cds;
  dcd(){
  }
  dcd(cand c){
    cds.PB(c);
  }
  void adc(const cand c){
    trt=sz(cds);
    if(trt<2){
      if(trt==0){
	cds.PB(c);
	return;
      }
      if(cds[0].v<c.v){
	cds.PB(cds[0]);
	cds[0]=c;
	return;
      }
      cds.PB(c);
      return;
    }
    if(cds[1].v>=c.v)
      return;
    if(cds[0].v>=c.v){
      cds[1]=c;
      return;
    }
    cds[1]=cds[0];
    cds[0]=c;
  }
};
struct segtree{
  in MX;
  const in inf=10000000000LL;
  vector<dcd> mxp;
  VI lft,rgt;
  void mxin(dcd& ti, in l, in r, in id=1){
    if(r<lft[id] || l>rgt[id])return;
    if(l<=lft[id] && r>=rgt[id]){
      forv(i,mxp[id].cds)
	ti.cds.PB(mxp[id].cds[i]);
      return;
    }
    mxin(ti,l,r,2*id);
    mxin(ti,l,r,2*id+1);
  }
  void pg(){
    for(in id=MX-1;id>=1;--id){
      forv(i,mxp[2*id].cds)
	mxp[id].adc(mxp[2*id].cds[i]);
      forv(i,mxp[2*id+1].cds)
	mxp[id].adc(mxp[2*id+1].cds[i]);
    }
  }
  void ini(in n){
    MX=1;
    while(MX<n)
      MX*=2;
    mxp=vector<dcd>(2*MX);
    lft=rgt=VI(2*MX);
    forn(i,MX)
      lft[i+MX]=rgt[i+MX]=i;
    for(in i=MX-1;i>=1;--i){
      lft[i]=lft[2*i];
      rgt[i]=rgt[2*i+1];
    }
  }
};
in n;
in td=0;
void prg(dcd& tp){
  sort(all(tp.cds));
  while(sz(tp.cds)>2)
    tp.cds.pop_back();
}
dcd fnd(segtree& tr, in a, in b, in sg){
  dcd tp;
  if(a>b)
    tr.mxin(tp,b+1,a-1);
  else{
    tr.mxin(tp,b+1,n-1);
    dcd t2;
    tr.mxin(t2,0,a-1);
    forv(i,t2.cds)
      tp.cds.PB(cand(t2.cds[i].id,t2.cds[i].v+sg*td));
  }
  prg(tp);
  return tp;
}
segtree scpos,scneg;
VI dupt,h;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in m;
  cin>>n>>m;
  dupt.resize(n+1);
  h.resize(n);
  forn(i,n){
    cin>>dupt[i+1];
    td+=dupt[i+1];
  }
  forn(i,n)
    cin>>h[i];
  for(in i=1;i<n;++i)
    dupt[i]+=dupt[i-1];
  dupt.resize(n);
  scpos.ini(n);
  scneg.ini(n);
  forn(i,n){
    scpos.mxp[scpos.MX+i]=dcd(cand(i,dupt[i]+2*h[i]));
    scneg.mxp[scneg.MX+i]=dcd(cand(i,-dupt[i]+2*h[i]));
  }
  scpos.pg();
  scneg.pg();
  in ta,tb;
  dcd t1,t2;
  forn(z,m){
    cin>>ta>>tb;
    --ta;
    --tb;
    t1=fnd(scpos,ta,tb,1);
    t2=fnd(scneg,ta,tb,-1);
    if(t1.cds[0].id!=t2.cds[0].id){
      cout<<t1.cds[0].v+t2.cds[0].v<<"\n";
      continue;
    }
    cout<<max(t1.cds[0].v+t2.cds[1].v,t1.cds[1].v+t2.cds[0].v)<<"\n";
  }
  return 0;
}