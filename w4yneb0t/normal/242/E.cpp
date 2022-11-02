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
VI mar;
struct segtree{
  VI l,r,mn,tad;
  void ad(in a, in b, in v, in id){
    if(b<l[id] || a>r[id])
      return;
    if(a<=l[id] && b>=r[id]){
      if(v)
	mn[id]=r[id]-l[id]+1-mn[id];
      tad[id]^=v;
      return;
    }
    prop(id);
    ad(a,b,v,2*id);
    ad(a,b,v,2*id+1);
    pul(id);
  }
  void prop(in id){ 
    if(tad[id]!=0 && l[id]!=r[id]){
      ad(l[id],r[id],tad[id],2*id);
      ad(l[id],r[id],tad[id],2*id+1);
    }
    tad[id]=0;
  }
  void pul(in id){
    assert(l[id]!=r[id]);
    mn[id]=mn[2*id]+mn[2*id+1];
  }
  void qr(in a, in b, in& tt, in id){
    if(b<l[id] || a>r[id])
      return;
    if(a<=l[id] && b>=r[id]){
      tt+=mn[id];
      return;
    }
    prop(id);
    pul(id);
    qr(a,b,tt,2*id);
    qr(a,b,tt,2*id+1);
  } 
  void build(in m, in bt){
    while(m&(m-1))
      ++m;
    l.clear();
    r.clear();
    tad.clear();
    mn.clear();
    l.resize(2*m);
    r.resize(2*m);
    tad.resize(2*m,0);
    mn.resize(2*m,0);
    forv(i,mar){
      if(mar[i]&(1LL<<bt))
	mn[i+m]=1;
    }
    for(in i=m-1;i>=1;--i){
      mn[i]=mn[2*i]+mn[2*i+1];
    }
    forn(i,m){
      l[i+m]=r[i+m]=i;
    }
    for(in i=m-1;i>=1;--i){
      l[i]=l[2*i];
      r[i]=r[2*i+1];
    }
  }
};
const in mxb=20;
vector<segtree> stri(mxb);
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  mar.resize(n);
  forn(i,n)
    cin>>mar[i];
  forn(i,mxb)
    stri[i].build(n,i);
  in m;
  cin>>m;
  in ta,tb,tx,ttyp;
  in s=0;
  in tm;
  forn(zz,m){
    cin>>ttyp>>ta>>tb;
    --ta;
    --tb;
    if(ttyp==1){
      s=0;
      forn(i,mxb){
	tm=0;
	stri[i].qr(ta,tb,tm,1);
	s+=tm*(1LL<<i);
      }
      cout<<s<<"\n";
    }
    else{
      cin>>tx;
      forn(i,mxb){
	if(tx&(1LL<<i))
	  stri[i].ad(ta,tb,1,1);
      }
    }
  }
  return 0;
}