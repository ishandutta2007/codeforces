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
const in mx=36;
struct pvt{
  vector<double> v;
  pvt(){
    v.resize(mx,0);
  }
};
void mkad(pvt& tg, const pvt& a){
  forn(i,mx){
    if(a.v[i]==0)
      break;
    tg.v[i]=tg.v[i]+a.v[i]-tg.v[i]*a.v[i];
  }
}
void mkrm(pvt& tg, const pvt& a){
  forn(i,mx){
    if(a.v[i]==0)
      break;
    tg.v[i]=(tg.v[i]-a.v[i])/(1-a.v[i]);
  }
}
void mksft(pvt& tg){
  for(in i=mx-1;i>0;--i)
    tg.v[i]=tg.v[i-1];
  tg.v[0]=1;
  forn(i,mx){
    tg.v[i]*=0.5;
    if(tg.v[i]<1e-14)
      tg.v[i]=0;
  }
}
vector<pvt> pvts,pvtr;
VI pr;
void mknu(in p){
  in s=sz(pr);
  pr.PB(p);
  pvts.PB(pvt());
  pvtr.PB(pvt());
  mksft(pvtr.back());
  mkad(pvts[p],pvtr.back());
  s=p;
  p=pr[s];
  in ct=1;
  while(ct<mx && p!=s){
    ++ct;
    mkrm(pvts[p],pvtr[s]);
    pvtr[s]=pvts[s];
    mksft(pvtr[s]);
    mkad(pvts[p],pvtr[s]);
    s=p;
    p=pr[s];
  }
  pvtr[s]=pvts[s];
  mksft(pvtr[s]);
}
double ans(in p){
  double r=0;
  forn(i,mx)
    r+=pvts[p].v[i];
  return r;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  pr.PB(0);
  pvtr.PB(pvt());
  mksft(pvtr[0]);
  pvts.PB(pvt());
  in q;
  scanf("%d",&q);
  in typ;
  in p;
  forn(zz,q){
    scanf("%d%d",&typ,&p);
    --p;
    if(typ==1){
      mknu(p);
    }
    else{
      printf("%.10lf\n",ans(p));
    }
  }
  return 0;
}