#include<bits/stdc++.h>
using namespace std;
const int N=505,M=105;
const double eps=1e-12;
int n,m,k,t,a[N],d[N],w[N];
vector<int>e[N],p;
double f[N][N],g[N][N],ans;
namespace guass
{
	int z[N];
	double x[N][N],c[N][N];
	void main()
	{
		for(int i=1;i<=n;i++)
		{
			if(!a[i])
			{
				for(auto j:e[i])
					x[i][j]+=1.0/w[i];
				x[i][i]=-1;
			}
			else
			{
				x[i][i]=1;
				c[i][i]=1;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int p=1;p<=n;p++)
			{
				if(abs(x[i][p])>eps)
				{
					z[i]=p;
					break;
				}
			}
			double k=x[i][z[i]];
			for(int p=1;p<=n;p++)
				x[i][p]/=k,c[i][p]/=k;
			for(int j=1;j<=n;j++)
			{
				if(i==j)
					continue;
				if(abs(x[j][z[i]])>eps)
				{
					double k=-x[j][z[i]];
					for(int p=1;p<=n;p++)
						x[j][p]+=k*x[i][p],c[j][p]+=k*c[i][p];
				}
			}
		}
		for(int i=1;i<=n;i++)
			if(a[i])
				for(int j=1;j<=n;j++)
					f[z[j]][i]=c[j][i];
	}
}
struct mat{double v[M][M];}v;
mat operator*(mat a,mat b)
{
	mat c;
	for(int i=1;i<=t;i++)
	{
		for(int j=1;j<=t;j++)
		{
			c.v[i][j]=0;
			for(int k=1;k<=t;k++)
				c.v[i][j]+=a.v[i][k]*b.v[k][j];
		}
	}
	return c;
}
mat qp(mat a,int b)
{
	mat ans=a;
	b--;
	while(b)
	{
		if(b&1)
			ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	p.push_back(0);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i])
		{
			d[i]=p.size();
			p.push_back(i);
		}
	}
	t=p.size()-1;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
		w[u]++;
		w[v]++;
	}
	guass::main();
	for(int i=1;i<=n;i++)
	{
		if(!a[i])
		{
			for(int j=1;j<=n;j++)
				g[i][j]=f[i][j];
		}
		else
		{
			for(int j=1;j<=n;j++)
			{
				for(auto v:e[i])
					g[i][j]+=f[v][j]/w[i];
			}
		}
	}
	if(k==2)
		printf("%.6lf\n",g[1][n]);
	else
	{
		for(int i=1;i<=t;i++)
			for(int j=1;j<=t;j++)
				v.v[i][j]=g[p[i]][p[j]];
		v=qp(v,k-2);
		for(int i=1;i<=t;i++)
			ans+=g[1][p[i]]*v.v[i][t];
		printf("%.6lf\n",ans);
	}
	return 0;
}