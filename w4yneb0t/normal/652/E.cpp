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
VVI ppi;
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
VVI egs;
bridges mbr;
in n,m;
VI tx,ty,tbr;
bool fnd=0;
VI dfv;
set<in> gdcp;
bool isfd(in a){
  return gdcp.find(a)!=gdcp.end();
}
in dfs(in u, in gl){
  if(dfv[u])
    return 0;
  dfv[u]=1;
  if(u==gl){
    gdcp.insert(mbr.comp[u]);
    return 1;
  }
  in tt;
  forv(i,egs[u]){
    tt=egs[u][i];
    if(dfs(tt,gl)){
      gdcp.insert(mbr.comp[u]);
      return 1;
    }
  }
  return 0;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  mbr.ini(n);
  tx=ty=tbr=VI(m);
  egs.resize(n);
  forn(i,m){
    cin>>tx[i]>>ty[i]>>tbr[i];
    --tx[i];
    --ty[i];
    egs[tx[i]].PB(ty[i]);
    egs[ty[i]].PB(tx[i]);
    mbr.ad(tx[i],ty[i]);
  }
  mbr.hasol();
  in id1,id2;
  cin>>id1>>id2;
  --id1;
  --id2;
  dfv.resize(n);
  dfs(id1,id2);
  forn(i,m){
    if(tbr[i]){
      if(isfd(mbr.comp[tx[i]])&&isfd(mbr.comp[ty[i]])){
	cout<<"YES"<<endl;
	return 0;
      }
    }
  }
  cout<<"NO"<<endl;
  return 0;
}