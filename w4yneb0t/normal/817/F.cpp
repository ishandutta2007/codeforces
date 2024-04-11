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
const in inf=2e18;
struct segtree{
  VI l,r,m0,m1,tad;
  void ad(in a, in b, in op, in id){
    if(b<l[id] || a>r[id])
      return;
    if(a<=l[id] && b>=r[id]){
      if(op==1){
	m0[id]=inf;
	m1[id]=l[id];
	tad[id]=1;
      }
      if(op==2){
	m0[id]=l[id];
	m1[id]=inf;
	tad[id]=2;
      }
      if(op==3){
	swap(m0[id],m1[id]);
	tad[id]=3-tad[id];
      }
      return;
    }
    prop(id);
    ad(a,b,op,2*id);
    ad(a,b,op,2*id+1);
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
    m0[id]=min(m0[2*id],m0[2*id+1]);
    m1[id]=min(m1[2*id],m1[2*id+1]);
  }
  void qr(in a, in b, in& tt, in id){
    if(b<l[id] || a>r[id])
      return;
    if(a<=l[id] && b>=r[id]){
      tt=min(tt,m0[id]);
      return;
    }
    prop(id);
    pul(id);
    qr(a,b,tt,2*id);
    qr(a,b,tt,2*id+1);
  } 
  void build(in m){
    in rm=m;
    while(m&(m-1))
      ++m;
    l.clear();
    r.clear();
    tad.clear();
    m0.clear();
    m1.clear();
    l.resize(2*m);
    r.resize(2*m);
    tad.resize(2*m,0);
    m0.resize(2*m,inf);
    forn(i,m){
      l[i+m]=r[i+m]=i;
    }
    for(in i=m;i<m+rm;++i)
      m0[i]=l[i];
    m1.resize(2*m,inf);
    for(in i=m-1;i>=1;--i){
      m0[i]=min(m0[2*i],m0[2*i+1]);
    }
    for(in i=m-1;i>=1;--i){
      l[i]=l[2*i];
      r[i]=r[2*i+1];
    }
  }
};
segtree tr;
VI qtp,ql,qr;
map<in,in> prs;
map<in,in> enc;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in q;
  cin>>q;
  qtp.resize(q);
  ql.resize(q);
  qr.resize(q);
  prs[1]=0;
  forn(z,q){
    cin>>qtp[z]>>ql[z]>>qr[z];
    prs[ql[z]]=0;
    prs[qr[z]+1]=0;
  }
  in nxt=0;
  fors(i,prs){
    i->second=nxt;
    enc[nxt]=i->first;
    ++nxt;
  }
  tr.build(nxt);
  in typ,l,r;
  forn(z,q){
    typ=qtp[z];
    l=prs[ql[z]];
    r=prs[qr[z]+1]-1;
    tr.ad(l,r,typ,1);
    typ=inf;
    tr.qr(0,nxt-1,typ,1);
    assert(typ!=inf);
    cout<<enc[typ]<<"\n";
  }
  return 0;
}