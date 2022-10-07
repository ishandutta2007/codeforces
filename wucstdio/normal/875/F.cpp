#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
struct Princess
{
	int prince1;
	int prince2;
	ll dowry;
}a[200005];
int n,m,pa[200005];
ll ans;
bool pos[200005];
bool cmp(Princess a,Princess b)
{
	return a.dowry>b.dowry;
}
int find(int x)
{
	return x==pa[x]?x:pa[x]=find(pa[x]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  pa[i]=i,pos[i]=1;
	for(int i=1;i<=m;i++)
	  scanf("%d%d%I64d",&a[i].prince1,&a[i].prince2,&a[i].dowry);
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int x=a[i].prince1,y=a[i].prince2;
		x=find(x),y=find(y);
		if(x!=y)
		{
			if(pos[x]&&pos[y])
			{
				pa[x]=y;
				ans+=a[i].dowry;
			}
			else if(pos[x]||pos[y])
			{
				pa[x]=y;
				pos[y]=0;
				ans+=a[i].dowry;
			}
		}
		else
		{
			if(pos[x])
			{
				ans+=a[i].dowry;
				pos[x]=0;
			}
		}
	}
	printf("%I64d\n",ans);
	return 0;
}