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
typedef long long ll;
typedef vector<in> VI;
typedef vector<VI> VVI;
const ll mdl=1000000007LL;
ll p2(ll a){
  return (1LL<<a);
}
ll pw(ll a, ll b, in lm=62){
  a%=mdl;
  if(a<0)
    a+=mdl;
  ll r=1;
  for(in i=lm;i>=0;--i){
    r=r*r%mdl;
    if(b&p2(i))
      r=r*a%mdl;
  }
  return r;
}
ll inv(ll a){
  a%=mdl;
  if(a<0)
    a+=mdl;
  assert(a!=0);
  return pw(a,mdl-2,30);
}
ll sm=0;
vector<ll> val;
vector<ll> origval;
VVI divs;
vector<ll> phi;
vector<ll> fct;
in n;
struct tkr{
  VI locs;
  vector<ll> s;
  VI trdon;
  void ini(){
    trdon.resize(n+3);
    s.resize(n+3,0);
  }
  void ad(in l, ll c){
    s[l]+=c;
    s[l]%=mdl;
    locs.PB(l);
  }
  void clr(){
    forv(i,locs)
      s[locs[i]]=trdon[locs[i]]=0;
    locs.clear();
  }
  ll trval(in l){
    if(trdon[l])
      return 0;
    trdon[l]=1;
    return s[l];
  }
};
tkr mntk;
tkr sdtk;
void genbas(){
  mntk.ini();
  sdtk.ini();
  origval=val;
  divs.resize(n+3);
  phi.resize(n+3);
  fct.resize(n+3,1);
  forv(i,phi)
    phi[i]=i;
  bool pr;
  for(in i=1;i<sz(divs);++i){
    if(i>1 && sz(divs[i])==1)
      pr=1;
    else
      pr=0;
    for(in j=i;j<sz(divs);j+=i){
      divs[j].PB(i);
      if(pr){
	phi[j]=phi[j]*(i-1)/i;
	fct[j]*=(i*inv(i-1)%mdl);
	fct[j]%=mdl;
      }
    }
  }
  forv(i,val)
    val[i]=phi[val[i]];
  for(in i=1;i<sz(fct);++i){
    forv(j,divs[i]){
      if(divs[i][j]<i)
	fct[i]-=fct[divs[i][j]];
    }
    fct[i]%=mdl;
    if(fct[i]<0)
      fct[i]+=mdl;
  }
}
VI act;
VVI egs;
VI blw;
VI lrgc;
VI visl;
in cu;
void adto(in u, in pr, tkr& t, in d, in f){
  forv(i,divs[origval[u]]){
    cu=divs[origval[u]][i];
    if(d==0)
      t.ad(cu,val[u]*f);
    else
      t.ad(cu,val[u]*d*f);
  }
  in tup;
  in ts=sz(egs[u]);
  forn(i,ts){
    tup=egs[u][i];
    if(tup==pr)
      continue;
    if(!act[tup])
      continue;
    adto(tup,u,t,(d==0?0:(d+1)),f);
  }
}

in gentot(const in& u, const in& pr){
  visl.PB(u);
  blw[u]=1;
  lrgc[u]=0;
  in tup;
  in ts=sz(egs[u]);
  forn(i,ts){
    tup=egs[u][i];
    if(tup==pr)
      continue;
    if(!act[tup])
      continue;
    blw[u]+=gentot(tup,u);
    lrgc[u]=max(lrgc[u],blw[tup]);
  }
  return blw[u];
}
void gen(in bpt){
  if(sz(lrgc)==0){
    lrgc.resize(sz(egs));
    blw.resize(sz(egs));
    act.resize(sz(egs),1);
  }
  assert(act[bpt]);
  visl.clear();
  gentot(bpt,bpt);
  in msz=blw[bpt];
  in u=-1;
  forv(i,visl){
    if(blw[visl[i]]*2>=msz && lrgc[visl[i]]*2<=msz)
      u=visl[i];
  }
  assert(u!=-1);
  act[u]=0;
  mntk.clr();
  forv(z,egs[u]){
    if(!act[egs[u][z]])
      continue;
    adto(egs[u][z],u,mntk,1,1);
  }
  in cl;
  forv(z,egs[u]){
    if(!act[egs[u][z]])
      continue;
    sdtk.clr();
    adto(egs[u][z],u,mntk,1,-1);
    adto(egs[u][z],u,sdtk,0,1);
    forv(i,sdtk.locs){
      cl=sdtk.locs[i];
      //cout<<"ad "<<cl<<" "<<sdtk.s[cl]<<" "<<mntk.s[cl]<<" "<<fct[cl]<<endl;
      sm+=sdtk.trval(cl)*mntk.s[cl]%mdl*fct[cl]%mdl;
    }
    adto(egs[u][z],u,mntk,1,1);
  }
  forv(i,divs[origval[u]]){
    cl=divs[origval[u]][i];
    sm+=mntk.s[cl]*val[u]%mdl*fct[cl]%mdl;
  }
  forv(z,egs[u]){
    if(!act[egs[u][z]])
      continue;
    gen(egs[u][z]);
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  ll rs=inv(n)*inv(n-1)%mdl;
  val.resize(n);
  forn(i,n)
    cin>>val[i];
  genbas();
  egs.resize(n);
  in ta,tb;
  forn(z,n-1){
    cin>>ta>>tb;
    --ta;
    --tb;
    egs[ta].PB(tb);
    egs[tb].PB(ta);
  }
  gen(0);
  sm%=mdl;
  sm*=2;
  sm%=mdl;
  sm*=rs;
  sm%=mdl;
  if(sm<0)
    sm+=mdl;
  cout<<sm<<endl;
  return 0;
}