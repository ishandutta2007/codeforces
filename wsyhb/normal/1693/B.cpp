#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
int p[max_n],l[max_n],r[max_n];
long long val[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=2;i<=n;++i)
			scanf("%d",p+i);
		for(int i=1;i<=n;++i)
		{
			scanf("%d%d",l+i,r+i);
			val[i]=0;
		}
		int ans=0;
		for(int i=n;i>=1;--i)
		{
			if(val[i]<l[i])
			{
				++ans;
				val[i]=r[i];
			}
			else
				val[i]=min(val[i],1ll*r[i]);
			val[p[i]]+=val[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}