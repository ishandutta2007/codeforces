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
double sq(double a){
  return a*a;
}
double dof(double xa, double ya, double xb, double yb){
  return sqrt(sq(xa-xb)+sq(ya-yb));
}
double dt(double xa, double ya, double xb, double yb, double x, double y){
  double spr=(xb-xa)*(x-xa)+(yb-ya)*(y-ya);
  double dln=dof(xa,ya,xb,yb);
  spr/=dln;
  double px=xa+spr*(xb-xa)/dln;
  double py=ya+spr*(yb-ya)/dln;
  return dof(px,py,x,y);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  double ans=1e18;
  cin>>n;
  VI x(n);
  VI y(n);
  forn(i,n)
    cin>>x[i]>>y[i];
  forn(i,n){
    ans=min(ans,dt(x[i],y[i],x[(i+2)%n],y[(i+2)%n],x[(i+1)%n],y[(i+1)%n]));
  }
  ans/=2;
  cout<<setprecision(15);
  cout<<ans<<endl;
  return 0;
}