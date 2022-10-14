#include <bits/stdc++.h>

using namespace std;

int main() {
  double a,b;
  scanf("%lf%lf",&a,&b);
  int n;
  scanf("%i",&n);
  double sol=1000000;
  for(int i=0;i<n;i++){
    double x,y,v;
    scanf("%lf%lf%lf",&x,&y,&v);
    double dist=sqrt(abs(a-x)*abs(a-x)+abs(b-y)*abs(b-y));
    double time=dist/v;
    sol=min(time,sol);
  }
  printf("%.12lf",sol);
}