#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100050;
int cnt[N];
bool ok;
int n,k;
int my_pow(int x, int k)
{
	int ans=1;
	for(;k;k>>=1,x=x*x)
	{
		if(k&1) ans=ans*x;
	}
	return ans;
}
void Take(int p, int l, int &y, int &z)
{
	y*=my_pow(p,l);
	if(N/z<pow(p,k-l)) ok=0;
	else z*=my_pow(p,k-l);
}
int main()
{
	scanf("%i %i",&n,&k);
	ll ans=0;
	while(n--)
	{
		int x,y=1,z=1;
		ok=1;
		scanf("%i",&x);
		for(int i=2;i*i<=x;i++)
		{
			int c=0;
			while(x%i==0)
			{
				c++;
				x/=i;
			}
			if(c%k!=0) Take(i,c%k,y,z);
		}
		if(x>1)
		{
			Take(x,1,y,z);
		}
		if(ok)
		{
			ans+=cnt[z];
			cnt[y]++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}