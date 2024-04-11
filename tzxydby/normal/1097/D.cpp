#include<bits/stdc++.h>
using namespace std;
const int md=1e9+7;
inline void add(int &a,int b)
{
	a+=b;
	if(a>=md)
		a-=md;
}
inline void sub(int &a,int b)
{
	a-=b;
	if(a<0)
		a+=md;
}
inline int mul(int a,int b)
{
	return (int)((long long)a*b%md);
}
inline int power(int a,long long b)
{
	int res=1;
	while(b>0)
	{
		if(b&1)
			res=mul(res,a);
		a=mul(a,a);
		b>>=1;
	}
	return res;
}
inline int inv(int a)
{
	a%=md;
	if(a<0)
		a+=md;
	int b=md,u=0,v=1;
	while(a)
	{
		int t=b/a;
		b-=t*a;
		swap(a,b);
		u-=t*v;
		swap(u,v);
	}
	assert(b==1);
	if(u<0)
		u+=md;
	return u;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n;
	int k;
	cin>>n>>k;
	vector<pair<long long,int>> f;
	for(long long i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			int cc=0;
			while(n%i==0)
			{
				n/=i;
				cc++;
			}
			f.emplace_back(i,cc);
		}
	}
	if(n>1)
		f.emplace_back(n,1);
	int ans=1;
	for(auto& p:f)
	{
		int cc=p.second;
		vector<vector<int>> dp(k+1,vector<int>(cc+1,0));
		dp[0][cc]=1;
		for(int i=0;i<k;i++)
		{
			for(int j=0;j<=cc;j++)
			{
				int cur=mul(dp[i][j],inv(j+1));
				for(int t=0;t<=j;t++)
					add(dp[i+1][t],cur);
			}
		}
		int x=1;
		int cur=0;
		for(int j=0;j<=cc;j++)
		{
			add(cur,mul(x,dp[k][j]));
			x=mul(x,(int)(p.first%md));
		}
		ans=mul(ans,cur);
	}
	cout<<ans<<endl;
	return 0;
}