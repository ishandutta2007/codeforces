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
in p2(in a){
  return 1<<a;
}
const in inf=1e9;
in n;
VI nbl,nrd;
VI c,cr,cb;
in zr;
VVI bst;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  zr=n*n+5;
  bst.resize(p2(n),VI(2*zr,inf));
  c=cr=cb=VI(n);
  char clr;
  in sprb=0;
  in sprr=0;
  forn(z,n){
    cin>>clr;
    assert(clr=='R' || clr=='B');
    c[z]=(clr=='B');
    cin>>cr[z]>>cb[z];
    if(cr[z]>n){
      sprr+=cr[z]-n;
      cr[z]=n;
    }
    if(cb[z]>n){
      sprb+=cb[z]-n;
      cb[z]=n;
    }
  }
  nbl.resize(p2(n));
  nrd.resize(p2(n));
  forn(msk,p2(n)){
    forn(i,n){
      if(msk&p2(i)){
	nrd[msk]+=1-c[i];
	nbl[msk]+=c[i];
      }
    }
  }
  in adi=max(sprr,sprb);
  in strb=adi-sprb;
  in strr=adi-sprr;
  in mxnd=zr-4;
  bst[0][zr+min(strr,mxnd)-min(strb,mxnd)]=adi;
  in cstr,cstb;
  in py;
  forn(msk,p2(n)){
    forn(nxt,n){
      if(msk&p2(nxt))
	continue;
      cstr=max(0,cr[nxt]-nrd[msk]);
      cstb=max(0,cb[nxt]-nbl[msk]);
      forn(hvr,mxnd+1){
	if(bst[msk][zr+hvr]==inf)
	  continue;
	py=max(cstr-hvr,cstb);
	in& tp=bst[msk|p2(nxt)][zr+min(mxnd,py+hvr-cstr)-min(mxnd,py-cstb)];
	tp=min(tp,bst[msk][zr+hvr]+py);
      }
      forn(hvb,mxnd+1){
	if(bst[msk][zr-hvb]==inf)
	  continue;
	py=max(cstr,cstb-hvb);
	in& tp=bst[msk|p2(nxt)][zr+min(mxnd,py-cstr)-min(mxnd,py+hvb-cstb)];
	tp=min(tp,bst[msk][zr-hvb]+py);
      }
    }
  }
  in rs=inf;
  for(in i=-mxnd;i<=mxnd;++i)
    rs=min(rs,bst[p2(n)-1][zr+i]);
  cout<<rs+n<<endl;
  return 0;
}