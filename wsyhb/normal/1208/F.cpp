#include<bits/stdc++.h>
using namespace std;
const int max_R=1<<21|5;
int mx[max_R],se[max_R];
inline void update(int S,int v)
{
	if(v>mx[S])
	{
		se[S]=mx[S];
		mx[S]=v;
	}
	else
		se[S]=max(se[S],v);
}
const int max_n=1e6+5;
int a[max_n];
int main()
{
	int n;
	scanf("%d",&n);
	int R=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		R=max(R,a[i]);
	}
	if(!R)
	{
		puts("0");
		return 0;
	}
	int Full=0,B=0;
	while(Full<R)
	{
		Full=Full<<1|1;
		++B;
	}
	for(int i=1;i<=n;++i)
		update(a[i],i);
	for(int i=0;i<B;++i)
		for(int S=0;S<=Full;++S)
		{
			if(S>>i&1)
			{
				int T=S^(1<<i);
				update(T,mx[S]);
				update(T,se[S]);
			}
		}
	int ans=0;
	for(int i=1;i<=n-2;++i)
	{
//		fprintf(stderr,"i=%d\n",i);
		int res=0;
		for(int j=B-1;j>=0;--j)
		{
			if(a[i]>>j&1)
				continue;
			res|=1<<j;
//			fprintf(stderr,"j=%d res=%d mx[res]=%d se[res]=%d\n",j,res,mx[res],se[res]);
			if(se[res]<=i)
				res^=1<<j;
		}
		ans=max(ans,a[i]|res);
	}
	printf("%d\n",ans);
	return 0;
}