#include<iostream>
#include<cmath>
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
const double PI=3.14159265358979323;
double cx,cy,tar;
vector<double> x,y;
double cpr(double a, double b, double c, double d){
  return a*d-b*c;
}
double ab(double a){
  return a<0?-a:a;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  VI lt(6);
  forv(i,lt)
    cin>>lt[i];
  cx=cy=0;
  tar=0;
  double cag=0;
  forv(i,lt){
    x.PB(cx);
    y.PB(cy);
    cx+=cos(cag)*lt[i];
    cy+=sin(cag)*lt[i];
    cag+=60.0/180.0*PI;
  }
  forv(i,lt){
    tar+=cpr(x[i],y[i],x[(i+1)%6],y[(i+1)%6]);
  }
  tar/=(sqrt(3)/2);
  in ans=tar+0.5;
  assert(ab(tar-ans)<0.01);
  cout<<ans<<endl;
  return 0;
}