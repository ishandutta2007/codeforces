#include <stdio.h>
const int N=55;
char ch[N][N];
int main()
{
int a,b,c,d,i,j;
scanf("%i %i %i %i",&a,&b,&c,&d);
for(i=1;i<=25;i++) for(j=1;j<=50;j++) ch[i][j]='A';
for(i=26;i<=50;i++) for(j=1;j<=50;j++) ch[i][j]='B';
a--;b--;
for(i=2;i<25;i+=2) for(j=2;j<=50;j+=2)
{
if(b) b--,ch[i][j]='B';
else if(c) c--,ch[i][j]='C';
}
for(i=27;i<50;i+=2) for(j=2;j<=50;j+=2)
{
if(a) a--,ch[i][j]='A';
else if(d) d--,ch[i][j]='D';
}
printf("50 50\n");
for(i=1;i<=50;i++) printf("%s\n",ch[i]+1);
return 0;
}