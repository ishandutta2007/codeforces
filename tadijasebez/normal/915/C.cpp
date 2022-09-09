#include <stdio.h>
#define ll long long
ll max(ll a, ll b){ return a>b?a:b;}
ll ans;
int C[10];
int need[22];
bool Try(int lvl, bool f, ll sol)
{
	if(!(~lvl))
	{
		ans=max(ans,sol);
		return 1;
	}
	if(!f)
	{
		for(int i=9;~i;i--)
		{
			if(C[i])
			{
				C[i]--;
				bool done=Try(lvl-1,0,sol*10+i);
				C[i]++;
				if(done) return 1;
			}
		}
		return 1;
	}
	for(int i=need[lvl];~i;i--)
	{
		if(C[i])
		{
			C[i]--;
			bool done=Try(lvl-1,i==need[lvl],sol*10+i);
			C[i]++;
			if(done) return 1;
		}
	}
	return 0;
}
int main()
{
	ll a,b;
	scanf("%lld %lld",&a,&b);
	int i=0,j=0;
	while(a) C[a%10]++,a/=10,i++;
	while(b) need[j++]=b%10,b/=10;
	if(j>i) Try(i-1,0,0);
	else Try(i-1,1,0);
	printf("%lld\n",ans);
	return 0;
}