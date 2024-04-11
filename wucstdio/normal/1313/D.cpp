#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
struct Data
{
	int val;
	int id;
	bool lorr;
}a[200005];
int n,m,k,l[100005],r[100005],sa[100005],num[200005];
int last[10],pos[10][200005],f[1<<8],s[1<<8];
bool cmp2(int i,int j)
{
	return l[i]<l[j]||(l[i]==l[j]&&r[i]<r[j]);
}
bool cmp(Data a,Data b)
{
	return a.val<b.val;
}
int calc(int x)
{
	int ans=0;
	while(x)
	{
		if(x&1)ans^=1;
		x>>=1;
	}
	return ans;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&l[i],&r[i]);
		a[2*i-1].val=l[i];
		a[2*i-1].id=i;
		a[2*i-1].lorr=0;
		a[2*i].val=r[i]+1;
		a[2*i].id=i;
		a[2*i].lorr=1;
	}
	sort(a+1,a+2*n+1,cmp);
	int now=0;
	for(int i=1;i<=2*n;i++)
	{
		if(a[i].val!=a[i-1].val)
		{
			num[now]=a[i].val-a[i-1].val;
			now++;
		}
		if(a[i].lorr==0)l[a[i].id]=now;
		else r[a[i].id]=now-1;
	}
	for(int i=1;i<=n;i++)sa[i]=i;
	sort(sa+1,sa+n+1,cmp2);
	for(int t=1;t<=n;t++)
	{
		int i=sa[t];
		int now=0;
		for(int j=0;j<k;j++)
		{
			if(l[i]>last[j])
			{
				now=j;
				break;
			}
		}
		for(int j=l[i];j<=r[i];j++)pos[now][j]=i;
		last[now]=r[i];
	}
	n=0;
	for(int i=0;i<k;i++)n=max(n,last[i]);
	for(int i=1;i<=n;i++)
	{
		for(int x=0;x<(1<<k);x++)
		{
			bool flag=1;
			for(int j=0;j<k;j++)
			{
				if(pos[j][i]==0&&((1<<j)&x))
				{
					flag=0;
					break;
				}
			}
			if(flag)f[x]=s[x]+calc(x)*num[i];
			else f[x]=0;
		}
		for(int x=0;x<(1<<k);x++)s[x]=f[x];
		for(int j=0;j<k;j++)
		{
			if(pos[j][i]!=pos[j][i+1])
			{
				for(int x=0;x<(1<<k);x++)
				{
					s[x^(1<<j)]=s[x]=max(s[x],s[x^(1<<j)]);
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<(1<<k);i++)ans=max(ans,f[i]);
	printf("%d\n",ans);
	return 0;
}