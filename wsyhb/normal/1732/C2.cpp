#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
int a[max_n],nxt[max_n],lst[max_n],xor_sum[max_n];
long long sum[max_n];
inline long long f(int l,int r)
{
	return (sum[r]-sum[l-1])-(xor_sum[r]^xor_sum[l-1]);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,q;
		scanf("%d%d",&n,&q);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",a+i);
			xor_sum[i]=xor_sum[i-1]^a[i];
			sum[i]=sum[i-1]+a[i];
			if(a[i])
				lst[i]=i;
			else
				lst[i]=lst[i-1];
		}
		nxt[n+1]=n+1;
		for(int i=n;i>=1;--i)
		{
			if(a[i])
				nxt[i]=i;
			else
				nxt[i]=nxt[i+1];
		}
		while(q--)
		{
			int L,R;
			scanf("%d%d",&L,&R);
			if(nxt[L]>R)
			{
				printf("%d %d\n",L,L);
				continue;
			}
			vector<int> posL,posR;
			int now=nxt[L];
			while(now<=R&&(int)posL.size()<31)
			{
				posL.push_back(now);
				now=nxt[now+1];
			}
			now=lst[R];
			while(now>=L&&(int)posR.size()<31)
			{
				posR.push_back(now);
				now=lst[now-1];
			}
			reverse(posR.begin(),posR.end());
			long long goal=f(L,R);
			int l=L,r=R,len=R-L+1;
			for(int a:posL)
				for(int b:posR)
				{
					if(b-a+1>=len)
						break;
					if(a<=b&&f(a,b)==goal)
					{
						l=a,r=b,len=b-a+1;
						break;
					}
				}
			printf("%d %d\n",l,r);
		}
	}
	return 0;
}