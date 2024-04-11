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
#define fors(i,s) for(typeof((s).begin()) i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
vector<in> pms;
vector<bool> isp;
const in mx=59;
in msz;
vector<in> dvs;
in p2(in a){
  return (1LL<<a);
}
vector<vector<in> > bst,trc;
const in inf=1000000000LL;
in n;
in dt(in a, in b){
  if(a<b)
    return b-a;
  return a-b;
}
vector<in> a;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  isp.resize(mx,1);
  isp[0]=isp[1]=0;
  forn(i,mx){
    if(isp[i]){
      pms.PB(i);
      for(in j=2*i;j<mx;j+=i)
	isp[j]=0;
    }
  }
  msz=sz(pms);
  dvs.resize(mx,0);
  for(in i=1;i<mx;i++){
    forv(j,pms){
      if(i%pms[j]==0)
	dvs[i]|=p2(j);
    }
  }
  cin>>n;
  a.resize(n);
  forn(i,n)
    cin>>a[i];
  bst.resize(n+1);
  forn(i,n+1)
    bst[i].resize(p2(msz),inf);
  trc=bst;
  bst[0][0]=0;
  forn(i,n){
    forn(msk,p2(msz))
      bst[i+1][msk]=inf;
    forn(msk,p2(msz)){
      for(in nb=1;nb<mx;nb++){
	if(dvs[nb]&msk)
	  continue;
	if(bst[i+1][dvs[nb]|msk]>dt(a[i],nb)+bst[i][msk]){
	  bst[i+1][dvs[nb]|msk]=dt(a[i],nb)+bst[i][msk];
	  trc[i+1][dvs[nb]|msk]=nb;
	}
      }
    }
  }
  in tbs=0;
  forn(msk,p2(msz)){
    if(bst[n][msk]<bst[n][tbs])
      tbs=msk;
  }
  vector<in> rt;
  for(in cr=n;cr>0;cr--){
    rt.PB(trc[cr][tbs]);
    tbs^=dvs[trc[cr][tbs]];
  }
  reverse(all(rt));
  forv(i,rt)
    cout<<rt[i]<<" ";
  cout<<endl;
  return 0;
}