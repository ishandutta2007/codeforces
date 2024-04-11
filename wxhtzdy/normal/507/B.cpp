#include <bits/stdc++.h>
using namespace std;
int main() {
  double r,x,y,x1,y1;
  scanf("%lf%lf%lf%lf%lf",&r,&x,&y,&x1,&y1);
  r*=2;
  double dist=ceil(sqrt(abs(x-x1)*abs(x-x1)+abs(y-y1)*abs(y-y1)));
  int ans=(dist+r-1)/r;
  ans=max(ans,0);
  printf("%i",ans);
}