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
typedef vector<in> VI;
typedef vector<VI> VVI;
const in asz=26;
in n;
VI cvl;
in cmax=-1;
in maxct=0;
string tlt;
VVI egs;
struct trie{
  in cvl;
  trie* nxt[asz];
  in totsz;
  trie(char cc='a'){
    cvl=cc-'a';
    totsz=1;
    forn(i,asz)
      nxt[i]=NULL;
  }
  void ad(const in& loc, trie* cp){
    if(cp==NULL)
      return;
    if(nxt[loc]==NULL){
      nxt[loc]=cp;
      totsz+=cp->totsz;
      return;
    }
    totsz-=nxt[loc]->totsz;
    forn(i,asz){
      nxt[loc]->ad(i,cp->nxt[i]);
    }
    totsz+=nxt[loc]->totsz;
  }
};
trie* mrg(trie* t1, trie* t2){
  if(t1==NULL){
    if(t2==NULL)
      return NULL;
    return t2;
  }
  if(t2==NULL)
    return t1;
  if((t1->totsz)<(t2->totsz))
    swap(t1,t2);
  forn(i,asz)
    t1->ad(i,t2->nxt[i]);
  return t1;
}
trie* prtr(in u, in pr){
  trie* mtr=new trie(tlt[u]);
  in tt;
  forv(i,egs[u]){
    tt=egs[u][i];
    if(tt==pr)
      continue;
    mtr->nxt[tlt[tt]-'a']=mrg(mtr->nxt[tlt[tt]-'a'],prtr(tt,u));
  }
  mtr->totsz=1;
  forn(i,asz){
    if((mtr->nxt[i])!=NULL)
      mtr->totsz+=mtr->nxt[i]->totsz;
  }
  in csz=cvl[u]+mtr->totsz;
  if(csz>cmax){
    cmax=csz;
    maxct=0;
  }
  maxct+=(csz==cmax);
  return mtr;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  cvl.resize(n);
  forn(i,n)
    cin>>cvl[i];
  cin>>tlt;
  egs.resize(n);
  in ta,tb;
  forn(i,n-1){
    cin>>ta>>tb;
    --ta;
    --tb;
    egs[ta].PB(tb);
    egs[tb].PB(ta);
  }
  prtr(0,-1);
  cout<<cmax<<endl<<maxct<<endl;
  return 0;
}