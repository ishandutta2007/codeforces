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
VVI btm;
VI c;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  c.resize(n);
  forn(i,n)
    cin>>c[i];
  btm.resize(n,VI(n+1,100000));
  forn(i,n)
    btm[i][i]=btm[i][i+1]=1;
  for(in l=2;l<=n;++l){
    for(in i=0;i+l<=n;++i){
      for(in j=i+1;j<i+l;++j)
	btm[i][i+l]=min(btm[i][i+l],btm[i][j]+btm[j][i+l]);
      if(c[i]==c[i+l-1])
	btm[i][i+l]=min(btm[i][i+l],btm[i+1][i+l-1]);
    }
  }
  cout<<btm[0][n]<<endl;
  return 0;
}