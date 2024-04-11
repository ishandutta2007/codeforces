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
struct fenw{
  VI fw;
  in n;
  void ini(in pn){
    n=pn;
    fw.clear();
    fw.resize(n,0);
  }
  void ad(in l, in x){
    while(l<n){
      fw[l]+=x;
      l|=(l+1);
    }
  }
  in sm(in l){
    in r=0;
    while(l>=0){
      r+=fw[l];
      l&=(l+1);
      --l;
    }
    return r;
  }
};
VI ans;
map<in,in> codt,codx;
VVI rqtyp,rqt,rqid;
VI qtyp,qt,qx;
fenw fw;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  scanf("%d",&n);
  fw.ini(n);
  rqid.resize(n);
  ans.resize(n,-1);
  rqtyp.resize(n);
  rqt.resize(n);
  qtyp.resize(n);
  qt.resize(n);
  qx.resize(n);
  forn(i,n){
    scanf("%d%d%d",&(qtyp[i]),&(qt[i]),&(qx[i]));
    codt[qt[i]]=0;
    codx[qx[i]]=0;
  }
  in cc=0;
  fors(i,codt){
    i->second=cc;
    ++cc;
  }
  cc=0;
  fors(i,codx){
    i->second=cc;
    ++cc;
  }
  forn(i,n){
    qt[i]=codt[qt[i]];
    qx[i]=codx[qx[i]];
  }
  forn(i,n){
    rqtyp[qx[i]].PB(qtyp[i]);
    rqt[qx[i]].PB(qt[i]);
    rqid[qx[i]].PB(i);
  }
  forn(i,n){
    forv(j,rqtyp[i]){
      if(rqtyp[i][j]==1){
	fw.ad(rqt[i][j],1);
      }
      if(rqtyp[i][j]==2){
	fw.ad(rqt[i][j],-1);
      }
      if(rqtyp[i][j]==3){
	ans[rqid[i][j]]=fw.sm(rqt[i][j]);
      }
    }
    forv(j,rqtyp[i]){
      if(rqtyp[i][j]==1){
	fw.ad(rqt[i][j],-1);
      }
      if(rqtyp[i][j]==2){
	fw.ad(rqt[i][j],1);
      }
    }
  }
  forn(i,n){
    if(ans[i]!=-1)
      printf("%d\n",ans[i]);
  }
  return 0;
}