#include<cstdio>
#include<vector>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const long long mod=1000000007;

vector<int> lucky;

int cnt[1050];
long long dp[1050][1050];//[using 0,1,...i][select j numbers]
long long fact[100100];

int a[100100];

int N,K;

long long get(long long n,int e)
{
	if(e==0) return 1;
	long long a=get(n,e/2);
	a*=a;
	a%=mod;
	if(e%2==1) a*=n;
	a%=mod;
	return a;
}

int main()
{
	lucky.push_back(4);lucky.push_back(7);
	int id=2;
	for(int d=2;d<=9;d++)
	{
		for(int i=0;i<id;i++)
		{
			lucky.push_back(lucky[i]*10+4);
			lucky.push_back(lucky[i]*10+7);
		}
		id=lucky.size();
	}
	sort(lucky.begin(),lucky.end());
	lucky.erase(unique(lucky.begin(),lucky.end()),lucky.end());
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)
	{
		scanf("%d",a+i);
	}
	int all=0;
	for(int i=0;i<N;i++)
	{
		vector<int>::iterator it=lower_bound(lucky.begin(),lucky.end(),a[i]);
		if(it==lucky.end()) continue;
		if(a[i]==(*it))
		{
			int id=distance(lucky.begin(),it);
			cnt[id]++;
			all++;
		}
	}
	int num=lucky.size();
	memset(dp,0,sizeof(dp));
	for(int i=0;i<num;i++)
	{
		dp[i][0]=1;
	}
	dp[0][1]=cnt[0];
	for(int i=1;i<lucky.size();i++)
	{
		for(int j=1;j<=lucky.size();j++)
		{
			dp[i][j]=dp[i-1][j]+dp[i-1][j-1]*cnt[i];
			dp[i][j]%=mod;
		}
	}/*
	fact[0]=1;
	fact[1]=N-all;
	for(int i=2;i<=N;i++)
	{
		fact[i]=fact[i-1]*(N-all-i+1);
		fact[i]%=mod;
	}*/
	long long fact2[100100];
	fact2[0]=1;
	for(int i=1;i<=100050;i++)
	{
		fact2[i]=fact2[i-1]*i;
		fact2[i]%=mod;
	}
	long long factinv[100100];
	for(int i=0;i<=100050;i++) factinv[i]=get(fact2[i],mod-2);
	long long ans=0;
	for(int i=0;i<=K;i++)
	{
	//	ans+=(fact[K-i]*dp[num-1][i]*factinv[i]);
		//i lucky numbers K-i unlucky nubers
		//dp[num-1][i]*(N-all)C(K-i)
		if(N-all-K+i<0) continue;
		if(i>num) continue;
		long long tmp=dp[num-1][i]*fact2[N-all];
		tmp%=mod;
		tmp*=factinv[K-i];
		tmp%=mod;
		tmp*=factinv[N-all-K+i];
		tmp%=mod;
		ans+=tmp;
		ans%=mod;
	}
	cout<<ans<<"\n";
	return 0;
}