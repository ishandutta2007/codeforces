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
const in tt=1009;
VVI bck;
vector<vector<pair<in,in> > > sby;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  scanf("%d",&n);
  bck.resize(tt);
  sby.resize(tt*tt);
  in x,y;
  forn(i,n){
    scanf("%d%d",&x,&y);
    sby[y].PB(MP(x,i+1));
  }
  forv(i,sby){
    forv(j,sby[i])
      bck[sby[i][j].first/tt].PB(sby[i][j].second);
  }
  forv(i,bck){
    if(i%2){
      forv(j,bck[i])
	printf("%d ",bck[i][j]);
    }
    else{
      for(in j=sz(bck[i])-1;j>=0;--j)
	printf("%d ",bck[i][j]);
    }
  }
  printf("\n");
  return 0;
}