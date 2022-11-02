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
in n,m;
VVI egs;
VI mcmp,hsc;
VI indeg;
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
set<in> totcps;
queue<in> q;
VI vs;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  egs.resize(n);
  in ta,tb;
  tfd.ini(n);
  indeg.resize(n);
  forn(z,m){
    cin>>ta>>tb;
    --ta;
    --tb;
    egs[ta].PB(tb);
    ++indeg[tb];
    tfd.uni(ta,tb);
  }
  mcmp.resize(n);
  hsc.resize(n);
  vs.resize(n);
  forn(i,n){
    totcps.insert(tfd.fnd(i));
    mcmp[i]=tfd.fnd(i);
    if(indeg[i]==0){
      q.push(i);
      vs[i]=1;
    }
  }
  in u,tt;
  while(!q.empty()){
    u=q.front();
    q.pop();
    forv(i,egs[u]){
      tt=egs[u][i];
      --indeg[tt];
      if(!indeg[tt]){
	vs[tt]=1;
	q.push(tt);
      }
    }
  }
  forn(i,n){
    if(!vs[i])
      hsc[mcmp[i]]=1;
  }
  in rs=n-sz(totcps);
  fors(i,totcps)
    if(hsc[*i])
      ++rs;
  cout<<rs<<endl;
  return 0;
}