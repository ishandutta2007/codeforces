#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int k,n,m,sa[100005],t[100005],id[100005],b[100005];
ll a[100005],v[100005];
bool flag[100005],c[100005];
bool cmp1(int x,int y)
{
	if(id[x]!=id[y])return id[x]<id[y];
	if(t[x]!=t[y])return t[x]<t[y];
	return b[x]>b[y];
}
bool cmp2(int x,int y)
{
	if(v[x]==-1)return 0;
	if(v[y]==-1)return 1;
	return b[x]*v[y]>b[y]*v[x];
}
int main()
{
	scanf("%d%d%d",&k,&n,&m);
	for(int i=1;i<=k;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&t[i],&id[i],&b[i]);
		sa[i]=i;
	}
	sort(sa+1,sa+n+1,cmp1);
	for(int ii=1;ii<=n;ii++)
	{
		int i=sa[ii];
		if(t[i]==1)
		{
			if(b[i]>a[id[i]]&&!flag[id[i]])
			{
				b[i]-=(int)a[id[i]];
				c[i]=1;
				t[i]=2;
				flag[id[i]]=1;
			}
		}
	}
	sort(sa+1,sa+n+1,cmp1);
	memset(flag,0,sizeof(flag));
	for(int ii=1;ii<=n;ii++)
	{
		int i=sa[ii];
		if(t[i]==1)v[i]=-1;
		if(t[i]==2)
		{
			v[i]=a[id[i]];
			a[id[i]]+=b[i];
		}
		if(t[i]==3)v[i]=1,b[i]--;
	}
	sort(sa+1,sa+n+1,cmp2);
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		if(v[sa[i]]!=-1)
		{
			flag[sa[i]]=1;
			ans++;
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
	  if(c[i])t[i]=1;
	sort(sa+1,sa+n+1,cmp1);
	for(int i=1;i<=n;i++)
	{
		if(flag[sa[i]])
		  printf("%d ",sa[i]);
	}
	printf("\n");
	return 0;
}