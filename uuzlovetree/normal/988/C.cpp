#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int k,n[maxn],sum[maxn];
vector<int> a[maxn];
struct node
{
	int x,y;
	node(int a=0,int b=0){x=a;y=b;}
};
map<int,node> mp;
int main()
{
	scanf("%d",&k);
	for(int i=1;i<=k;++i)
	{
		scanf("%d",&n[i]);
		for(int j=1;j<=n[i];++j)
		{
			int x;scanf("%d",&x);
			a[i].push_back(x);
			sum[i]+=x;
		}
		for(int j=1;j<=n[i];++j)
		{
			if(mp.count(sum[i]-a[i][j-1]))
			{
				node ans=mp[sum[i]-a[i][j-1]];
				puts("YES");
				printf("%d %d\n",i,j);
				printf("%d %d\n",ans.x,ans.y);
				return 0;
			}
		}
		for(int j=1;j<=n[i];++j)
		{
			mp[sum[i]-a[i][j-1]]=node(i,j);
		}
	}
	puts("NO");
	return 0;
}