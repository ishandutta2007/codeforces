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
VI bst[2];
VVI icmw,icmb;
unifnd tfd;
VI wt,bt;
VI ismw,ismb;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m,w;
  cin>>n>>m>>w;
  tfd.ini(n);
  wt=bt=VI(n);
  forn(z,n)
    cin>>wt[z];
  forn(z,n)
    cin>>bt[z];
  in ta,tb;
  forn(z,m){
    cin>>ta>>tb;
    --ta;
    --tb;
    tfd.uni(ta,tb);
  }
  ismw.resize(n);
  ismb.resize(n);
  icmw.resize(n);
  icmb.resize(n);
  forn(z,n){
    icmw[tfd.fnd(z)].PB(wt[z]);
    icmb[tfd.fnd(z)].PB(bt[z]);
    ismw[tfd.fnd(z)]+=wt[z];
    ismb[tfd.fnd(z)]+=bt[z];
  }
  forn(z,n){
    if(sz(icmw[z])){
      icmw[z].PB(ismw[z]);
      icmb[z].PB(ismb[z]);
    }
  }
  forn(z,2)
    bst[z].resize(w+1);
  in nw=0;
  in sw=1;
  forv(z,icmw){
    if(sz(icmw[z])==0)
      continue;
    swap(nw,sw);
    forn(i,w+1)
      bst[nw][i]=bst[sw][i];
    forv(zz,icmw[z]){
      forn(i,w+1-icmw[z][zz])
	bst[nw][i+icmw[z][zz]]=max(bst[nw][i+icmw[z][zz]],bst[sw][i]+icmb[z][zz]);
    }
  }
  in b=0;
  forn(i,w+1)
    b=max(b,bst[nw][i]);
  cout<<b<<endl;
  return 0;
}