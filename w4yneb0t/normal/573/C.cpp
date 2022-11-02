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
VVI egs;
in tz;
VI deg;
VI fixd;
VI remd;
VI htbm;
void rmf(in u){
  in tt;
  remd[u]=1;
  forv(i,egs[u]){
    tt=egs[u][i];
    if(fixd[tt] || remd[tt])continue;
    if(deg[tt]>2){
      fixd[tt]=1;
      if(deg[tt]>3)
	htbm[tt]=1;
      continue;
    }
    if(htbm[tt] && tz!=2)
      continue;
    if(tz!=1)
      rmf(tt);
  }
}
VVI negs;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  egs.resize(n);
  in ta,tb;
  fixd=deg=remd=htbm=VI(n,0);
  forn(i,n-1){
    cin>>ta>>tb;
    ta--;
    tb--;
    deg[ta]++;
    deg[tb]++;
    egs[ta].PB(tb);
    egs[tb].PB(ta);
  }
  forn(zz,3){
    tz=zz;
    forn(i,n){
      if(remd[i] || fixd[i] || (htbm[i] && zz==1))continue;
      if(deg[i]<=1)
	rmf(i);
    }
    deg=VI(n,0);
    negs=VVI(n);
    forn(i,n){
      if(remd[i])continue;
      forv(j,egs[i]){
	if(!remd[egs[i][j]]){
	  deg[i]++;
	  negs[i].PB(egs[i][j]);
	}
      }
    }
    egs=negs;
    forn(i,n)
      if(deg[i]>=2 && fixd[i])
	htbm[i]=1;
    fixd=VI(n,0);
  }
  forn(i,n){
    if(!remd[i]){
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
  return 0;
}