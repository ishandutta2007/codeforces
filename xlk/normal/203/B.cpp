#include<stdio.h>
int s[1020][1020],n,m,x,y;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&x,&y);
		for(int j=x-1;j<=x+1;j++)
			for(int k=y-1;k<=y+1;k++)
			{
				s[j][k]++;
				if(s[j][k]==9)
					return printf("%d",i+1),0;
			}
	}
	return puts("-1"),0;
}