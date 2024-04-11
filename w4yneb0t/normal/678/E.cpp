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
in p2(in a){
  return 1LL<<a;
}
in n;
vector<vector<double> > p;
vector<vector<double> > bst;
double fb(in a, in msk){
  double& tp=bst[a][msk];
  if(tp>-1)
    return tp;
  if(msk==0){
    if(a==0)
      return tp=1;
    return tp=0;
  }
  forn(i,n){
    if(!(msk&p2(i)))
      continue;
    tp=max(tp,p[a][i]*fb(a,msk^p2(i))+p[i][a]*fb(i,msk^p2(i)));
  }
  return tp;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  p.resize(n,vector<double>(n));
  forn(i,n){
    forn(j,n)
      cin>>p[i][j];
  }
  bst.resize(n,vector<double>(p2(n),-2));
  double ans=0;
  forn(i,n){
    ans=max(ans,fb(i,(p2(n)-1)^p2(i)));
  }
  cout<<setprecision(15)<<ans<<endl;
  return 0;
}