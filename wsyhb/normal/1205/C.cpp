#include<bits/stdc++.h>
using namespace std;
int n,cnt_queries;
inline int query(int a,int b,int c,int d)
{
	assert(1<=a&&a<=c&&c<=n);
	assert(1<=b&&b<=d&&d<=n);
	assert(a+b+2<=c+d);
	assert(++cnt_queries<=n*n);
	printf("? %d %d %d %d\n",a,b,c,d);
	fflush(stdout);
	int res;
	scanf("%d",&res);
	assert(res!=-1);
	return res;
}
const int max_n=49+5;
int id[max_n][max_n],ans[max_n][max_n];
const int max_tot=49*49+5;
int fa[max_tot],dis[max_tot];
int get_fa(int x)
{
	if(fa[x]!=x)
	{
		int rt=get_fa(fa[x]);
		dis[x]^=dis[fa[x]];
		fa[x]=rt;
	}
	return fa[x];
}
int x[max_tot],y[max_tot],p[max_n<<1];
int main()
{
	scanf("%d",&n);
	int tot=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			id[i][j]=++tot;
			x[tot]=i,y[tot]=j;
		}
	for(int i=1;i<=tot;++i)
		fa[i]=i,dis[i]=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			for(int d=0;d<=2;++d)
			{
				int x=i+d,y=j+(2-d);
				if(x<=n&&y<=n&&x+y!=n<<1)
				{
					int a=id[i][j];
					int b=id[x][y];
					int c=get_fa(a);
					int d=get_fa(b);
					if(c!=d)
					{
						if(c>d)
							swap(c,d);
						fa[d]=c;
						dis[d]=dis[a]^dis[b]^(query(i,j,x,y)^1);
					}
				}
			}
	ans[1][1]=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			if(i==n&&j==n)
				continue;
			int k=id[i][j],rt=get_fa(k);
			if((i+j)&1)
			{
				assert(rt==2);
				ans[i][j]=ans[1][2]^dis[k];
			}
			else
			{
				assert(rt==1);
				ans[i][j]=ans[1][1]^dis[k];
			}
		}
	assert(ans[1][1]==1);
	for(int i=1;i<=n;++i)
		p[i]=i;
	for(int i=n+1;i<=2*n-1;++i)
		p[i]=id[i-(n-1)][n];
	for(int i=1;i+3<=2*n-1;++i)
	{
		int c[4];
		for(int j=0;j<=3;++j)
			c[j]=ans[x[p[i+j]]][y[p[i+j]]];
		if((c[0]^c[1]^c[2]^c[3])==0)
		{
			int res=query(x[p[i]],y[p[i]],x[p[i+3]],y[p[i+3]])^1;
			if(c[0]^c[3]^res)
			{
				for(int a=1;a<=n;++a)
					for(int b=1;b<=n;++b)
					{
						if((a+b)&1)
							ans[a][b]^=1;
					}
			}
			assert(cnt_queries==n*n-2);
			puts("!");
			for(int a=1;a<=n;++a)
			{ 
				for(int b=1;b<=n;++b)
					putchar(ans[a][b]^'0');
				putchar('\n');
			}
			fflush(stdout);
			return 0;
		}
	}
	assert(false);
	return 0;
}