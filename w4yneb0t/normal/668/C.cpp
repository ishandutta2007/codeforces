#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<iomanip>
#include<queue>
#include<cassert>
#include<cmath>
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

double ab(double a){
  return a<0?-a:a;
}
vector<double> sola,solb,x,y;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  scanf("%d",&n);
  sola.resize(n);
  solb.resize(n);
  x.resize(n);
  y.resize(n);
  forn(i,n)
    scanf("%lf",&(x[i]));
  forn(i,n)
    scanf("%lf",&(y[i]));
  double pva=0;
  double pvb=0;
  double tb,tc;
  double cd1,cd2,fl1,fl2,b1,b2;
  forn(i,n){
    tb=pva-pvb-x[i]-y[i];
    tc=x[i]-x[i]*pva-y[i]*pva;
    cd1=(-tb+sqrt(max(0.0,tb*tb-4*tc)))/2.0;
    cd2=(-tb-sqrt(max(0.0,tb*tb-4*tc)))/2.0;
    fl1=max(-cd1,cd1-1);
    fl2=max(-cd2,cd2-1);
    b1=x[i]+y[i]-cd1;
    b2=x[i]+y[i]-cd2;
    fl1=max(fl1,-b1);
    fl1=max(fl1,b1-1);
    fl2=max(fl2,-b2);
    fl2=max(fl2,b2-1);
    if(fl1>fl2)
      sola[i]=cd2;
    else
      sola[i]=cd1;
    solb[i]=x[i]+y[i]-sola[i];
    if(sola[i]<0)
      sola[i]=0;
    if(solb[i]<0)
      solb[i]=0;
    pva+=sola[i];
    pvb+=solb[i];
  }
  forn(i,n)
    printf("%.15lf ",sola[i]);
  printf("\n");
  forn(i,n)
    printf("%.15lf ",solb[i]);
  printf("\n");
  return 0;
}