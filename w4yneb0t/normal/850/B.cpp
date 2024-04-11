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
VI cnt;
VI sm;
in x,y;
const in mx=2e6+9;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n>>x>>y;
  in bst=n*x;
  in a;
  cnt.resize(mx);
  sm.resize(mx);
  forn(z,n){
    cin>>a;
    sm[a]+=a;
    ++cnt[a];
  }
  for(in i=1;i<mx;++i){
    sm[i]+=sm[i-1];
    cnt[i]+=cnt[i-1];
  }
  const in lo=1e6+3;
  in lim=x/y;
  in chav;
  in csm;
  in cst;
  for(in bas=2;bas<lo;++bas){
    in csf=0;
    in clim=min(lim,bas-1);
    for(in i=1;i*bas<mx;++i){
      chav=cnt[i*bas]-cnt[i*bas-clim-1];
      csm=sm[i*bas]-sm[i*bas-clim-1];
      cst=chav*i*bas-csm;
      if(cst>bst/y+5){
	csf=bst+9;
	break;
      }
      csf+=cst*y;
      if(csf>bst)
	break;
      csf+=(cnt[i*bas-clim-1]-cnt[(i-1)*bas])*x;
    }
    bst=min(bst,csf);
  }
  cout<<bst<<endl;
  return 0;
}