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
vector<string> rst;
VVI rcost;
VI msk;
VI cst;
void gnmsk(in id){
  for(char z='a';z<='z';++z){
    in mex=-1;
    in sm=0;
    in tms=0;
    forn(i,n){
      if(rst[i][id]==z){
	tms+=(1LL<<i);
	sm+=rcost[i][id];
	mex=max(mex,rcost[i][id]);
      }
    }
    if(mex==-1)continue;
    msk.PB(tms);
    cst.PB(sm-mex);
  }
}
VI bst;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in pn;
  cin>>pn>>m;
  string tp;
  forn(i,pn){
    cin>>tp;
    rst.PB(tp);
  }
  VI tt;
  forn(i,pn){
    tt.resize(m);
    forn(j,m)
      cin>>tt[j];
    rcost.PB(tt);
  }
  n=sz(rst);
  forn(i,n){
    in mn=1000000000LL;
    forn(j,m)
      mn=min(mn,rcost[i][j]);
    msk.PB(1LL<<i);
    cst.PB(mn);
  }
  forn(j,m)
    gnmsk(j);
  bst.resize(1LL<<n,1000000000LL);
  bst[0]=0;
  forv(j,msk){
    forv(x,bst){
      bst[x|msk[j]]=min(bst[x|msk[j]],bst[x]+cst[j]);
    }
  }
  cout<<bst[(1LL<<n)-1]<<endl;
  return 0;
}