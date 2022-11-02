#include<iostream>
#include<iomanip>
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
bool isp(double v1, double v2, in cp, double t){
  //x*v2+(t-x)*v1=1
  //x*(v2-v1)+t*v1=1
  //x=(1-t*v1)/(v2-v1)
  double x=(1-t*v1)/(v2-v1);
  if(x>t)
    return 0;
  double ls=0;
  double tm;
  forn(z,cp){
    double l2=ls+x*v2;
    if(l2>1)
      return 0;
    ls+=x*v1;
    tm=(l2-ls)/(v1+v2);
    ls+=tm*v1;
  }
  return 1;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,k;
  double l,v1,v2;
  cin>>n>>l>>v1>>v2>>k;
  in cp=(n+k-1)/k;
  v1/=l;
  v2/=l;
  double mn=1/v1;
  double mx=1/v2;
  double md;
  forn(z,80){
    md=(mn+mx)/2;
    if(isp(v1,v2,cp,md))
      mn=md;
    else
      mx=md;
  }
  cout<<setprecision(15)<<mn<<endl;
  return 0;
}