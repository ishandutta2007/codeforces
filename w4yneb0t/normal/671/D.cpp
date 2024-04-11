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
struct gvr{
  multiset<in> tvs;
  in ofs,bct,s;
  map<in,in> vup;
  gvr(){
    ofs=bct=s=0;
  }
};
VVI egs;
VVI upt,ct;
map<in,in>::iterator it;
gvr* dfs(in u, in pr){
  vector<gvr*> cds;
  in tt;
  forv(i,egs[u]){
    tt=egs[u][i];
    if(tt==pr)
      continue;
    cds.PB(dfs(tt,u));
  }
  in bind=-1;
  gvr* bs=new gvr();
  in ttc=0;
  forv(i,cds){
    ttc+=(cds[i]->ofs+cds[i]->bct);
    if(cds[i]->s>bs->s){
      bs=cds[i];
      bind=i;
    }
  }
  bs->bct=ttc-bs->ofs;
  gvr* crg;
  forv(zz,cds){
    if(bind==zz)
      continue;
    crg=cds[zz];
    bs->s+=crg->s;
    fors(i,crg->vup){
      it=bs->vup.find(i->first);
      if(it==bs->vup.end()){
	bs->vup[i->first]=i->second+crg->ofs-bs->ofs;
	bs->tvs.insert(i->second+crg->ofs-bs->ofs);
      }
      else{
	if(it->second<=i->second+crg->ofs-bs->ofs)
	  continue;
	bs->tvs.erase(bs->tvs.find(it->second));
	it->second=i->second+crg->ofs-bs->ofs;
	bs->tvs.insert(i->second+crg->ofs-bs->ofs);
      }
    }
  }
  bs->s+=sz(upt[u]);
  forv(i,upt[u]){
    it=bs->vup.find(upt[u][i]);
    if(it==bs->vup.end()){
      bs->vup[upt[u][i]]=ct[u][i]-bs->ofs;
      bs->tvs.insert(ct[u][i]-bs->ofs);
    }
    else{
      if(it->second<=ct[u][i]-bs->ofs)
	continue;
      bs->tvs.erase(bs->tvs.find(it->second));
      it->second=ct[u][i]-bs->ofs;
      bs->tvs.insert(ct[u][i]-bs->ofs);
    }
  }
  if(u==0)
    return bs;
  if(sz(bs->tvs)==0){
    cout<<-1<<endl;
    exit(0);
  }
  in mn=*(bs->tvs.begin())+bs->ofs;
  bs->ofs-=mn;
  bs->bct+=2*mn;
  it=bs->vup.find(pr);
  if(it!=bs->vup.end()){
    bs->tvs.erase(bs->tvs.find(it->second));
    bs->vup.erase(it);
  }
  return bs;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m;
  cin>>n>>m;
  egs.resize(n);
  upt.resize(n);
  ct.resize(n);
  in ta,tb,tc;
  forn(z,n-1){
    cin>>ta>>tb;
    --ta;
    --tb;
    egs[ta].PB(tb);
    egs[tb].PB(ta);
  }
  forn(z,m){
    cin>>ta>>tb>>tc;
    --ta;
    --tb;
    if(ta==tb)
      continue;
    upt[ta].PB(tb);
    ct[ta].PB(tc);
  }
  gvr* ans=dfs(0,-1);
  cout<<(ans->ofs+ans->bct)<<endl;
  return 0;
}