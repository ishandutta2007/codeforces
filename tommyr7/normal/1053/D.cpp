#include <bits/stdc++.h>
#define Maxn 2000007
#define modp 1000000007
using namespace std;
typedef long long ll;
int m=2000000,ans,flag;
bool mark[Maxn];
int cnt[Maxn],vis[Maxn];
void work()
{
	ans=1;
	for (int p=2;p<=m;p++)
	{
		if (!mark[p])
		{
			int mx=1,flagg=0;
			for (int j=p;j<=m;j+=p)
			{
				mark[j]=1;
				if (vis[j])
				{
					int t=vis[j],c=1;
					while (t%p==0) t/=p,c*=p;
					if (mx==c) flagg=1; else if (mx<c) {mx=c,flagg=0;}
				}
			}
			for (int j=p;j<=m;j+=p)
			{
				if (vis[j]&&(flagg||vis[j]%mx!=0))
				{
					while (vis[j]%p==0) vis[j]/=p;
				}
			}
			ans=(1LL*ans*mx)%modp;
		}
	}
	for (int i=1;i<=m;i++)
		if (vis[i]==1)
		{
			flag=1;
			return;
		}
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		++cnt[x];
	}
	for (int i=m;i>=2;i--)
	{
		if (cnt[i]==0) continue;
		bool mark=1;
		for (int j=i+i;j<=m;j+=i)
		{
			if (vis[j])
			{
				mark=0;
				break;
			}
		}
		if (mark)
		{
			vis[i]=i;
			--cnt[i];
		}
		if (cnt[i]>0)
		{
			vis[i-1]=i-1;
			--cnt[i];
		}
		if (cnt[i]>0) flag=1;
	}
	work();
	ans=(ans+flag)%modp;
	printf("%d\n",ans);
	return 0;
}