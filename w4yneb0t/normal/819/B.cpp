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
VI p;
in bst=1e18;
in bstloc=1e9;
void adb(in sc, in lc){
  if(sc<bst){
    bst=sc;
    bstloc=lc;
  }
}
VI df;
in tsm=0;
in tlg=0;
in tdev=0;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  scanf("%lld",&n);
  p.resize(n);
  df.resize(n);
  forn(i,n){
    scanf("%lld",&(p[i]));
    --p[i];
    if(p[i]>i){
      ++tlg;
      tdev+=p[i]-i;
      ++df[p[i]-i];
    }
    else{
      ++tsm;
      tdev+=i-p[i];
      if(i>p[i])
	++df[p[i]-i+n];
    }
  }
  adb(tdev,0);
  for(in i=1;i<n;++i){
    tdev-=(n-1-p[n-i]);
    tdev+=p[n-i];
    --tsm;
    tdev-=tlg;
    tdev+=tsm;
    ++tlg;
    tlg-=df[i];
    tsm+=df[i];
    adb(tdev,i);
  }
  printf("%lld %lld\n",bst,bstloc); 
  return 0;
}