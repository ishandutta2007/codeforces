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
in cls(in ost, in bdg, in nud){
  if(bdg>nud)
    return 0;
  if(bdg<nud)
    return 2;
  return ost;
}
in cnt(in mx, in ds){
  ++mx;
  VI dg;
  while(mx>0){
    dg.PB(mx%10);
    mx/=10;
  }
  VVI wys(ds+1,VI(3,0));
  VVI nwys(ds+1,VI(3,0));
  wys[0][1]=1;
  in tdg;
  forv(z,dg){
    tdg=dg[z];
    forv(i,nwys){
      forv(j,nwys[i]){
	nwys[i][j]=0;
      }
    }
    forv(i,wys){
      forv(j,wys[i]){
	for(in nud=0;nud<10 && nud+i<sz(wys);++nud){
	  nwys[i+nud][cls(j,tdg,nud)]+=wys[i][j];
	}
      }
    }
    wys=nwys;
  }
  return wys[ds][0];
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,s;
  cin>>n>>s;
  in bd=0;
  for(in ds=1;ds<=200;++ds){
    in mx=min(n,ds+s-1);
    bd+=cnt(mx,ds);
  }
  cout<<n-bd<<endl;
  return 0;
}