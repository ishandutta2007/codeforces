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
in p2(const in& a){
  return 1<<a;
}
in cc;
struct tri{
  in cbl;
  tri* nxt[2];
  in ckr;
  tri(in c){
    ckr=c;
    cbl=0;
    nxt[0]=nxt[1]=NULL;
  }
  void ad(const in& p, const in& f){
    cbl+=f;
    if(ckr>=0){
      cc=(p&p2(ckr))>>ckr;
      if(nxt[cc]==NULL)
	nxt[cc]=new tri(ckr-1);
      nxt[cc]->ad(p,f);
    }
  }
  tri* nt(in b){
    assert(ckr>=0);
    if(nxt[b]==NULL){
      nxt[b]=new tri(ckr-1);
    }
    return nxt[b];
  }
};
tri* rt=new tri(26);
void smp(in p, in l){
  in sm=0;
  tri* cr=rt;
  in flp,nd;
  for(in a=26;a>=0;--a){
    flp=(p&p2(a))>>a;
    nd=(l&p2(a))>>a;
    if(!nd){
      cr=cr->nt(flp);
    }
    else{
      sm+=cr->nt(flp)->cbl;
      cr=cr->nt(!flp);
    }
  }
  cout<<sm<<"\n";
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in q;
  cin>>q;
  in typ,p,l;
  forn(zz,q){
    cin>>typ>>p;
    if(typ==1){
      rt->ad(p,1);
    }
    if(typ==2){
      rt->ad(p,-1);
    }
    if(typ==3){
      cin>>l;
      smp(p,l);
    }
  }
  return 0;
}