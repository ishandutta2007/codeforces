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
struct segtree{
  in MX;
  const in inf=1000000000;
  VI mxp;
  VI lft,rgt;
  in mxin(in l, in r, in id=1){
    if(r<lft[id] || l>rgt[id])return -inf;
    if(l<=lft[id] && r>=rgt[id])return mxp[id];
    return max(mxin(l,r,2*id),mxin(l,r,2*id+1));
  }
  void st(in x, in v, in id=1){
    if(x<lft[id] || x>rgt[id])return;
    if(lft[id]!=rgt[id]){
      st(x,v,2*id);
      st(x,v,2*id+1);
      mxp[id]=max(mxp[2*id],mxp[2*id+1]);
    }
    else
      mxp[id]=v;
  }
  void ini(in n){
    MX=1;
    while(MX<n)
      MX*=2;
    mxp=VI(2*MX,inf);
    lft=rgt=VI(2*MX);
    forn(i,MX)
      lft[i+MX]=rgt[i+MX]=i;
    for(in i=MX-1;i>=1;--i){
      lft[i]=lft[2*i];
      rgt[i]=rgt[2*i+1];
    }
  }
};
segtree tr;
VI mx,my,qx1,qy1,qx2,qy2;
in n,m,k,q;
VI tisg;
struct evt{
  in typ;// 0 add, 1 query
  in x2,y1,id; //only for query
  in x1,y2;
  bool operator<(const evt cp)const{
    if(y2!=cp.y2)
      return y2<cp.y2;
    return typ<cp.typ;
  }
};
vector<evt> evts;
void slv(){
  tr.ini(n+1);
  evt tp;
  tp.typ=0;
  evts.clear();
  forn(i,k){
    tp.x1=mx[i];
    tp.y2=my[i];
    evts.PB(tp);
  }
  tp.typ=1;
  forn(i,q){
    tp.id=i;
    tp.x1=qx1[i];
    tp.x2=qx2[i];
    tp.y1=qy1[i];
    tp.y2=qy2[i];
    evts.PB(tp);
  }
  sort(all(evts));
  forv(z,evts){
    tp=evts[z];
    if(tp.typ==0){
      tr.st(tp.x1,-tp.y2);
      continue;
    }
    if(tr.mxin(tp.x1,tp.x2)>-tp.y1)
      continue;
    tisg[tp.id]=1;
  }
}

VI isg;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m>>k>>q;
  mx.resize(k);
  my.resize(k);
  qx1.resize(q);
  qx2.resize(q);
  qy1.resize(q);
  qy2.resize(q);
  forn(i,k){
    cin>>mx[i]>>my[i];
  }
  forn(i,q){
    cin>>qx1[i]>>qy1[i]>>qx2[i]>>qy2[i];
  }
  tisg.resize(q);
  slv();
  isg=tisg;
  forn(i,q)
    tisg[i]=0;
  swap(mx,my);
  swap(qx1,qy1);
  swap(qx2,qy2);
  swap(n,m);
  slv();
  forn(i,q){
    if(tisg[i]||isg[i])
      cout<<"YES\n";
    else
      cout<<"NO\n";
  }
  return 0;
}