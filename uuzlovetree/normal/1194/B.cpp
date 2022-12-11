#include<bits/stdc++.h>
#define maxn 500005
using namespace std;
int T,n,m;
vector<char> a[maxn];
char str[maxn];
int r[maxn],c[maxn];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)a[i].clear(),a[i].push_back(' ');
		for(int i=1;i<=n;++i)r[i]=0;
		for(int i=1;i<=m;++i)c[i]=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%s",str+1);
			for(int j=1;j<=m;++j)a[i].push_back(str[j]);
		}
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)if(a[i][j]=='*')r[i]++;
		for(int j=1;j<=m;++j)
			for(int i=1;i<=n;++i)if(a[i][j]=='*')c[j]++;
		int ans=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)ans=max(ans,r[i]+c[j]-(a[i][j]=='*'));
		printf("%d\n",n+m-1-ans);
	}
}