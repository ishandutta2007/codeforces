#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
int a[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;++i)
			scanf("%d",a+i);
		map<int,bool> vis;
		bool ans=false;
		for(int i=1;i<=n;++i)
		{
			if(vis[a[i]+k]||vis[a[i]-k])
			{
				ans=true;
				break;
			}
			vis[a[i]]=true;
		}
		puts(ans?"YES":"NO");
	}
	return 0;
}