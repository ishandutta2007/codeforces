#include <stdio.h>
int main()
{
 int n,a,cnt,k,i,mass;
 mass=0;
 cnt=0;
 scanf("%i%i",&n,&k);
 for(i=0;i<k;i++)
 {
  scanf("%i",&a);
  if(a%2==1)
  {
   a++;
   cnt++;
  }
  mass+=a;
 }
 if(mass<8*n) printf("YES");
 else if(mass>8*n) printf("NO");
 else
 {
  if(k==4*n && cnt<n) printf("NO");
  else printf("YES");
 }
 return 0;
}