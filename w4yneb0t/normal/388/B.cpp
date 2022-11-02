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
#define C 999
using namespace std;
typedef long long in;
bool a[C][C];
in goal;
string s[C];
int main(){
  cin>>goal;
  forn(i,C)
    forn(j,C)
      a[i][j]=0;
  a[0][10]=1;
  a[0][11]=1;
  for(in i=0;i<40;i++){
    forn(c1,2)
      forn(c2,2)
	a[10+2*i+c1][10+2*(i+1)+c2]=1;
  }
  in bpt=100;
  in mlt=35;
  for(in i=0;i<35;i++){
    if(!(goal&(1LL<<i)))
      continue;
    in prv=10+2*i;
    for(in j=i;j<mlt;j++){
      a[prv][bpt]=1;
      prv=bpt;
      bpt++;
    }
    a[prv][1]=1;
  }
  forn(i,bpt)
    forn(j,bpt)
      if(a[i][j])
	a[j][i]=1;
  cout<<bpt<<endl;
  forn(i,bpt){
    forn(j,bpt){
      if(a[i][j])
	s[i]+='Y';
      else
	s[i]+='N';
    }
    cout<<s[i]<<endl;
  }
  return 0;
}