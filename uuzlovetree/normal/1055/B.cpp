#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
int n,q;
ll l;
ll a[maxn];
int ans;
int main()
{
	scanf("%d%d%I64d",&n,&q,&l);
	for(int i=1;i<=n;++i)scanf("%I64d",&a[i]);
	for(int i=1;i<=n;++i)if(a[i]>l&&a[i-1]<=l)ans++;
	while(q--)
	{
		int opt,x;
		ll y;
		scanf("%d",&opt);
		if(opt==0)
		{
			printf("%d\n",ans);
		}
		else
		{
			scanf("%d%I64d",&x,&y);
			if(a[x]<=l)
			{
				a[x]+=y;
				if(a[x]>l)
				{
					if(a[x-1]<=l&&a[x+1]<=l)ans++;
					else if(a[x-1]>l&&a[x+1]>l)ans--;
				}
			}
		}
	}
	return 0;
}