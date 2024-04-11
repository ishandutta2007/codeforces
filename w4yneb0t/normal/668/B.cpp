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
VI sol;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,q;
  scanf("%d%d",&n,&q);
  in fs=0;
  in ss=1;
  in typ,x;
  forn(zz,q){
    scanf("%d",&typ);
    if(typ==1){
      scanf("%d",&x);
      fs+=x;
      ss+=x;
    }
    else{
      if(fs%2==0)
	++fs;
      else
	--fs;
      if(ss%2==0)
	++ss;
      else
	--ss;
    }
    while(fs<0)
      fs+=n;
    while(fs>=n)
      fs-=n;
    while(ss<0)
      ss+=n;
    while(ss>=n)
      ss-=n;
  }
  --ss;
  if(ss<0)
    ss+=n;
  sol.resize(n);
  forn(i,n){
    if(i%2==0)
      sol[(i+fs)%n]=i+1;
    else
      sol[(i+ss)%n]=i+1;
  }
  forn(i,n)
    printf("%d ",sol[i]);
  printf("\n");
  return 0;
}