#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#include<cmath>
#define PB push_back
#define MP make_pair
#define sz(v) (in((v).size()))
#define forn(i,n) for(in i=0;i<(n);i++)
#define forv(i,v) forn(i,sz(v))
using namespace std;
typedef long long in;
double ab(double a){
  if(a<0)
    return -a;
  return a;
}
double f(in ai, in hi){
  double a=ai;
  double h=hi;
  double c=sqrt(a*a*0.25+h*h);
  double r=a*0.5*h/c;
  return r;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  double x;
  cin>>x;
  double best=1;
  in ba,bh;
  for(in ai=1;ai<=10;ai++){
    for(in hi=1;hi<=10;hi++){
      double v=f(ai,hi);
      if(ab(v-x)<best){
	best=ab(v-x);
	ba=ai;
	bh=hi;
      }
    }
  }
  cout<<ba<<" "<<bh<<endl;
  return 0;
}