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
const in mdl=1000000007LL;
VI nvb[2];
void upd(in sw, in nw){
  in n=sz(nvb[sw]);
  forn(i,n)
    nvb[nw][i]=0;
  in tsm=0;
  in nxc=0;
  forn(i,n){
    while(nxc<n && nxc<=2*i){
      tsm+=nvb[sw][nxc++];
      if(tsm>=mdl)
	tsm-=mdl;
    }
    nvb[nw][i]=tsm-nvb[sw][i];
    if(nvb[nw][i]<0)
      nvb[nw][i]+=mdl;
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,a,b,k;
  cin>>n>>a>>b>>k;
  if(a>b){
    a=n+1-a;
    b=n+1-b;
  }
  a=(b-1+1-a);
  n=b-1;
  a--;
  nvb[0].resize(n,1);
  nvb[1].resize(n,0);
  in sw=0;
  in nw=0;
  forn(z,k){
    sw=z%2;
    nw=!sw;
    upd(sw,nw);
  }
  cout<<nvb[nw][a]<<endl;
  return 0;
}