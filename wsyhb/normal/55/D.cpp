#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
int lcm(int a,int b)
{
	return a/gcd(a,b)*b;
}
const int max_s=1<<9|5;
int L[max_s],Log[max_s],val[max_s],cnt;
const int max_cnt=48+5;
int tr1[max_cnt][10];
const int max_val=2520+5;
int tr2[max_val][10],id[max_val];
const int mod=2520;
inline void init()
{
	Log[0]=-1,val[0]=L[0]=1;
	for(int s=1;s<512;++s)
	{
		Log[s]=Log[s>>1]+1;
		int v=s&(-s);
		val[s]=L[s]=lcm(L[s^v],Log[v]+1);
	}
	sort(val,val+512);
	cnt=unique(val,val+512)-val;
	assert(cnt==48);
	for(int i=0;i<cnt;++i)
		id[val[i]]=i;
	for(int i=0;i<cnt;++i)
	{
		tr1[i][0]=i;
		for(int j=1;j<=9;++j)
			tr1[i][j]=id[lcm(val[i],j)];
	}
	for(int i=0;i<2520;++i)
		for(int j=0;j<=9;++j)
			tr2[i][j]=(i*10+j)%mod;
}
inline int tran1(int x,int v)
{
	return tr1[x][v];
}
inline int tran2(int x,int v)
{
	return tr2[x][v];
}
long long dp[20][48][2520][2];
inline long long calc(long long x)
{
	vector<int> d;
	while(x)
	{
		d.push_back(x%10);
		x/=10;
	}
	dp[(int)d.size()][0][0][0]=1;
	for(int i=(int)d.size()-1;i>=0;--i)
		for(int j=0;j<48;++j)
			for(int k=0;k<2520;++k)
			{
				long long v=dp[i+1][j][k][0];
				if(v)
				{
					dp[i][tran1(j,d[i])][tran2(k,d[i])][0]+=v;
					for(int t=d[i]-1;t>=0;--t)
						dp[i][tran1(j,t)][tran2(k,t)][1]+=v;
				}
				v=dp[i+1][j][k][1];
				if(v)
				{
					for(int t=9;t>=0;--t)
						dp[i][tran1(j,t)][tran2(k,t)][1]+=v;
				}
			}
	long long res=0;
	for(int i=0;i<48;++i)
		for(int j=0;j<mod;j+=val[i])
			res+=dp[0][i][j][0]+dp[0][i][j][1];
	for(int i=d.size();i>=0;--i)
		for(int j=0;j<48;++j)
			for(int k=0;k<2520;++k)
				for(int t=0;t<=1;++t)
					dp[i][j][k][t]=0;
	return res;
}
int main()
{
	init();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long l,r;
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",calc(r)-calc(l-1));
	}
	return 0;
}