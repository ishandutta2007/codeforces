#include<cstdio>
#include<algorithm>
#include<cstring>
#include<bitset>
using namespace std;
struct Edge
{
	int from,to;
	int d;
}e[155];
int n,m,a[155][155];
bool cmp(Edge a,Edge b)
{
	return a.d<b.d;
}
struct Matrix
{
	bitset<155>a[155];
	bitset<155>&operator[](int i){return a[i];}
	Matrix(){memset(a,0,sizeof(a));}
	Matrix operator*(Matrix b)
	{
		Matrix ans;
		for(int i=1;i<=n;i++)
		  for(int k=1;k<=n;k++)
		    if(a[i][k]==1)
		      ans[i]|=b[k];
		return ans;
	}
	Matrix operator|(Matrix b)
	{
		Matrix ans;
		for(int i=1;i<=n;i++)
		  ans[i]=a[i]|b[i];
		return ans;
	}
}f,g[155],A[75],B[75];
Matrix quick_pow(Matrix x,int a)
{
	Matrix ans;
	for(int i=1;i<=n;i++)ans[i][i]=1;
	while(a)
	{
		if(a&1)ans=ans*x;
		x=x*x;
		a>>=1;
	}
	return ans;
}
Matrix quick_pow2(Matrix x,int a)
{
	Matrix ans;
	for(int i=1;i<=n;i++)ans[i][i]=1;
	while(a)
	{
		if(a&1)ans=ans|(ans*x);
		x=x|(x*x);
		a>>=1;
	}
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&e[i].from,&e[i].to,&e[i].d);
		a[e[i].from][e[i].to]=min(a[e[i].from][e[i].to],e[i].d);
	}
	sort(e+1,e+m+1,cmp);
	e[m+1].d=e[m].d+1000;
	for(int i=1;i<=n;i++)f[i][i]=1;
	int ans=0;
	for(int i=0;i<=m;i++)
	{
		if(i)g[i]=g[i-1];
		if(i)g[i][e[i].from][e[i].to]=1;
		Matrix xx=quick_pow2(g[i],e[i+1].d-e[i].d);
		Matrix ff=f*xx;
		if(ff[1][n])
		{
			A[0]=B[0]=g[i];
			int k;
			for(k=1;(1<<k)<=e[i+1].d-e[i].d;k++)
			  A[k]=A[k-1]*A[k-1],B[k]=B[k-1]|(B[k-1]*B[k-1]);
			k--;
			while(k>=0)
			{
				bool flag=1;
				for(int j=1;j<=n;j++)
				{
					if(f[1][j]&&B[k][j][n])
					{
						flag=0;
						break;
					}
				}
				if(flag)f=f*A[k],ans+=1<<k;
				k--;
			}
			printf("%d\n",ans+1);
			return 0;
		}
		else
		{
			f=f*quick_pow(g[i],e[i+1].d-e[i].d);
			ans+=e[i+1].d-e[i].d;
		}
	}
	printf("Impossible\n");
	return 0;
}