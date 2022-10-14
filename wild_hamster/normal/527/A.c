#include <stdio.h>
long long h,x,y,w,l,wl,wr,hl,hr,r,i,j,n,k,k1,k2,d,m,q,max1,a[200500],b[200500],rez;
void gcd(long long a, long long b)
{
 if (a%b == 0)
 {
  rez += a/b;
  return;
 }
 rez += a/b;
 gcd(b,a%b);
}
int main()
{
    scanf("%I64d%I64d",&n,&m);
    gcd(n,m);
    printf("%I64d\n",rez);
    return 0;
}