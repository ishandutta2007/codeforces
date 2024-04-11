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
struct segtree{
  in MX;
  VI mxp;
  VI lft,rgt;
  in mpd;
  in mxin(in l, in r, in id=1){
    if(r<lft[id] || l>rgt[id])return 0;
    if(l<=lft[id] && r>=rgt[id])return mxp[id];
    return mxin(l,r,2*id)+mxin(l,r,2*id+1);
  }
  void st(in x, in v, in id=1){
    if(x<lft[id] || x>rgt[id])return;
    if(lft[id]!=rgt[id]){
      st(x,v,2*id);
      st(x,v,2*id+1);
      mxp[id]=mxp[2*id]+mxp[2*id+1];
    }
    else{
      mxp[id]+=v;
      mxp[id]=min(mxp[id],mpd);
    }
  }
  void ini(in n, in pr){
    mpd=pr;
    MX=1;
    while(MX<n)
      MX*=2;
    mxp=VI(2*MX,0);
    lft=rgt=VI(2*MX);
    forn(i,MX)
      lft[i+MX]=rgt[i+MX]=i;
    for(in i=MX-1;i>=1;--i){
      lft[i]=lft[2*i];
      rgt[i]=rgt[2*i+1];
    }
  }
};
segtree tl,tr;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,k,b,a,q;
  cin>>n>>k>>a>>b>>q;
  n+=5;
  tl.ini(n,b);
  tr.ini(n,a);
  in typ,d,amt;
  forn(zz,q){
    cin>>typ>>d;
    if(typ==1){
      cin>>amt;
      tl.st(d,amt);
      tr.st(d,amt);
    }
    else{
      cout<<tl.mxin(0,d-1)+tr.mxin(d+k,n-1)<<"\n";
    }
  }
  return 0;
}