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
typedef int in;
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
VVI regs;
VVI lku,lkd;
VI vis;
VI ncd;
in gcd(in u, in pr=-1){
  vis[u]=1;
  in s=1;
  forv(i,regs[u]){
    if(regs[u][i]==pr)
      continue;
    s+=gcd(regs[u][i],u);
  }
  ncd[u]=s;
  return s;
}
void imp(){
  cout<<"No"<<endl;
  exit(0);
}
set<in>::iterator it1,it2;
void canc(set<in>* a, set<in>* b){
  it1=b->begin();
  while(it1!=b->end()){
    if(a->find(*it1)!=a->end()){
      a->erase(*it1);
      it2=it1;
      ++it1;
      b->erase(it2);
      continue;
    }
    ++it1;
  }
}
pair<set<in>*, set<in>* > ttf(in u, in pr=-1){
  vis[u]=1;
  in mc=-1;
  in mid=-1;
  forv(i,regs[u]){
    if(regs[u][i]==pr)
      continue;
    if(ncd[regs[u][i]]>mc){
      mc=ncd[regs[u][i]];
      mid=i;
    }
  }
  if(mc==-1){
    set<in>* lu=new set<in>();
    set<in>* ld=new set<in>();
    forv(i,lku[u])
      lu->insert(lku[u][i]);
    forv(i,lkd[u])
      ld->insert(lkd[u][i]);
    if(sz(*lu)&&sz(*ld))
      imp();
    return MP(lu,ld);
  }
  pair<set<in>*, set<in>* > tp=ttf(regs[u][mid],u);
  set<in>* lu=tp.first;
  set<in>* ld=tp.second;
  forv(i,lku[u]){
    if(ld->find(lku[u][i])==ld->end())
      lu->insert(lku[u][i]);
    else
      ld->erase(lku[u][i]);
  }
  forv(i,lkd[u]){
    if(lu->find(lkd[u][i])==lu->end())
      ld->insert(lkd[u][i]);
    else
      lu->erase(lkd[u][i]);
  }
  forv(i,regs[u]){
    if(i==mid)
      continue;
    if(regs[u][i]==pr)
      continue;
    tp=ttf(regs[u][i],u);
    canc(lu,tp.second);
    canc(ld,tp.first);
    fors(i,*(tp.first))
      lu->insert(*i);
    fors(i,*(tp.second))
      ld->insert(*i);
  }
  if(sz(*lu)&&sz(*ld))
    imp();
  return MP(lu,ld);
}
VI ax,ay;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m,q;
  cin>>n>>m>>q;
  mbr.ini(n+m);
  in ta,tb;
  forn(z,m){
    cin>>ta>>tb;
    --ta;
    --tb;
    if(ta==tb)
      continue;
    ax.PB(ta);
    ay.PB(tb);
    mbr.ad(ta,z+n);
    mbr.ad(tb,z+n);
  }
  mbr.hasol();
  regs.resize(n+m);
  in negs=0;
  forv(z,ax){
    if(mbr.comp[ax[z]]==mbr.comp[ay[z]])
      continue;
    ++negs;
    regs[mbr.comp[ax[z]]].PB(mbr.comp[ay[z]]);
    regs[mbr.comp[ay[z]]].PB(mbr.comp[ax[z]]);
  }
  lku.resize(n+m);
  lkd.resize(n+m);
  forn(z,q){
    cin>>ta>>tb;
    --ta;
    --tb;
    if(mbr.comp[ta]==mbr.comp[tb])
      continue;
    lku[mbr.comp[ta]].PB(z);
    lkd[mbr.comp[tb]].PB(z);
  }
  ncd.resize(n+m);
  vis.resize(n+m);
  forn(i,n+m){
    if(!vis[i]){
      ++negs;
      gcd(i);
    }
  }
  assert(negs==n+m);
  vis=VI(n+m,0);
  forn(i,n+m){
    if(!vis[i])
      ttf(i);
  }
  cout<<"Yes"<<endl;
  return 0;
}