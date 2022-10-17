#include<stdio.h>
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int n,m,z;
char s[20][20];
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(s[i][j]=='W')
				for(int k=0;k<4;k++)
					if(s[i+dx[k]][j+dy[k]]=='P')
					{
						z++;
						break;
					}
	printf("%d",z);
}