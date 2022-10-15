#include <bits/stdc++.h>
#define MOD 1000000007
#define SIZE 200005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

ll inv[SIZE],fac[SIZE],finv[SIZE];
ll dp[SIZE];
P pos[SIZE];

void init()
{
	inv[1]=1;
	fac[0]=fac[1]=finv[0]=finv[1]=1;
	for(int i=2;i<SIZE;i++)
	{
		inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
		fac[i]=fac[i-1]*(ll) i%MOD;
		finv[i]=finv[i-1]*inv[i]%MOD;
	}
}
ll C(int a,int b)
{
	if(a<b) return 0;
	return fac[a]*(finv[b]*finv[a-b]%MOD)%MOD;
}
int main()
{
	init();
	int h,w,n;
	scanf("%d %d %d",&h,&w,&n);
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		pos[i]=P(a,b);
	}
	pos[n++]=P(0,0);
	pos[n++]=P(h-1,w-1);
	sort(pos,pos+n);
	dp[0]=1;
	for(int i=1;i<n;i++)
	{
		dp[i]=0;
		for(int j=0;j<i;j++)
		{
			P p=pos[j];
			P q=pos[i];
			int a=q.first-p.first,b=q.second-p.second;
			if(a>=0&&b>=0)
			{
				dp[i]+=dp[j]*C(a+b,a)%MOD;
				if(dp[i]>=MOD) dp[i]-=MOD;
			}
		}
		if(dp[i]!=0) dp[i]=MOD-dp[i];
	}
	ll ret=MOD-dp[n-1];
	ret%=MOD;
	printf("%I64d\n",ret);
	return 0;
}