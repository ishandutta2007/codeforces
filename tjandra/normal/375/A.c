#include<stdio.h>
typedef unsigned u;
u d[10],p[7]={1869,6198,1896,1689,1986,1968,1698},m,i;
int main()
{
	char c;
	while((c=getchar())>0)if(c>='0')d[c-'0']++;
	d[1]--;d[8]--;d[6]--;d[9]--;
	for(i=10;--i;)while(d[i]--){m=(m*3+i)%7;putchar('0'+i);}
	printf("%u",p[m]);
	while(d[0]--)putchar('0');
	putchar('\n');
	return 0;
}