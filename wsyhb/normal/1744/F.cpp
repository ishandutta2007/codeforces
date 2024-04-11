#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
int pos[max_n];
inline long long calc(int a,int b,int c)
{
	if(c<0)
		return 0;
	a=min(a,c),b=min(b,c);
	if(a+b<=c)
		return (a+1ll)*(b+1);
	return (c-b+1ll)*(b+1)+(c-a+1ll+b)*(b-c+a)/2;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			int p;
			scanf("%d",&p);
			pos[p]=i;
		}
		long long ans=1;
		int mn=pos[0],mx=pos[0];
		for(int k=1;k<=n-1;++k)
		{
			if(pos[k]<mn)
				ans+=calc(mn-pos[k]-1,n-mx,k-((mx-mn+1)-k));
			else if(pos[k]>mx)
				ans+=calc(mn-1,pos[k]-mx-1,k-((mx-mn+1)-k));
			mn=min(mn,pos[k]);
			mx=max(mx,pos[k]);
//			fprintf(stderr,"k=%d ans=%lld\n",k,ans);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
1
6
2 0 4 1 3 5
---
8
*/