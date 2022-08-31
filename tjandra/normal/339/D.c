#include<stdio.h>
typedef unsigned u;
u map[18][131072];
int main()
{
	u m,n,p,q=0,i,j,k=1;
	for(scanf("%u%u",&m,&n),p=1u<<m;q<p;q++)scanf("%u",&map[m][q]);
	for(q=0,i=m;i--;q=0,k^=1)
	{
		for(p=1u<<i;q<p;q++)
		{
			if(k)map[i][q]=map[i+1][q<<1]|map[i+1][(q<<1)+1];
			else map[i][q]=map[i+1][q<<1]^map[i+1][(q<<1)+1];
		}
	}
	while(n--)
	{
		scanf("%u%u",&i,&j);
		map[m][--i]=j;j=i;
		for(k=1,i=m;i--;j>>=1,k^=1)
		{
			if(k)map[i][j>>1]=map[i+1][j]|map[i+1][j+1-((j&1)<<1)];
			else map[i][j>>1]=map[i+1][j]^map[i+1][j+1-((j&1)<<1)];
		}
		printf("%u\n",map[0][0]);
	}
	return 0;
}