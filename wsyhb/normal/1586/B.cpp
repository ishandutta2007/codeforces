#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
bool vis[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
			vis[i]=false;
		for(int i=1;i<=m;++i)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			vis[b]=true;
		}
		int root=-1;
		for(int i=1;i<=n;++i)
		{
			if(!vis[i])
			{
				root=i;
				break;
			}
		}
		assert(root!=-1);
		for(int i=1;i<=n;++i)
		{
			if(root!=i)
				printf("%d %d\n",root,i);
		}
	}
	return 0;
}