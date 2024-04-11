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
struct fenw{
  VI fw;
  in n;
  void ini(in pn){
    n=pn;
    fw.clear();
    fw.resize(n,0);
  }
  void ad(in l, in x){
    while(l<n){
      fw[l]+=x;
      l|=(l+1);
    }
  }
  in sm(in l){
    in r=0;
    while(l>=0){
      r+=fw[l];
      l&=(l+1);
      --l;
    }
    return r;
  }
};
fenw ctf,vlf;
/*
if pi > pj
count
1-((i+1)*(n-j))/tt
 */
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  ctf.ini(n);
  vlf.ini(n);
  double tt=n*(n+1)/2;
  in ta;
  double sm=0;
  in tvl=0;
  forn(z,n){
    cin>>ta;
    --ta;
    sm+=z-ctf.sm(ta);
    sm-=(tvl-vlf.sm(ta))*(n-z)/tt;
    ctf.ad(ta,1);
    vlf.ad(ta,z+1);
    tvl+=z+1;
  }
  for(in l=1;l<=n;++l){
    sm+=(n-l+1)/tt*(l*(l-1)/2)/2.0;
  }
  cout<<setprecision(15);
  cout<<sm<<endl;
  return 0;
}