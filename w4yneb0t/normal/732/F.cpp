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
template<typename T> void clr(stack<T>& t){
  while(!t.empty())
    t.pop();
}
struct bridges{
  VVI impl;
  stack<in> whr;
  stack<in> hsn;
  stack<in> ci;
  VI vst;
  VI trc;
  VI hit;
  in mhsh;
  stack<in> ts;
  VI comp,psd,gvh;
  void ad(in a, in b){
    impl[a].PB(b);
    impl[b].PB(a);
  }
  void ini(in n){
    mhsh=n;
    impl=VVI(mhsh,VI(0));
  }
  void hasol(){
    vst.clear();
    trc.clear();
    hit.clear();
    comp.clear();
    psd.clear();
    gvh.clear();
    clr(whr);
    clr(hsn);
    clr(ci);
    clr(ts);
    trc.resize(mhsh,0);
    vst.resize(mhsh,0);
    hit.resize(mhsh,0);
    psd=hit;
    comp.resize(mhsh,-1);
    gvh.resize(mhsh,0);
    in crn=0;
    in ccp=0;
    forn(z,mhsh){
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
	if(trc[u]==v){
	  ci.top()++;
	  continue;
	}
	if(vst[v]==0){
	  trc[v]=u;
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
  }
};
bridges mbr;
VI cct;
VI tx,ty;
VI fix;
VVI egs,egid;
in rcp;
VI vis;
void dfs(in u, in pr){
  if(vis[u])
    return;
  vis[u]=1;
  in tt,ti;
  forv(i,egs[u]){
    tt=egs[u][i];
    if(tt==pr)
      continue;
    ti=egid[u][i];
    if(!fix[ti]){
      fix[ti]=1;
      if(mbr.comp[tt]==rcp){
	if(tx[ti]!=u)
	  swap(tx[ti],ty[ti]);
      }
      else{
	if(tx[ti]==u)
	  swap(tx[ti],ty[ti]);
      }
    }
    dfs(tt,u);
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m;
  cin>>n>>m;
  egs.resize(n);
  egid.resize(n);
  mbr.ini(n);
  tx.resize(m);
  ty.resize(m);
  forn(i,m){
    cin>>tx[i]>>ty[i];
    --tx[i];
    --ty[i];
    egs[tx[i]].PB(ty[i]);
    egid[tx[i]].PB(i);
    egs[ty[i]].PB(tx[i]);
    egid[ty[i]].PB(i);
    mbr.ad(tx[i],ty[i]);
  }
  mbr.hasol();
  cct.resize(n);
  forn(i,n)
    ++cct[mbr.comp[i]];
  in mx=0;
  forn(i,n)
    mx=max(mx,cct[i]);
  in rpr=-1;
  forn(i,n)
    if(cct[mbr.comp[i]]==mx)
      rpr=i;
  vis.resize(n);
  fix.resize(m,0);
  rcp=mbr.comp[rpr];
  dfs(rpr,-1);
  cout<<mx<<"\n";
  forv(i,tx)
    cout<<tx[i]+1<<" "<<ty[i]+1<<"\n";
  return 0;
}