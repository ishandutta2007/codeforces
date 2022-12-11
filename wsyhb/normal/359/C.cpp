#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7;
int get_power(int a,long long n)
{
	int res=1;
	while(n)
	{
		if(n&1)
			res=1ll*res*a%P;
		a=1ll*a*a%P;
		n>>=1; 
	}
	return res;
}
const int max_n=1e5+5;
long long a[max_n];
map<long long,int> cnt;
int main()
{
//	freopen("in.txt","r",stdin); 
	int n,x;
	scanf("%d%d",&n,&x);
	long long sum=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",a+i);
		sum+=a[i];
	}
	long long Min=1e18;
	for(int i=1;i<=n;++i)
	{
		a[i]=sum-a[i];
		++cnt[a[i]];
		Min=min(Min,a[i]);
	}
	while(Min<sum)
	{
		int cnt_now=cnt[Min];
		if(cnt_now%x!=0)
		{
			printf("%d\n",get_power(x,Min));
			return 0;
		}
		cnt[++Min]+=cnt_now/x;
	}
	printf("%d\n",get_power(x,Min));
	return 0;
}