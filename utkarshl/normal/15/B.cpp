//TA lab, how many grids will melt?
#include"stdio.h"
#include"iostream"
long long mod(int a)
{
  if(a<=0) return -a;
  return a;
}
int main()
{
  int T;
  scanf("%d",&T);
  while(T--)
  {
    int n,m,x1,x2,y1,y2;
    scanf("%d%d%d%d%d%d",&n,&m,&x1,&y1,&x2,&y2);
    long long a=(x1>x2)?x1-x2:x2-x1;
    long long b=(y1>y2)?y1-y2:y2-y1,c=0;
    if((n<(a<<1))||(m<(b<<1)))
    c=(2*a-n)*(2*b-m);
    std::cout<<(2*a*b-c)<<"\n";
  }
}