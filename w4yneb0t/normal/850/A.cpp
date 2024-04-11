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
VVI pt;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  if(n>300){
    cout<<0<<endl;
    return 0;
  }
  pt.resize(n,VI(5));
  forn(i,n){
    forn(j,5)
      cin>>pt[i][j];
  }
  VI gd;
  bool isg;
  in tpr;
  forn(i,n){
    isg=1;
    forn(j,n){
      if(i==j)
	continue;
      forn(k,j){
	if(i==k)
	  continue;
	tpr=0;
	forn(z,5){
	  tpr+=(pt[j][z]-pt[i][z])*(pt[k][z]-pt[i][z]);
	}
	if(tpr>0){
	  isg=0;
	  break;
	}
      }
      if(!isg)
	break;
    }
    if(isg)
      gd.PB(i+1);
  }
  cout<<sz(gd)<<endl;
  forv(i,gd)
    cout<<gd[i]<<" ";
  cout<<endl;
  return 0;
}