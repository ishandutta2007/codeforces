#include<bits/stdc++.h>
#define maxn 300005
using namespace std;
int n;
int c[maxn];
int last[maxn];
bool vis[maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&c[i]);
	for(int i=1;i<=n;++i)last[c[i]]=i;
	int ans=0;
	for(int i=1;i<=n;++i)if(!vis[c[i]])
	{
		vis[c[i]]=1;
		if(last[c[i]]!=n)
		{
			ans=max(ans,n-i);
		}
		else
		{
			for(int j=i+1;j<=n;++j)if(c[j]!=c[i])ans=max(ans,j-i); 
		}
	}
	printf("%d\n",ans);
	return 0;
}