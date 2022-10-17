#include<stdio.h>
#include<string.h>
#include<bitset>
using namespace std;
bitset<20020>a[10020];
int x[20020],y[20020],f[20020],g[20020],n,m,p,l;
char z[40020];
void wk(int t)
{
	for(int i=1;i<=n;i++)
	{
		memset(g,0,sizeof g);
		if(n-i<10010)
			a[n-i].reset();
		for(int j=1;j<=m;j++)
		{
			g[j]=g[j-1];
			if(j<2||f[j]>g[j])
			{
				g[j]=f[j];
				if(n-i<10010)
					a[n-i][j]=1;
			}
			g[j]+=(x[i]+y[j])%p;
		}
		memcpy(f,g,sizeof f);
	}
	if(t)
		printf("%d\n",f[m]);
	int i=0; 
	while(i<10010&&i<n&&n-i+m>1&&m)
		if(a[i][m])
			i++,z[--l]='C';
		else
			m--,z[--l]='S';
	n-=i;
	memset(f,0,sizeof f);
}
int main()
{
	scanf("%d%d%d",&n,&m,&p),l=n+m-2;
	for(int i=1;i<=n;i++)
		scanf("%d",x+i);
	for(int i=1;i<=m;i++)
		scanf("%d",y+i);
	wk(1),wk(0);
	puts(z);
	return 0;
}