#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
int cnt[10],use[10];
ll binom[50][50];
int main()
{
	ll n;
	int i,j;
	scanf("%lld",&n);
	while(n) cnt[n%10]++,n/=10;
	binom[0][0]=1;
	for(i=1;i<50;i++)
	{
		for(j=0;j<50;j++)
		{
			binom[i][j]=binom[i-1][j];
			if(j!=0) binom[i][j]+=binom[i-1][j-1];
		}
	}
	vector<int> dig;
	for(i=0;i<10;i++) if(cnt[i]) dig.pb(i),use[i]=1;
	ll sol=0;
	while(1)
	{
		//for(i=0;i<dig.size();i++) printf("(%i: %i %i)\n",dig[i],use[dig[i]],cnt[dig[i]]);
		int all=0,tmp=0;
		for(i=0;i<dig.size();i++)
		{
			all+=use[dig[i]];
		}
		ll ans=1;
		//printf("%i\n",all);
		for(i=0;i<dig.size();i++)
		{
			ans*=binom[all-tmp][use[dig[i]]];
			tmp+=use[dig[i]];
		}
		if(dig[0]==0)
		{
			ll del=1;
			tmp=0;
			for(i=1;i<dig.size();i++)
			{
				del*=binom[all-1-tmp][use[dig[i]]];
				tmp+=use[dig[i]];
			}
			del*=binom[all-1-tmp][use[dig[0]]-1];
			ans-=del;
		}
		sol+=ans;
		use[dig[0]]++;
		i=0;
		while(i<dig.size() && use[dig[i]]>cnt[dig[i]])
		{
			//printf(":D\n");
			use[dig[i]]=1;
			if(i+1<dig.size()) use[dig[i+1]]++;
			i++;
		}
		if(i>=dig.size()) break;
	}
	printf("%lld\n",sol);
	return 0;
}