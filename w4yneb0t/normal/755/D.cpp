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
fenw tfw;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,k;
  scanf("%lld%lld",&n,&k);
  tfw.ini(n);
  k=min(k,n-k);
  in sm=1;
  in ci=0;
  in ni;
  forn(i,n){
    ni=(ci+k)%n;
    if(ni>ci)
      sm+=tfw.sm(ni-1)-tfw.sm(ci);
    else
      sm+=tfw.sm(ni-1)+tfw.sm(n-1)-tfw.sm(ci);
    ++sm;
    tfw.ad(ni,1);
    tfw.ad(ci,1);
    ci=ni;
    printf("%lld ",sm);
  }
  printf("\n");
  return 0;
}