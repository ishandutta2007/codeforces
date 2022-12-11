#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
char s[max_n];
const int mod=998244353;
int fac[max_n],inv_fac[max_n],inv[max_n];
inline void init(int n)
{
	fac[0]=inv_fac[0]=1;
	fac[1]=inv_fac[1]=inv[1]=1;
	for(int i=2;i<=n;++i)
	{
		fac[i]=1ll*fac[i-1]*i%mod;
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
		inv_fac[i]=1ll*inv_fac[i-1]*inv[i]%mod;
	}
}
inline int C(int n,int m)
{
	assert(n>=0&&m>=0&&n>=m);
	return 1ll*fac[n]*inv_fac[m]%mod*inv_fac[n-m]%mod;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d%s",&n,s+1);
		vector<int> pos;
		for(int i=1;i<=n;++i)
		{
			if(s[i]=='1')
				pos.push_back(i);
		}
		bool no_adj=true;
		for(int i=0;i+1<int(pos.size());++i)
		{
			if(pos[i]+1==pos[i+1])
			{
				no_adj=false;
				break;
			}
		}
		if(no_adj)
		{
			puts("1");
			continue;
		}
		pos.insert(pos.begin(),0);
		pos.push_back(n+1);
		vector<int> delta;
		for(int i=0;i+1<int(pos.size());++i)
			delta.push_back(pos[i+1]-pos[i]);
		int sum=0;
		for(int i=0;i<int(delta.size());++i)
		{
//			fprintf(stderr,"%d%c",delta[i],i+1<int(delta.size())?' ':'\n');
			sum+=delta[i];
		}
		init(n);
		int cnt=0;
		for(int i=1;i<=n;++i)
		{
			if(s[i]!='1')
				continue;
			int j=i;
			while(j+1<=n&&s[j+1]==s[j])
				++j;
			cnt+=(j-i+1+1)/2;
			i=j;
		}
		printf("%d\n",C(sum-1-cnt,(int)delta.size()-1-cnt));
	}
	return 0;
}
/*
2
20
01100110100110111101
20
11000110100110111101
---
1287
1287
*/