#include<bits/stdc++.h>
using namespace std;
const int N=100005,inf=1e9;
int n,m,a[N],b[N],l[N],p[N],f[N],g[N],v[N],ans[N];
void sol(int i,int k,int &x){int s=lower_bound(b+1,b+m+1,k)-b-1;v[s]=1;x=ans[i]=b[s];}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),f[i]=inf;
	n++,a[n]=f[n]=inf;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	sort(b+1,b+m+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i]==-1)
		{
			for(int j=n,s=m;s;s--)
			{
				while(f[j]>=b[s])
					j--;
				f[j+1]=b[s],g[j+1]=i;
			}
		}
		else
		{
			int j=lower_bound(f+1,f+n+1,a[i])-f-1;
			l[i]=j+1,p[i]=g[j],f[j+1]=a[i],g[j+1]=i;
		}
	}
	int i=l[n],j=n,x=a[n];
	while(i--)
	{
		if(a[j]==-1)
		{
			int fl=0;
			for(int s=j-1;s;s--)
			{
				if(a[s]!=-1&&l[s]==i&&a[s]<x)
				{
					x=a[j=s];
					fl=1;
					break;
				}
			}
			if(!fl)
			{
				for(int s=j-1;s;s--)
				{
					if(a[s]==-1)
					{
						sol(s,x,x);
						j=s;
						break;
					}
				}
			}
		}
		else
		{
			if(a[p[j]]==-1)
				sol(p[j],a[j],x);
			else
				x=a[p[j]];
			j=p[j];
		}
	}
	for(int i=1,j=1;i<=n;i++)
	{
		if(a[i]==-1)
		{
			if(ans[i])
				continue;
			while(v[j])
				j++;
			v[j]=1,ans[i]=b[j];
		}
		else
			ans[i]=a[i];
	}
	for(int i=1;i<n;i++)
		printf("%d ",ans[i]);
	return 0;
}