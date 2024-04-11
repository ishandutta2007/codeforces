#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
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
//impl[a] lists all the things that a implies
//neg(a) is the negation of a
//the variables are from 0 to mhsh-1, their negations from mhsh to 2*mhsh-1
template<typename T>
void clr(stack<T> t){
  while(!t.empty())
    t.pop();
}
VVI ppi;
struct twosat{
  in mhsh;
  vector<vector<in> > impl;
  stack<in> whr;
  stack<in> hsn;
  stack<in> ci;
  vector<in> vst;
  vector<in> hit;
  stack<in> ts;
  vector<in> comp,psd,gvh;
  in neg(in h){
    return h>=mhsh?h-mhsh:h+mhsh;
  }
  void add(in a, in b){
    impl[a].PB(b);
    impl[neg(b)].PB(neg(a));
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
};
void ans(VI q){
  forv(i,q)
    cout<<char(q[i]+'a');
  cout<<endl;
  exit(0);
}
VI vow;
in l,n;
VVI egs[2];
VVI egtp[2];
twosat tps;
in prc(in lc, in typ){
  if(typ==0)
    return lc;
  return tps.neg(lc);
}
bool isw(VI q){
  if(sz(ppi)==0){
    tps.impl=VVI(2*n+2,VI(0));
    tps.mhsh=n+1;
    tps.impl[tps.neg(n)].PB(n);
    forn(i,n){
      forn(z,2){
	forv(j,egs[z][i])
	  tps.add(prc(i,z),prc(egs[z][i][j],egtp[z][i][j]));
      }
    }
    ppi=tps.impl;
  }
  else
    tps.impl=ppi;
  forv(i,q)
    tps.add(n,prc(i,q[i]));
  return tps.hasol();
}
VI gbd(VI q){
  VI typq(sz(q));
  forv(i,q)
    typq[i]=vow[q[i]];
  assert(isw(typq));
  for(in i=sz(q);i<n;i++){
    VI ckd(2,0);
    bool ock=0;
    for(in k=0;k<l;k++){
      if(ckd[vow[k]])continue;
      ckd[vow[k]]=1;
      typq.PB(vow[k]);
      if(ock || isw(typq)){
	q.PB(k);
	break;
      }
      typq.pop_back();
      ock=1;
    }
  }
  return q;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  string tps;
  cin>>tps;
  l=sz(tps);
  vow=VI(l);
  VI sint(2,0);
  forv(i,tps){
    vow[i]=(tps[i]=='V');
    sint[vow[i]]=1;
  }
  in m;
  cin>>n>>m;
  forn(z,2){
    egs[z].resize(n);
    egtp[z].resize(n);
  }
  in ta,tb;
  char tpa,tpb;
  in typa,typb;
  forn(z,m){
    cin>>ta>>tpa>>tb>>tpb;
    ta--;
    tb--;
    typa=(tpa=='V');
    typb=(tpb=='V');
    egs[typa][ta].PB(tb);
    egtp[typa][ta].PB(typb);
    if(!sint[0] || !sint[1]){
      in tal=0;
      if(!sint[0])tal=1;
      if(typa==tal && typb!=tal){
	cout<<-1<<endl;
	return 0;
      }
    }
  }
  string llm;
  cin>>llm;
  if(!sint[0] || !sint[1]){
    cout<<llm<<endl;
    return 0;
  }
  assert(sz(llm)==n);
  VI qr(n);
  VI typq(n,0);
  forv(i,llm){
    qr[i]=llm[i]-'a';
    typq[i]=vow[qr[i]];
  }
  if(isw(typq))
    ans(qr);
  for(in i=n;i>=1;i--){
    typq.clear();
    typq.resize(i);
    forn(j,i-1)
      typq[j]=vow[qr[j]];
    VI ckd(2,0);
    for(in k=qr[i-1]+1;k<l;k++){
      if(ckd[vow[k]])continue;
      ckd[vow[k]]=1;
      typq[i-1]=vow[k];
      if(isw(typq)){
	qr.resize(i);
	qr.back()=k;
	ans(gbd(qr));
      }
    }
  }
  cout<<-1<<endl;
  return 0;
}