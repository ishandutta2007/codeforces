#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<math.h>
#include<iomanip>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef pair<int,int> pint;
typedef long long ll;
const int inf   = 1<<30;
const int mod=1000000007;

  
int main(){
  double r,x,y,xx,yy;
  cin>>r>>x>>y>>xx>>yy;
  double dist=(xx-x)*(xx-x)+(yy-y)*(yy-y);
  dist=sqrt(dist);
  if(dist>=r){cout<<setprecision(10)<<x<<" "<<y<<" "<<r;return 0;}
  double ar=(dist+r)/2;
  double ax,ay;
  if(dist!=0)ax=xx+(x-xx)*ar/dist,ay=yy+(y-yy)*ar/dist;
  else ax=xx+ar,ay=yy;
  cout<<setprecision(10)<<ax<<" "<<ay<<" "<<ar<<endl;
  return 0;
  }