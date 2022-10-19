#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int dp[4000005];
int n,mod;
vector<int>v[4000005];
int main()
{
	n=read();
	mod=read();
	dp[1]=1;
	for(int j=2;j<=n/2;j++)
	{
		v[2*j].push_back(j);
	}
	int gre=0,qz=1;
	for(int i=2;i<=n;i++)
	{
		//printf("%d %d\n",query(i),qz[i-1]);
		dp[i]=qz;
		for(int sth=0;sth<v[i].size();sth++)
		{
			gre=(gre+dp[i/v[i][sth]])%mod;
			gre=(gre+mod-dp[i/v[i][sth]-1])%mod;
			if(i+v[i][sth]<=n)v[i+v[i][sth]].push_back(v[i][sth]);
		}
		gre=(gre+1)%mod;
		dp[i]=(dp[i]+gre)%mod;
		vector<int>iwannadie;
        swap(v[i],iwannadie);
		qz=(qz+dp[i])%mod;
		//printf("%d\n",dp[i]);
	}
	printf("%d\n",dp[n]);
	return 0;
}