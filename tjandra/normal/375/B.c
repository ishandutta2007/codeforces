#include<stdio.h>
typedef unsigned u;
u M[5005][5005],X[5005];
int main()
{
	char c;
	u x,y,i,j,n,ans;
	scanf("%u%u",&x,&y);
	for(i=0;i<x;i++)for(n=j=0;j<y;j++)
	{
		while((c=getchar())<'0');
		if(c=='1')
		{
			n++;
			if(n>X[j])X[j]=n;
			M[j][n]++;
		}
		else n=0;
	}
	ans=0;
	for(j=y;j--;)
	{
		for(i=X[j]+1;--i;)
		{
			M[j][i]+=M[j][i+1];
			if(ans<i*M[j][i])ans=i*M[j][i];
		}
	}
	printf("%u\n",ans);
	return 0;
}