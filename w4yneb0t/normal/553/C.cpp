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
struct unifnd{
  VI ht,pr;
  in fnd(in a){
    in ta=a;
    while(a!=pr[a])a=pr[a];
    in tt=ta;
    while(ta!=a){
      tt=pr[ta];
      pr[ta]=a;
      ta=tt;
    }
    return a;
  }
  void uni(in a, in b){
    a=fnd(a);
    b=fnd(b);
    if(a==b)return;
    if(ht[b]<ht[a])swap(a,b);
    pr[a]=b;
    ht[b]+=(ht[a]==ht[b]);
  }
  void ini(in n){
    ht.resize(n);
    pr.resize(n);
    forn(i,n){
      ht[i]=0;
      pr[i]=i;
    }
  }
};
unifnd tfd;
VI x,y;
VI sof;
VVI egs;
in n;
void mksof(in u, in c){
  if(sof[u]!=-1){
    if(sof[u]!=c){
      cout<<0<<endl;
      exit(0);
    }
    return;
  }
  sof[u]=c;
  forv(i,egs[u])
    mksof(egs[u][i],!c);
}
void bg(){
  forn(i,n){
    if(sof[i]!=-1)
      continue;
    mksof(i,0);
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in m;
  cin>>n>>m;
  tfd.ini(n);
  in ta,tb,tc;
  forn(z,m){
    cin>>ta>>tb>>tc;
    --ta;
    --tb;
    if(tc)
      tfd.uni(ta,tb);
    else{
      x.PB(ta);
      y.PB(tb);
    }
  }
  sof.resize(n,-1);
  egs.resize(n);
  in tx,ty;
  forv(i,x){
    tx=tfd.fnd(x[i]);
    ty=tfd.fnd(y[i]);
    egs[tx].PB(ty);
    egs[ty].PB(tx);
  }
  bg();
  forv(i,x)
    tfd.uni(x[i],y[i]);
  in ncmp=0;
  forn(i,n){
    if(tfd.fnd(i)==i)
      ++ncmp;
  }
  in rs=1;
  forn(i,ncmp-1)
    rs=2*rs%1000000007;
  cout<<rs<<endl;
  return 0;
}