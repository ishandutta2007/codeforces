#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int t,n,a[N],s[N][N];
long long ans;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			for(int j=1;j<=n;j++)
				s[i][j]=s[i-1][j];
			s[i][a[i]]++;
		}
		ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				ans+=s[i-1][a[j]]*(s[n][a[i]]-s[j][a[i]]);
		printf("%I64d\n",ans);
	}
	return 0;
}