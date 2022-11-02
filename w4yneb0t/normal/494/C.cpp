#include<iostream>
#include<iomanip>
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
const in mct=10009;
in n;
in tmx;
VI mar;
struct quer{
  in l,r;
  double p;
  bool operator<(const quer cp)const{
    if(l!=cp.l)
      return l<cp.l;
    return r-l>cp.r-cp.l;
  }
};
vector<quer> quers;
VVI cd;
vector<double> slv(in u){
  in mmx=-1;
  in nxs=0;
  in nlc=quers[u].l;
  while(nlc<=quers[u].r){
    if(nxs<sz(cd[u]) && nlc==quers[cd[u][nxs]].l)
      nlc=quers[cd[u][nxs++]].r;
    else
      mmx=max(mmx,mar[nlc++]);
  }
  vector<double> psf(mct,0);
  vector<double> trs,pfx,tfx,nu;
  forv(i,cd[u]){
    trs=slv(cd[u][i]);
    pfx.resize(mct);
    pfx[0]=1;
    forn(j,mct)
      pfx[0]-=psf[j];
    forn(j,mct-1)
      pfx[j+1]=pfx[j]+psf[j];
    tfx.resize(mct);
    tfx[0]=1;
    forn(j,mct)
      tfx[0]-=trs[j];
    forn(j,mct-1)
      tfx[j+1]=tfx[j]+trs[j];
    nu.resize(mct);
    forn(j,mct){
      nu[j]=pfx[j]*trs[j]+psf[j]*tfx[j]+psf[j]*trs[j];
    }
    psf=nu;
  }
  mmx-=tmx;
  if(mmx>=0){
    double hpr=0;
    for(in i=mmx+1;i<mct;++i)
      hpr+=psf[i];
    forn(i,mmx)
      psf[i]=0;
    psf[mmx]=1-hpr;
  }
  double p=quers[u].p;
  double q=1-p;
  for(in i=mct-1;i>=1;--i)
    psf[i]=q*psf[i]+p*psf[i-1];
  return psf;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in q;
  tmx=-1;
  cin>>n>>q;
  mar.resize(n);
  forn(i,n){
    cin>>mar[i];
    tmx=max(mar[i],tmx);
  }
  tmx-=mct/2;
  quers.resize(q+1);
  forn(z,q){
    cin>>quers[z].l>>quers[z].r>>quers[z].p;
    quers[z].l--;
    quers[z].r--;
  }
  quers[q].l=0;
  quers[q].r=n-1;
  quers[q].p=0;
  ++q;
  sort(all(quers));
  cd.resize(q);
  forn(z,q){
    in blt=10000000;
    in lc=-1;
    forn(i,z){
      if(quers[i].l<=quers[z].l && quers[i].r>=quers[z].r){
	if(quers[i].r-quers[i].l<=blt){
	  blt=quers[i].r-quers[i].l;
	  lc=i;
	}
      }
    }
    if(lc!=-1){
      cd[lc].PB(z);
    }
  }
  vector<double> tpr=slv(0);
  double av=0;
  forv(i,tpr){
    av+=tpr[i]*(i+tmx);
  }
  cout<<setprecision(20)<<av<<endl;
  return 0;
}