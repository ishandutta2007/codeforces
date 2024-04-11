#include<bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
using namespace std;
int ans[105];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) ans[i]=i;
		random_shuffle(ans+1,ans+n+1);
		for(int i=1;i<=n;i++) printf("%d%c",ans[i],i<n?' ':'\n');
	}
	return 0;
}