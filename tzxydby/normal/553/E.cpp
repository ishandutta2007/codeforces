#include<bits/stdc++.h>
using namespace std;
const int N=105,M=200005;
const double pi=acos(-1);
struct cp
{
	double x,y;
	cp operator+(cp k){return {x+k.x,y+k.y};}
	cp operator-(cp k){return {x-k.x,y-k.y};}
	cp operator*(cp k){return {x*k.x-y*k.y,x*k.y+y*k.x};}
};
struct mul
{
	int n,m,k,l,r[M];
	cp a[M],b[M];
	void fft(cp *a,int n,int x)
	{
		for(int i=0;i<n;i++)
			if(i<r[i])
				swap(a[i],a[r[i]]);
		for(int h=2,k=1;h<=n;h<<=1,k<<=1)
		{
			cp wn={cos(pi/k),x*sin(pi/k)};
			for(int i=0;i<n;i+=h)
			{
				cp w={1,0};
				for(int j=0;j<k;j++,w=w*wn)
				{
					cp x=a[i+j],y=w*a[i+j+k];
					a[i+j]=x+y,a[i+j+k]=x-y;
				}
			}
		}
	}
	void sol()
	{
		k=1,l=0;
		while(k<=n+m)
			k<<=1,l++;
		for(int i=0;i<k;i++)
			r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
		for(int i=n+1;i<k;i++)
			a[i]={0,0};
		for(int i=m+1;i<k;i++)
			b[i]={0,0};
		fft(a,k,1);
		fft(b,k,1);
		for(int i=0;i<k;i++)
			a[i]=a[i]*b[i];
		fft(a,k,-1);
		for(int i=0;i<=n+m;i++)
			a[i].x/=k;
	}
}z;
int n,m,t,x,a[N],b[N];
double d[N][N],c[N],p[N][M],f[N][M],g[N][M];
void cdq(int l,int r)
{
	if(l==t)
		return;
	if(l==r)
	{
		for(int i=1;i<n;i++)
			f[i][l]=1e18;
		for(int i=1;i<=m;i++)
			if(a[i]!=n)
				f[a[i]][l]=min(f[a[i]][l],g[i][l]+c[i]);
		return;
	}
	int mid=l+r>>1;
	cdq(mid+1,r);
	z.n=r-l+1,z.m=r-mid+1;
	for(int i=1;i<=m;i++)
	{
		if(a[i]!=n)
		{
			for(int j=0;j<=z.n;j++)
				z.a[j]={p[i][j+1],0};
			for(int j=0;j<=z.m;j++)
				z.b[j]={f[b[i]][r-j],0};
			z.sol();
			for(int j=l;j<=mid;j++)
				g[i][j]+=z.a[r-j-1].x;
		}
	}
	cdq(l,mid);
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&t,&x);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)
				d[i][j]=1e18;
	for(int i=1;i<=m;i++)
	{
		int x;
		scanf("%d%d%d",&a[i],&b[i],&x);
		c[i]=d[a[i]][b[i]]=x;
		for(int j=1;j<=t;j++)
		{
			scanf("%lf",&p[i][j]);
			p[i][j]/=100000;
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	for(int i=0;i<2*t;i++)
		f[n][i]=(i<=t?0:x);
	for(int i=1;i<n;i++)
		for(int j=t;j<2*t;j++)
			f[i][j]=d[i][n]+x;
	cdq(0,2*t-1);
	printf("%.10lf\n",f[1][0]);
	return 0;
}