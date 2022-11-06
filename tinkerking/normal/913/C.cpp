#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
LL L;
LL f[35];

int main()
{
	scanf("%d%lld",&N,&L);
	for (int i=1;i<=N;i++)scanf("%lld",&f[i]);
	for (int i=2;i<=N;i++)f[i] = min(f[i],2LL*f[i-1]);
	for (int i=N+1;i<=31;i++)f[i] = f[i-1] * 2LL;
	//for (int i=1;i<=31;i++) printf("%d %lld %d\n",i,f[i],1<<(i-1));
	LL ans = 4e18;
	for (int i=31;i>=1;i--)
	if ((1<<(i-1)) >= L)
	{
		ans = min(ans,f[i]);
	}
	LL tmp = 0;
	for (int i=31;i>=1;i--)
	if ((1<<(i-1)) <= L)
	{
		for (int j=i+1;j<=31;j++)ans = min(ans,tmp + f[j]);
		tmp += f[i];
		L -= (1<<(i-1));
		//printf("L = %lld\n",L); 
	}
	ans = min(ans,tmp);
	printf("%lld\n",ans);
}