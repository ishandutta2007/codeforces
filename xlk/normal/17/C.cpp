#include<stdio.h>
int n,m,f[153][53][53][53],v[151][3],z,p=51123987,u;
char s[160];
void inc(int &x,int y)
{
	x=(x+y)%p;
}
int K(int x,int y)
{
	return x-y<2&&y-x<2;
}
int main()
{
	scanf("%d%s",&n,s+1);
	for(int i=n;i;i--)
		v[i][0]=v[i+1][0],v[i][1]=v[i+1][1],v[i][2]=v[i+1][2],v[i][s[i]-'a']=i;
	f[1][0][0][0]=1;
	m=n/3+2;
	for(int i=1;i<=n;i++)
		for(int j=0;j<m;j++)
			for(int k=0;k<m;k++)
				for(int l=0;l<m;l++)
					if(u=f[i][j][k][l])
					{
						if(j+k+l==n&&K(j,k)&&K(k,l)&&K(l,j))
							inc(z,u);
						inc(f[v[i][0]][j+1][k][l],u);
						inc(f[v[i][1]][j][k+1][l],u);
						inc(f[v[i][2]][j][k][l+1],u);
					}
	printf("%d",z);
}