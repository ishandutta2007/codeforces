#include<iostream>
#include<stack>
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
template<typename T>
void clr(stack<T>& t){
  while(!t.empty())
    t.pop();
}
VVI ppi;
struct scc{
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
    impl[a].PB(b);
  }
  void ini(in n){
    mhsh=n;
    impl.resize(n);
    forn(i,n)
      impl[i].clear();
  }
  void hasol(){
    clr(whr);
    clr(hsn);
    clr(ci);
    vst.clear();
    hit.clear();
    clr(ts);
    comp.clear();
    psd.clear();
    gvh.clear();
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
  }
};
scc tcc;
VVI vid;
VVI tmc;
in n;
vector<string> bsst;
VI valid;
vector<VVI> mbut;
void gencom(in pa, in pb){
  string& a=bsst[pa];
  string& b=bsst[pb];
  VI& r=mbut[pa][pb];
  r.resize(sz(a));
  in bstl=0;
  in bsts=0;
  while(bsts<sz(b) && bsts<sz(a) && a[bsts]==b[bsts])
    ++bsts;
  r[0]=bsts;
  in cpr;
  for(in i=1;i<sz(a);++i){
    if(i-bstl>=bsts)
      cpr=0;
    else
      cpr=tmc[pb][i-bstl];
    if(cpr+i<bstl+bsts){
      r[i]=cpr;
      continue;
    }
    if(i+cpr>bstl+bsts)
      cpr=max(0,bstl+bsts-i);
    while(cpr<sz(b) && i+cpr<sz(a) && a[i+cpr]==b[cpr])
      ++cpr;
    bstl=i;
    bsts=r[i]=cpr;
  }
}
bool canfit(in a, in b, in s){// a[s], a[s+1],... = b[0], b[1]...
  if(s==sz(bsst[a]))
    return 1;
  return mbut[a][b][s]==min(sz(bsst[b]),sz(bsst[a])-s);
}
void ad(in id){
  valid.PB(id);
}
void rm(in id){
  forv(i,valid){
    if(valid[i]==id){
      for(in j=i+1;j<sz(valid);++j)
	valid[j-1]=valid[j];
      valid.pop_back();
      return;
    }
  }
  assert(0);
}
in nxid;
VI compsz;
bool isok(){
  tcc.ini(nxid);
  in c,d;
  forv(z,valid){
    c=valid[z];
    forv(zz,valid){
      d=valid[zz];
      forv(j,vid[c]){
	if(canfit(c,d,j)){
	  if(c==d){
	    if(j==0 || j==sz(bsst[c]))
	      continue;
	    if(j*2==sz(bsst[c]))
	      return 0;
	  }
	  if(sz(bsst[d])+j<=sz(bsst[c])){
	    tcc.ad(vid[c][j],vid[c][j+sz(bsst[d])]);
	  }
	  else{
	    tcc.ad(vid[c][j],vid[d][sz(bsst[c])-j]);
	  }
	}
      }
    }
  }
  tcc.hasol();
  compsz.resize(nxid+3);
  forv(i,compsz)
    compsz[i]=0;
  forv(z,valid){
    c=valid[z];
    forv(j,vid[c]){
      ++compsz[tcc.comp[vid[c][j]]];
    }
  }
  forv(z,valid){
    c=valid[z];
    forv(j,vid[c]){
      if(j==0 || j==sz(bsst[c]))
	continue;
      if(compsz[tcc.comp[vid[c][j]]]>1)
	return 0;
    }
  }
  return 1;
}



VI mmc;
VI p;
void genpref(){//mmc[i] is the length of the LCprefix of p[0]p[1]... and p[i]p[i+1]...
  if(sz(p)==1){
    mmc={1};
    return;
  }
  in rms=1;
  in rsz=0;
  while(rsz<sz(p)-rms && p[rsz+rms]==p[rsz])
    ++rsz;
  mmc.resize(sz(p));
  mmc[0]=sz(p);
  mmc[1]=rsz;
  for(in i=2;i<sz(p);i++){
    mmc[i]=0;
    if(i<rms+rsz){
      mmc[i]=mmc[i-rms];
      if(mmc[i]+i>=rms+rsz)
	mmc[i]=rms+rsz-i;
    }
    if(i+mmc[i]>=rms+rsz){
      rms=i;
      rsz=mmc[i];
      while(rsz<sz(p)-rms && p[rsz+rms]==p[rsz])
	++rsz;
      mmc[i]=rsz;
    }
  }
}


int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  tmc.resize(n);
  bsst.resize(n);
  vid.resize(n);
  nxid=0;
  mbut.resize(n,VVI(n));
  forn(i,n){
    cin>>bsst[i];
    p.resize(sz(bsst[i]));
    forv(j,bsst[i])
      p[j]=in(bsst[i][j]);
    genpref();
    tmc[i]=mmc;
    vid[i].resize(sz(bsst[i])+1);
    forv(j,vid[i])
      vid[i][j]=nxid++;
  }
  tcc.ini(nxid);
  in sm=0;
  in nxad=0;
  in nxrm=0;
  forn(i,n){
    forn(j,n)
      gencom(i,j);
  }


  
  while(1){
    if(nxad==n)
      break;
    ad(nxad++);
    while(!isok())
      rm(nxrm++);
    sm+=nxad-nxrm;
  }
  cout<<sm<<endl;
  return 0;
}