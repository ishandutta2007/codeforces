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
VI ex,ey;
in co(in n, in k){
  if(n==1)
    return 0;
  if(n==2){
    ex.PB(0);
    ey.PB(1);
    return 1;
  }
  k=min(k,n-1);
  assert(k>=2);
  if(n==k+1){
    for(in i=n-1;i>=n-k;--i){
      ex.PB(0);
      ey.PB(i);
    }
    return 2;
  }
  if(n==k+2){
    ex.PB(0);
    ey.PB(2);
    ex.PB(0);
    ey.PB(1);
    for(in i=3;i<n;++i){
      ex.PB(1);
      ey.PB(i);
    }
    return 3;
  }
  in sf=co(n-k,k);
  in nxtu=n-k-1;
  for(in i=nxtu+1;i<n;++i){
    ex.PB(nxtu--);
    if(nxtu<0)
      nxtu=0;
    ey.PB(i);
  }
  return 2+sf;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,k;
  cin>>n>>k;
  cout<<co(n,k)<<"\n";
  forv(i,ex){
    cout<<ex[i]+1<<" "<<ey[i]+1<<"\n";
  }
  return 0;
}