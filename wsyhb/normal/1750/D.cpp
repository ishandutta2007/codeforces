#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
int a[max_n];
inline int phi(int v)
{
	int res=1;
	for(int i=2;i*i<=v;++i)
	{
		if(v%i==0)
		{
			res*=i-1;
			v/=i;
			while(v%i==0)
				v/=i,res*=i;
		}
	}
	if(v>1)
		res*=v-1;
	return res;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
			scanf("%d",a+i);
		bool ans=true;
		for(int i=1;i+1<=n;++i)
		{
			if(a[i]%a[i+1])
			{
				ans=false;
				break;
			}
		}
		if(!ans)
		{
			puts("0");
			continue;
		}
		int Ans=1;
		const int mod=998244353;
		vector<int> Div;
		for(int i=1;i*i<=a[1];++i)
		{
			if(a[1]%i==0)
			{
				Div.push_back(i);
				if(i*i!=a[1])
					Div.push_back(a[1]/i);
			}
		}
		int sz=Div.size();
		vector<int> cnt(sz);
		int t=a[1];
		vector<int> prime;
		for(int i=2;i*i<=t;++i)
		{
			if(t%i==0)
			{
				prime.push_back(i);
				while(t%i==0)
					t/=i;
			}
		}
		if(t>1)
			prime.push_back(t);
		for(int i=0;i<sz;++i)
		{
			int t=Div[i];
			for(int p:prime)
			{
				if(t%p==0)
				{
					t/=p;
					++cnt[i];
					if(t%p==0)
					{
						cnt[i]=-1;
						break;
					}
				}
			}
		}
		for(int i=1;i+1<=n;++i)
		{
			if(a[i]==a[i+1])
			{
				Ans=1ll*Ans*(m/a[i])%mod;
				continue;
			}
			int R=m/a[i+1],v=a[i]/a[i+1],res=0;
			for(int i=0;i<sz;++i)
			{
				if(v%Div[i]==0&&cnt[i]!=-1)
					res=(res+(cnt[i]&1?-1ll:1ll)*(R/Div[i]))%mod;
			}
			res+=res<0?mod:0;
			Ans=1ll*Ans*res%mod;
		}
		printf("%d\n",Ans);
	}
	return 0;
}