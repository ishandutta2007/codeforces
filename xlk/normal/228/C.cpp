#include<stdio.h>
int dx[]={0,0,1,1};
int dy[]={0,1,0,1};
int n,m,z;
char s[505][505];
char f[505][505][16][16];
int F(int x,int y,int z,int w)
{
	if(z==0)
	{
		if(w!=15)
			return s[x][y]=='.';
		else
			return s[x][y]=='*';
	}
	char &t=f[x][y][z][w];
	if(t)
		return t;
	for(int i=0;i<4;i++)
		if(w>>i&1)
		{
			if(~F(x+(dx[i]<<z-1),y+(dy[i]<<z-1),z-1,15)&1)
				return t=2;
		}
		else
		{
			if(~F(x+(dx[i]<<z-1),y+(dy[i]<<z-1),z-1,w)&1)
				return t=2;
		}
	return t=1;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",s[i]);
	for(int k=2;1<<k<=n&&1<<k<=m;k++)
		for(int i=0;i<=n-(1<<k);i++)
			for(int j=0;j<=m-(1<<k);j++)
				for(int l=0;l<16;l++)
					if(F(i,j,k,l)&1)
						z++;
	printf("%d",z);
	return 0;
}