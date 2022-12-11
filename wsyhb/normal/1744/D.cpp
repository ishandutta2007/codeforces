#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
int expo[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int tot=0;
		for(int i=1;i<=n;++i)
		{
			int a;
			scanf("%d",&a);
			while(a%2==0)
				a>>=1,++tot;
			expo[i]=(i&1?0:expo[i>>1]+1);
		}
		sort(expo+1,expo+n+1,greater<int>());
		int ans=0;
		while(tot<n&&ans<n)
			tot+=expo[++ans];
		if(tot<n)
			ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}