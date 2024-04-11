#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int s[N];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	vector<vector<int>>a(n+1,vector<int>(m+1,0));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	int ans=0;
	for(int j=1;j<=m;j++)
	{
		for(int i=0;i<=n;i++)
			s[i]=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i][j]>n*m||a[i][j]%m!=j%m)
				continue;
			int k=(a[i][j]-1)/m+1;
			if(i>=k)
				s[i-k]++;
			else
				s[i+n-k]++;
		}
		int mi=n;
		for(int i=0;i<=n;i++)
			mi=min(mi,i+n-s[i]);
		ans+=mi;
	}
	printf("%d\n",ans);
	return 0;
}