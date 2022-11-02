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
int main(){
  in n,k;
  scanf("%lld%lld",&n,&k);
  VI ppw;
  for(in i=2;i<=k;++i){
    if(k%i)
      continue;
    ppw.PB(1);
    while(k%i==0){
      ppw.back()*=i;
      k/=i;
    }
  }
  in tp;
  forn(z,n){
    scanf("%lld",&tp);
    forv(i,ppw){
      if(tp%ppw[i]==0)
	ppw[i]=1;
    }
  }
  forv(i,ppw){
    if(ppw[i]!=1){
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
  return 0;
}