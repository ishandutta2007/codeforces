#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,k;
  scanf("%i%i",&n,&k);
  double x[n],y[n];
  for(int i=0;i<n;i++)scanf("%lf%lf",&x[i],&y[i]);
  double sol=0;
  for(int i=1;i<n;i++){
    double dist=sqrt(abs(x[i]-x[i-1])*abs(x[i]-x[i-1])+abs(y[i]-y[i-1])*abs(y[i]-y[i-1]));
    sol+=dist;
  }
  sol/=50;sol*=k;
  printf("%.12lf",sol);
}