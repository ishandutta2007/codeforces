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
in p;
in twp;
in ww(in s){
  if(s<0)
    return 0;
  if(s<=p-1)
    return (s+1)*(s+2)/2%mdl;
  return (twp-(2*p-2-s)*(2*p-1-s)/2);
}
VI dg;
int wy[8][3500];
void fw(in cr, in typ, in ds, in ks){
  if(ds==0){
    wy[cr*4+typ*2+ds%2][ks]=(cr==0 && typ==0 && ks==0);
    return;
  }
  in tp=0;
  in mn,mx;
  forn(pvcr,2){
    forn(pvtyp,2){
      in pvk=ks-cr;
      if(pvk<0)
	continue;
      mn=0;
      mx=2*p-2;
      if(cr==0)
	mx=p-1-pvcr;
      else
	mn=p-pvcr;
      if(typ==0)
	mx=dg[ds-1]-pvtyp-pvcr+cr*p;
      else
	mn=dg[ds-1]+1-pvtyp-pvcr+cr*p;
      if(mn>mx)
	continue;
      tp+=(ww(mx)-ww(mn-1))%mdl*wy[pvcr*4+pvtyp*2+(ds-1)%2][ks-cr]%mdl;
    }
  }
  tp%=mdl;
  if(tp<0)
    tp+=mdl;
  wy[cr*4+typ*2+ds%2][ks]=tp;
}
in k;
in fr(){
  in r=0;
  for(in d=0;d<sz(dg);++d){
    forn(a,2){
      forn(b,2){
	forn(x,d+2){
	  fw(a,b,d,x);
	}
      }
    }
  }
  for(in x=k;x<=sz(dg);++x){
    fw(0,0,sz(dg),x);
    r+=wy[sz(dg)%2][x];
  }
  r%=mdl;
  return r;
}
in bs=1e9;
VI a;
void conv(){
  in rm=0;
  in cp=1;
  forv(i,a){
    rm+=cp*a[i];
    rm%=p;
    cp*=bs;
    cp%=p;
  }
  dg.PB(rm);
  a[0]-=rm;
  in id=0;
  while(a[id]<0){
    while(a[id]<0){
      a[id]+=bs;
      --a[id+1];
    }
    ++id;
  }
  while(sz(a)>0 && a.back()==0)
    a.pop_back();
  if(sz(a)==0)
    return;
  for(in i=sz(a)-1;i>=0;--i){
    if(a[i]%p){
      assert(i);
      a[i-1]+=bs*(a[i]%p);
    }
    a[i]/=p;
  }
  while(sz(a)>0 && a.back()==0)
    a.pop_back();
  conv();
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  string ta;
  cin>>p>>k>>ta;
  twp=(p-1+1)*(p-1+2)/2+(p-2+1)*(p-2+2)/2;
  twp%=mdl;
  if(twp<0)
    twp+=mdl;
  forv(i,ta)
    a.PB(ta[i]-'0');
  reverse(all(a));
  VI b;
  in nx=0;
  while(nx<sz(a)){
    in cn=0;
    for(in i=min(sz(a)-1,8+nx);i>=nx;--i){
      cn=10*cn+a[i];
    }
    b.PB(cn);
    nx+=9;
  }
  a=b;
  conv();
  if(k>sz(dg)+3){
    cout<<0<<endl;
    return 0;
  }
  cout<<fr()<<endl;
  return 0;
}