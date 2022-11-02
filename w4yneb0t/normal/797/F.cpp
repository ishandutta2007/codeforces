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
const in mx=5009;
in ab(in a){
  return a<0?-a:a;
}
in bst[2][mx];
VI mouse;
vector<pair<in,in> > hole;
in pfcst[mx];
in sw,nw;
inline in cst(const int& ms, const int& ct){
  return pfcst[ms+1]-pfcst[ms+1-ct]+bst[sw][ms-ct+1];
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m;
  cin>>n>>m;
  mouse.resize(n);
  hole.resize(m);
  forn(i,n)
    cin>>mouse[i];
  in smcap=0;
  forn(j,m){
    cin>>hole[j].first>>hole[j].second;
    smcap+=hole[j].second;
  }
  if(smcap<n){
    cout<<-1<<endl;
    return 0;
  }
  sort(all(mouse));
  sort(all(hole));
  const in inf=1e18;
  forn(z,2){
    forn(i,n+1)
      bst[z][i]=inf;
  }
  sw=1;
  nw=0;
  bst[nw][0]=bst[sw][0]=0;
  in tp;
  for(int j=1;j<=m;++j){
    swap(sw,nw);
    forn(i,n)
      pfcst[i+1]=pfcst[i]+ab(mouse[i]-hole[j-1].first);
    int lstans=-1;
    forn(i,n){
      int mn=0;
      int mx=min(hole[j-1].second,i+1);
      int md;
      if(lstans!=-1){
	++lstans;
	mn=max(mn,lstans-2);
	mx=min(mx,lstans+2);
      }
      while(mx-mn>0){
	md=(mn+mx)/2;
	tp=cst(i,md);
	if(tp>inf/10){
	  mn=md+1;
	  continue;
	}
	++md;
	if(tp>cst(i,md))
	  mn=md;
	else
	  mx=md-1;
      }
      lstans=mn;
      bst[nw][i+1]=cst(i,mn);
    }
  }
  cout<<bst[nw][n]<<endl;
  return 0;
}