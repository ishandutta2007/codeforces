#include<bits/stdc++.h>
using namespace std;
int n,k,cnt;
struct Number
{
	int v[18];
	inline Number(int x=0)
	{
		for(int i=0;i<=cnt-1;++i)
			v[i]=x%k,x/=k;
	}
	inline Number inverse()
	{
		static Number res;
		for(int i=0;i<=cnt-1;++i)
			res.v[i]=v[i]?k-v[i]:0;
		return res;
	}
	inline int to_int()
	{
		int res=0;
		for(int i=cnt-1;i>=0;--i)
			res=res*k+v[i];
		return res;
	}
};
inline Number operator + (const Number &a,const Number &b)
{
	static Number res;
	for(int i=0;i<=cnt-1;++i)
	{
		res.v[i]=a.v[i]+b.v[i];
		res.v[i]-=res.v[i]>=k?k:0;
	}
	return res;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		cnt=1;
		int t=n;
		while(t>=k)
			++cnt,t/=k;
		int K=1;
		Number B(0);
		for(int i=0;i<=n-1;++i)
		{
			Number s(i);
			Number now=(K==1?s:s.inverse())+B;
			int y=now.to_int();
			printf("%d\n",y);
			fflush(stdout);
			int r;
			scanf("%d",&r);
			assert(r!=-1);
			if(i==n-1)
				assert(r==1);
			if(r==1)
				break;
			K=-K;
			B=B.inverse()+now;
		}
	}
	return 0;
}