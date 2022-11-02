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
using namespace std;
typedef long long in;
in a[109];
bool ud[109];
int main(){
  in n;
  cin>>n;
  forn(i,n)
    cin>>a[i];
  forn(i,n)
    ud[i]=0;
  sort(a,a+n);
  for(in k=0;1;k++){
    bool done=1;
    forn(i,n)
      done&=ud[i];
    if(done){
      cout<<k<<endl;
      break;
    }
    in ctt=0;
    forn(i,n){
      if(!ud[i] && a[i]>=ctt){
	ud[i]=1;
	ctt++;
      }
    }
  }
  return 0;
}