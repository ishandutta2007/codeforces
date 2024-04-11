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
in p2(in a){
  return (1LL<<a);
}
in pw(in a, in b, in lm=62){
  a%=mdl;
  if(a<0)
    a+=mdl;
  in r=1;
  for(in i=lm;i>=0;--i){
    r=r*r%mdl;
    if(b&p2(i))
      r=r*a%mdl;
  }
  return r;
}
in inv(in a){
  a%=mdl;
  if(a<0)
    a+=mdl;
  assert(a!=0);
  return pw(a,mdl-2,30);
}
VI fc,invfc;
in ncr(in a, in b){
  if(b==0 || b==a)
    return 1;//even if a<0
  if(b<0 || b>a)
    return 0;
  return fc[a]*invfc[b]%mdl*invfc[a-b]%mdl;
}
void inifc(){
  const in mxfc=1001000;
  fc.resize(mxfc);
  invfc.resize(mxfc);
  fc[0]=fc[1]=invfc[0]=invfc[1]=1;
  for(in i=2;i<mxfc;++i){
    fc[i]=fc[i-1]*i%mdl;
    invfc[i]=invfc[mdl%i]*(mdl-mdl/i)%mdl;
  }
  for(in i=2;i<mxfc;++i){
    invfc[i]*=invfc[i-1];
    invfc[i]%=mdl;
  }
}

const in mxn=1e5+9;
struct fenw{
  vector<int> fw;
  int n;
  void ini(int pn){
    n=pn;
    fw.clear();
    fw.resize(n,0);
  }
  void ad(int l, int x){
    while(l<n){
      fw[l]+=x;
      l|=(l+1);
    }
  }
  int sm(int l){
    int r=0;
    while(l>=0){
      r+=fw[l];
      l&=(l+1);
      --l;
    }
    return r;
  }
};
const in ofs=2*mxn;
fenw fw;
in n;
in res=1;
VVI egs,egv,egc;
in genbas(in u, in pr){
  in tt=1;
  in te;
  in bl;
  forv(i,egs[u]){
    te=egs[u][i];
    if(te==pr)
      continue;
    bl=genbas(te,u);
    res=res*pw(egv[u][i],bl*(n-bl))%mdl;
    tt+=bl;
  }
  return tt;
}

VI act;
VI blw;
VI lrgc;
VI visl;
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
VI ntclrloc;
VI tadbal,tadx;
void gentad(in u, in pr, in x, in bal){
  tadbal.PB(bal);
  tadx.PB(x);
  in tup;
  in ts=sz(egs[u]);
  forn(i,ts){
    tup=egs[u][i];
    if(tup==pr)
      continue;
    if(!act[tup])
      continue;
    gentad(tup,u,x*egv[u][i]%mdl,bal+egc[u][i]);
  }
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
  in tothav=1;
  fw.ad(ofs,1);
  forv(z,egs[u]){
    if(!act[egs[u][z]])
      continue;
    gentad(egs[u][z],u,egv[u][z],egc[u][z]);
    forv(i,tadbal){
      res=res*pw(tadx[i],tothav-fw.sm(ofs-tadbal[i]))%mdl;
    }
    forv(i,tadbal){
      fw.ad(tadbal[i]+ofs,1);
      ntclrloc.PB(tadbal[i]);
      ++tothav;
    }
    tadbal.clear();
    tadx.clear();
  }
  fw.ad(ofs,-1);
  forv(i,ntclrloc){
    fw.ad(ntclrloc[i]+ofs,-1);
  }
  ntclrloc.clear();
  tothav=0;
  for(in z=sz(egs[u])-1;z>=0;--z){
    if(!act[egs[u][z]])
      continue;
    gentad(egs[u][z],u,egv[u][z],egc[u][z]);
    forv(i,tadbal){
      res=res*pw(tadx[i],tothav-fw.sm(ofs-tadbal[i]))%mdl;
    }
    forv(i,tadbal){
      fw.ad(tadbal[i]+ofs,1);
      ntclrloc.PB(tadbal[i]);
      ++tothav;
    }
    tadbal.clear();
    tadx.clear();
  }
  forv(i,ntclrloc){
    fw.ad(ntclrloc[i]+ofs,-1);
  }
  ntclrloc.clear();
  forv(z,egs[u]){
    if(!act[egs[u][z]])
      continue;
    gen(egs[u][z]);
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  fw.ini(2*ofs);
  inifc();
  cin>>n;
  egs.resize(n);
  egv.resize(n);
  egc.resize(n);
  in ta,tb,tx,tc;
  forn(z,n-1){
    cin>>ta>>tb>>tx>>tc;
    --ta;
    --tb;
    egs[ta].PB(tb);
    egv[ta].PB(tx);
    egc[ta].PB(tc);
    egs[tb].PB(ta);
    egv[tb].PB(tx);
    egc[tb].PB(tc);
  }
  genbas(0,0);
  res=inv(res);
  forv(i,egc){
    forv(j,egc[i]){
      if(egc[i][j]==0)
	egc[i][j]=-2;
      else
	egc[i][j]=1;
    }
  }
  gen(0);
  forv(i,egc){
    forv(j,egc[i]){
      if(egc[i][j]==-2)
	egc[i][j]=1;
      else
	egc[i][j]=-2;
    }
  }
  act.clear();
  lrgc.clear();
  blw.clear();
  visl.clear();
  gen(0);
  res=inv(res);
  res%=mdl;
  if(res<0)
    res+=mdl;
  cout<<res<<endl;
  return 0;
}