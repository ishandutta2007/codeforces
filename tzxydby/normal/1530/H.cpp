#include<bits/stdc++.h>
using namespace std;
const int N=20005,inf=1e9;
int n,a[N],f[N],g[N],tf[N],tg[N],b1[N],b2[N],s;
void add1(int x,int v)
{
	for(int i=x;i;i-=i&(-i))
		b1[i]=min(b1[i],v);
}
int ask1(int x)
{
	int v=inf;
	for(int i=x;i<=n+1;i+=i&(-i))
		v=min(v,b1[i]);
	return v;
}
void add2(int x,int v)
{
	for(int i=x;i<=n+1;i+=i&(-i))
		b2[i]=max(b2[i],v);
}
int ask2(int x)
{
	int v=0;
	for(int i=x;i;i-=i&(-i))
		v=max(v,b2[i]);
	return v;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		s=1;
		for(int z=0;z<2;z++)
		{
			for(int i=0;i<=n+2;i++)
				tf[i]=inf,tg[i]=0;
			if(z)
			{
				for(int i=n-1;i>=1;i--)
					tf[i]=tg[i]=a[i];
			}
			else
				tf[n]=tg[n]=a[n];
			for(int j=z+2;;j++)
			{
				for(int i=0;i<=n+2;i++)
				{
					f[i]=b1[i]=inf;
					g[i]=b2[i]=0;
				}
				add1(a[n],tf[n]);
				add2(a[n],tg[n]);
				for(int i=n-1;i>=1;i--)
				{
					if(i+j-1<=n)
					{
						if(tg[i+j-1])
							add1(tg[i+j-1],a[i+j-1]);
						if(tf[i+j-1]<inf)
							add2(tf[i+j-1],a[i+j-1]);
					}
					f[i]=ask1(a[i]+1),g[i]=ask2(a[i]-1);
					add1(a[i],tf[i]);
					add2(a[i],tg[i]);
				}
				int b=0;
				for(int i=1;i<=n;i++)
					if(f[i]<inf||g[i]>0)
						b=1;
				if(!b)
					break;
				s=max(s,j-z);
				for(int i=0;i<=n+2;i++)
					tf[i]=f[i],tg[i]=g[i];
			}
		}
		printf("%d\n",s);
	}
	return 0;
}