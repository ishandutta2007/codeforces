#include <stdio.h>
int main()
{
int k,i,j,c;
scanf("%i",&k);
for(i=0;i<26;i++)
{
c=1;
while(c*(c+1)/2<=k) c++;
k-=c*(c-1)/2;
for(j=0;j<c;j++) printf("%c",'a'+i);
}
return 0;
}