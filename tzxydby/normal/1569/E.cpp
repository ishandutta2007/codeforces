#include<bits/stdc++.h>
using namespace std;
const int N=50,mod=998244353,d[]={1,2,3,5,9,17};
int n,k,a,z,p[N];
map<int,vector<int>>mp[2];
int main()
{
	scanf("%d%d%d",&k,&a,&z);
	n=(1<<k);
	p[0]=1;
	for(int i=1;i<=n;i++)
		p[i]=1ll*p[i-1]*a%mod;
	for(int s=0;s<(1<<(n/2));s++)
	{
		int h=0;
		vector<int>x;
		for(int i=1;i<=n/2;i++)
		{
			int g=i+n/2-1,t=k;
			while(g)
			{
				if((s>>(g>>1)&1)^(g&1))
					break;
				g>>=1;
				t--;
			}
			h=(h+1ll*i*p[d[t]]%mod)%mod;
			x.push_back(d[t]);
		}
		mp[s&1][h]=x;
	}
	for(int s=0;s<(1<<(n/2));s++)
	{
		int h=0;
		vector<int>x;
		for(int i=1;i<=n/2;i++)
		{
			int g=i+n/2-1,t=k;
			while(g)
			{
				if((s>>(g>>1)&1)^(g&1))
					break;
				g>>=1;
				t--;
			}
			h=(h+1ll*(i+n/2)*p[d[t]]%mod)%mod;
			x.push_back(d[t]);
		}
		h=(z-h+mod)%mod;
		if(mp[s&1^1].count(h))
		{
			vector<int>y=mp[s&1^1][h];
			for(auto j:y)
				printf("%d ",j);
			for(auto j:x)
				printf("%d ",j);
			puts("");
			return 0;
		}
	}
	puts("-1");
	return 0;
}