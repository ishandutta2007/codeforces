#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#define PB push_back
#define sz(v) ((v).size())
#define forn(i,n) for(in i=0;i<(n);i++)
#define forv(i,v) forn(i,sz(v))
#define C 40
using namespace std;
typedef long long in;
in mdl=1000000007LL;
in crt[C][C];
in ncr[C][C];
in nb;
in pwt[C];
int main(){
  pwt[0]=1;
  for(in i=1;i<C;i++){
    pwt[i]=(2*pwt[i-1])%mdl;
  }
  cin>>nb;
  forn(i,C){
    forn(j,C){
      crt[i][j]=ncr[i][j]=0;
    }
  }
  crt[C-1][0]=1;
  for(in i=C-2;i>=0;i--){
    for(in j=0;j<C;j++){
      ncr[i][j]+=ncr[i+1][j]*pwt[j];
      ncr[i][j+1]+=ncr[i+1][j];
      if(nb&(1LL<<i)){
	crt[i][j+1]+=crt[i+1][j];
	ncr[i][j]+=crt[i+1][j]*(j==0?1:pwt[j-1]);
	crt[i][j]+=crt[i+1][j]*(j==0?0:pwt[j-1]);
      }
      else{
	crt[i][j]+=crt[i+1][j]*(j==0?1:pwt[j-1]);
      }
    }
    forn(j,C){
      ncr[i][j]%=mdl;
      crt[i][j]%=mdl;
    }
  }
  in totl=0;
  forn(j,C)
    totl+=ncr[0][j]+crt[0][j];
  totl%=mdl;
  cout<<totl<<endl;
  return 0;
}