#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
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
template<typename T>
void clr(stack<T>& t){
  while(!t.empty())
    t.pop();
}
in mc;
VVI ppi;
struct twosat{
  in mhsh;
  VVI impl;
  stack<in> whr;
  stack<in> hsn;
  stack<in> ci;
  VI vst;
  VI hit;
  stack<in> ts;
  VI comp,psd,gvh;
  void ad(in a, in b){
    impl[neg(a)].PB(b);
    impl[neg(b)].PB(a);
  }
  void ini(in n){
    mhsh=n;
    impl=VVI(2*n,VI(0));
  }
  in neg(in h){
    return h>=mhsh?h-mhsh:h+mhsh;
  }
  bool hasol(){
    clr(whr);
    clr(hsn);
    clr(ci);
    vst.clear();
    hit.clear();
    clr(ts);
    comp.clear();
    psd.clear();
    gvh.clear();
    vst.resize(mhsh*2,0);
    hit.resize(mhsh*2,0);
    psd=hit;
    comp.resize(mhsh*2,-1);
    gvh.resize(mhsh*2,0);
    in crn=0;
    in ccp=0;
    forn(z,mhsh*2){
      if(vst[z])
	continue;
      crn++;
      whr.push(z);
      hsn.push(0);
      vst[z]=crn;
      hit[z]=0;
      in chit=1;
      ci.push(0);
      in u,i,ch,v;
      while(!whr.empty()){
	u=whr.top();
	i=ci.top();
	ch=hsn.top();
	gvh[u]=ch;
	if(!psd[u]){
	  ts.push(u);
	  psd[u]=1;
	}
	if(i==sz(impl[u])){
	  if(ch>=hit[u]){
	    while(1){
	      comp[ts.top()]=ccp;
	      ts.pop();
	      if(comp[u]!=-1)
		break;
	    }
	    ccp++;
	  }
	  whr.pop();
	  ci.pop();
	  hsn.pop();
	  continue;
	}
	v=impl[u][i];
	if(vst[v]==0){
	  whr.push(v);
	  hsn.push(chit);
	  ci.push(0);
	  hit[v]=chit++;
	  vst[v]=crn;
	  continue;
	}
	if(vst[v]==crn && comp[v]==-1){
	  if(gvh[v]<ch){
	    hsn.top()=gvh[v];
	  }
	}
	ci.top()++;
      }
    }
    mc=ccp;
    forn(i,mhsh)
      if(comp[i]==comp[neg(i)])
	return 0;
    return 1;
  }
};
twosat ts;
in totd=0;
VI csol;
in n;
void ad(in a){
  totd+=(csol[a%n]==-1);
  if(a>=n)
    csol[a-n]=0;
  else
    csol[a]=1;
  forv(i,ts.impl[a]){
    if(csol[ts.impl[a][i]%n]==-1)
      ad(ts.impl[a][i]);
  }
}
const in cbit=63;
VI deg,ord;
VVI isp;
in p2(in a){
  return 1LL<<a;
}
void adg(in a, in b){
  if(a==b)
    return;
  if(!(isp[a][b/cbit]&p2(b%cbit)))
    ++deg[b];
  isp[a][b/cbit]|=p2(b%cbit);
}
in aisp(in u, in i){
  return !!(isp[u][i/cbit]&p2(i%cbit));
}
bool crc(in a, in b){
  if(ts.comp[a]==ts.comp[b])
    return 1;
  if(aisp(ts.comp[a],ts.comp[b]))
    return 1;
  return 0;
}
void mksol(in a, in b){
  csol.resize(n,-1);
  ad(a);
  ad(b);
  forn(i,2*n){
    if(csol[i%n]!=-1)
      continue;
    if(crc(i,ts.neg(i)))
      continue;
    ad(i);
  }
  assert(totd==n);
  forn(i,n)
    printf("%lld ",csol[i]);
  printf("\n");
}
void hsb(VI f, VI g){
  ts.ini(n);
  for(in i=0;i<sz(f);i+=2){
    ts.ad(f[i],f[i+1]);
  }
  if(!ts.hasol())
    return;
  isp=VVI(mc,VI((mc+cbit-1)/cbit,0));
  deg=VI(mc,0);
  ord.clear();
  for(in i=0;i<sz(f);i+=2){
    adg(ts.comp[ts.neg(f[i])],ts.comp[f[i+1]]);
    adg(ts.comp[ts.neg(f[i+1])],ts.comp[f[i]]);
  }
  queue<in> q;
  forn(i,mc)
    if(deg[i]==0)
      q.push(i);
  in u;
  while(!q.empty()){
    u=q.front();
    q.pop();
    ord.PB(u);
    forn(i,mc){
      if(aisp(u,i)){
	--deg[i];
	if(deg[i]==0)
	  q.push(i);
      }
    }
  }
  for(in i=mc-1;i>=0;--i){
    for(in j=i+1;j<mc;++j){
      if(aisp(ord[i],ord[j])){
	forv(k,isp[ord[i]])
	  isp[ord[i]][k]|=isp[ord[j]][k];
      }
    }
  }
  for(in i=0;i<sz(g);i+=2){
    if(!crc(ts.neg(g[i]),g[i+1]) && !crc(ts.neg(g[i+1]),g[i])){
      if(crc(ts.neg(g[i]),g[i]) || crc(ts.neg(g[i+1]),g[i+1]))
	continue;
      mksol(ts.neg(g[i]),ts.neg(g[i+1]));
      exit(0);
    }
  }
}
VI f,g;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in m1,m2;
  scanf("%lld%lld%lld",&n,&m1,&m2);
  f.resize(2*m1);
  g.resize(2*m2);
  forv(i,f){
    scanf("%lld",&(f[i]));
    if(f[i]<0)
      f[i]=n-f[i]-1;
    else
      f[i]=f[i]-1;
  }
  forv(i,g){
    scanf("%lld",&(g[i]));
    if(g[i]<0)
      g[i]=n-g[i]-1;
    else
      g[i]=g[i]-1;
  }
  hsb(f,g);
  hsb(g,f);
  printf("SIMILAR\n");
  return 0;
}