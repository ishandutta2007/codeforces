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
in pw(in a, in b){
  in r=1;
  for(in i=32;i>=0;--i){
    r=r*r%mdl;
    if(b&1LL<<i)
      r=r*a%mdl;
  }
  return r;
}
in inv(in a){
  return pw(a,mdl-2);
}
VI fc,invfc;
in ncr(in a, in b){
  if(b>a || b<0)return 0;
  return fc[a]*invfc[b]%mdl*invfc[a-b]%mdl;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  fc.resize(2*n+9);
  fc[0]=1;
  for(in i=1;i<sz(fc);++i)
    fc[i]=fc[i-1]*i%mdl;
  invfc.resize(sz(fc));
  forv(i,fc)
    invfc[i]=inv(fc[i]);
  in sm=0;
  forn(x,n+1){
    sm+=ncr(n+x+1,x+1);
  }
  sm%=mdl;
  cout<<sm<<endl;
  return 0;
}