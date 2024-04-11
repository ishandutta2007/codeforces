#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#include<stack>
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
    impl[a].PB(b);
    impl[neg(b)].PB(neg(a));
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
    forn(i,mhsh)
      if(comp[i]==comp[neg(i)])
	return 0;
    return 1;
  }
  VVI incomp;
  VI compindeg;
  queue<in> q;
  VI compval;
  void mksol(VI& tvl){
    tvl.resize(mhsh);
    compval.clear();
    incomp.clear();
    compindeg.clear();
    while(!q.empty())
      q.pop();
    in cct=0;
    forv(i,comp)
      cct=max(cct,comp[i]);
    ++cct;
    compval.resize(cct,-1);
    compindeg.resize(cct,0);
    incomp.resize(cct);
    forv(i,comp){
      incomp[comp[i]].PB(i);
      forv(j,impl[i]){
	if(comp[impl[i][j]]!=comp[i])
	  ++compindeg[comp[impl[i][j]]];
      }
    }
    forn(i,cct){
      if(compindeg[i]==0 && compval[i]==-1){
	compval[i]=0;
	compval[comp[neg(incomp[i][0])]]=1;
	q.push(i);
      }
    }
    in u;
    in cspc;
    in cimp;
    while(!q.empty()){
      u=q.front();
      q.pop();
      forv(i,incomp[u]){
	cspc=incomp[u][i];
	if(cspc<mhsh)
	  tvl[cspc]=0;
	else
	  tvl[neg(cspc)]=1;
	forv(j,impl[cspc]){
	  cimp=comp[impl[cspc][j]];
	  --compindeg[cimp];
	  if(compindeg[cimp]==0 && compval[cimp]==-1){
	    compval[cimp]=0;
	    q.push(cimp);
	    compval[comp[neg(incomp[cimp][0])]]=1;
	  }
	}
      }
    }
  }
};
//call mksol(v) if hasol() returned 1, then v[i] is 0 or 1 for 0<=i<n
twosat tt;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<string> s[2];
  string s1,s2;
  in n;
  cin>>n;
  forn(i,n){
    cin>>s1>>s2;
    s[0].PB(s1.substr(0,3));
    s[1].PB(s1.substr(0,2)+s2.substr(0,1));
  }
  tt.ini(n);
  forn(i,n){
    forn(j,i){
      if(s[0][i]==s[0][j]){
	tt.ad(i,i+n);
	tt.ad(j,j+n);
      }
      forn(a,2){
	forn(b,2){
	  if(s[a][i]==s[b][j]){
	    tt.ad(i+a*n,j+(1-b)*n);
	  }
	}
      }
    }
  }
  if(!tt.hasol()){
    cout<<"NO"<<endl;
    return 0;
  }
  cout<<"YES"<<endl;
  VI v;
  tt.mksol(v);
  forn(i,n){
    if(v[i]==1)
      cout<<s[0][i]<<endl;
    else
      cout<<s[1][i]<<endl;
  }
  return 0;
}