#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
#define int long long
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int a[100005],pos[100005],wz[100005];
map<int,int>le,ri,nl;
bool bi(int x,int y)
{
	return a[x]<a[y];
}
int f[305][305],n,m;
void insert(int l,int k,int x)
{
	while(k<=m)
	{
		f[l][k]+=x;
		k+=((k)&(-k));
	}
	return;
}
int query(int l,int k)
{
	int ans=0;
	while(k>=1)
	{
		ans+=f[l][k];
		k-=((k)&(-k));
	}
	return ans;
}
signed main()
{
	int t,ans=0;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		for(int i=1;i<=n*m;i++)
		{
			a[i]=read();
			pos[i]=i;
		}
		sort(pos+1,pos+n*m+1,bi);
		le.clear();
		ri.clear();
		nl.clear();
		for(int i=1;i<=n*m;i++)
		{
			if(a[pos[i]]!=a[pos[i-1]])
			{
				ri[a[pos[i-1]]]=i-1;
				//printf("%d %d\n",le[a[pos[i-1]]],ri[a[pos[i-1]]]);
				le[a[pos[i]]]=i;
			}
		}
		ri[a[pos[n*m]]]=n*m;
		for(int i=1;i<=n*m;i++)
		{
				if(nl[a[i]]==0)
				{
					if((le[a[i]]-1)/m==(ri[a[i]]-1)/m)
					{
						wz[i]=ri[a[i]];
						ri[a[i]]--;
						continue;
					}
					nl[a[i]]=((le[a[i]]-1)/m+1)*m;
					wz[i]=nl[a[i]];
				}
				else
				{
					if(nl[a[i]]==le[a[i]])
					{
						le[a[i]]=((le[a[i]]-1)/m+1)*m+1;
						nl[a[i]]=min(ri[a[i]],((le[a[i]]-1)/m+1)*m);
					}
					else nl[a[i]]--;
					wz[i]=nl[a[i]];
				}
		}
		//for(int i=1;i<=n*m;i++)printf("%d ",wz[i]);
		//printf("\n");
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)f[i][j]=0;
		ans=0;
		for(int i=1;i<=n*m;i++)
		{
			ans+=query((wz[i]-1)/m+1,(wz[i]-1)%m);
			insert((wz[i]-1)/m+1,(wz[i]-1)%m+1,1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}