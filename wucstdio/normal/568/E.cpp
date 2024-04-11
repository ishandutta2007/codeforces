#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,k,m,a[100005],b[100005],f[100005],g[100005],from[100005],pos[100005];
bool flag[100005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	  scanf("%d",&b[i]);
	sort(b+1,b+m+1);
	memset(g,0x3f,sizeof(g));
	g[0]=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=-1)
		{
			int l=0,r=i-1;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				if(g[mid]<a[i])l=mid+1;
				else r=mid-1;
			}
			f[i]=r+1;
			from[i]=pos[r];
			if(g[f[i]]>a[i])
			{
				g[f[i]]=a[i];
				pos[f[i]]=i;
			}
		}
		else
		{
			int now=i-1;
			for(int j=m;j>=1;j--)
			{
				while(g[now]>=b[j])now--;
				f[i]=max(f[i],now+1);
				if(f[i]==now+1)from[i]=pos[now];
				if(g[now+1]>b[j])
				{
					g[now+1]=b[j];
					pos[now+1]=i;
				}
			}
		}
	}
	int p=0;
	for(int i=1;i<=n;i++)
	  if(f[i]>f[p])
		p=i;
	int last=1000000000;
	int now=m,len=f[p];
	while(p)
	{
		len--;
		if(a[p]==-1)
		{
			while(b[now]>=last)now--;
			a[p]=b[now];
			last=a[p];
			flag[now]=1;
			int pre=p;
			for(int i=p-1;i>=1;i--)
			{
				if(a[i]!=-1&&a[i]<a[p]&&f[i]==len)
				{
					p=i;
					break;
				}
			}
			if(p==pre)
			{
				for(int i=p-1;i>=1;i--)
				{
					if(a[i]==-1)
					{
						p=i;
						break;
					}
				}
			}
		}
		else
		{
			last=a[p];
			p=from[p];
		}
	}
	now=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==-1)
		{
			while(flag[now])now++;
			a[i]=b[now];
			flag[now]=1;
		}
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}