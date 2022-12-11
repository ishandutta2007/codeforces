#include<bits/stdc++.h>
using namespace std;
const int max_n=3e5+5;
int val[max_n];
long long mask[max_n];
inline int sign(long long x)
{
	return x>0?1:-1;
}
int main()
{
	int n;
	scanf("%d",&n);
	long long init_sum=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%d%lld",val+i,mask+i);
		init_sum+=val[i];
	}
	assert(init_sum!=0);
	long long s=0;
	for(int i=0;i<62;++i)
	{
		long long sum_now=0;
		for(int j=1;j<=n;++j)
		{
			if(mask[j]==(1ll<<i))
				sum_now+=val[j];
		}
		if(sum_now&&sign(sum_now)==sign(init_sum))
		{
			s|=1ll<<i;
			for(int j=1;j<=n;++j)
			{
				if(mask[j]&(1ll<<i))
					val[j]=-val[j];
			}
		}
		for(int j=1;j<=n;++j)
			mask[j]&=~(1ll<<i);
	}
	printf("%lld\n",s);
	return 0;
}