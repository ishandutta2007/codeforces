#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#define ll long long
using namespace std;
const ll MOD=998244353;
int n,m,a[500005],b[500005],pos[500005];
map<int,int>mp;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),mp[a[i]]=i;
	for(int i=1;i<=m;i++)scanf("%d",&b[i]),pos[i]=mp[b[i]];
	for(int i=1;i<=m;i++)
	{
		if(!pos[i]||pos[i]<pos[i-1])
		{
			printf("0\n");
			return 0;
		}
	}
	for(int i=1;i<pos[1];i++)
	{
		if(a[i]<b[1])
		{
			printf("0\n");
			return 0;
		}
	}
	pos[m+1]=n+1;
	for(int i=1;i<=m;i++)
	for(int j=pos[i]+1;j<pos[i+1];j++)
	{
		if(a[j]<b[i])
		{
			printf("0\n");
			return 0;
		}
	}
	ll ans=1;
	for(int i=2;i<=m;i++)
	{
		int cnt=1;
		for(int j=pos[i]-1;j>pos[i-1];j--)
		{
			if(a[j]>=b[i])cnt++;
			else break;
		}
		ans=ans*cnt%MOD;
	}
	printf("%lld\n",ans);
	return 0;
}