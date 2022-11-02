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
#define forn(i,n) for(in i=0;i<(n);i++)
#define forv(i,v) forn(i,sz(v))
using namespace std;
typedef long long in;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in t,n,p;
  cin>>t;
  forn(z,t){
    cin>>n>>p;
    in n0=2;
    while(n0*(n0-1)/2<2*n0+p)
      n0++;
    in e0=2*n0+p;
    forn(i,n0){
      for(in j=i+1;j<n0;j++){
	cout<<i+1<<" "<<j+1<<endl;
	e0--;
	if(e0==0)
	  break;
      }
      if(e0==0)
	break;
    }
    for(in i=n0;i<n;i++)
      cout<<1<<" "<<i+1<<endl<<2<<" "<<i+1<<endl;
  }
  return 0;
}