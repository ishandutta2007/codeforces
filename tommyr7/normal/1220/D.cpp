#include <bits/stdc++.h>
#define Maxn 200007
using namespace std;
int n;
long long val[Maxn];
vector<long long> res[71];
map<long long,bool> vis;
long long a[Maxn];
int cnt[71];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%lld",&val[i]);
	memset(cnt,0,sizeof(cnt));
	for (int i=1;i<=n;i++)
	{
		int tmp=0;
		long long x=val[i];
		a[i]=x;
		while (val[i]%2==0)
		{
			++tmp;
			val[i]/=2;
		}
		res[tmp].push_back(x);
		++cnt[tmp];
	}
	int ans=n;
	for (int i=0;i<=70;i++)
		ans=min(ans,n-cnt[i]);
	printf("%d\n",ans);
	if (ans==0) return 0;
	for (int i=0;i<=70;i++)
		if (n-cnt[i]==ans)
		{
			for (int j=0;j<(int)res[i].size();j++)
				vis[res[i][j]]=true;
			for (int i=1;i<=n;i++)
				if (!vis[a[i]]) printf("%lld ",a[i]);
			printf("\n");
			break;
		}
	return 0;
}