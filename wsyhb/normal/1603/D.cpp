#include<bits/stdc++.h>
using namespace std;
const int R=1e5;
const int max_n=1e5+5;
bool mark_p[max_n];
int prime[max_n],tot,phi[max_n];
long long sum_phi[max_n];
int sqr[max_n];
const int max_sqrt=316+5;
long long s1[max_n][max_sqrt],s2[max_n][max_sqrt];
inline void init()
{
	for(int i=2;i<=R;++i)
		mark_p[i]=true;
	phi[1]=1;
	for(int i=2;i<=R;++i)
	{
		if(mark_p[i])
		{
			prime[++tot]=i;
			phi[i]=i-1;
		}
		for(int j=1;j<=tot&&i*prime[j]<=R;++j)
		{
			mark_p[i*prime[j]]=false;
			if(i%prime[j]==0)
			{
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
	}
	for(int i=1;i<=R;++i)
		sum_phi[i]=sum_phi[i-1]+phi[i];
	for(int i=1;i<=R;++i)
	{
		for(int j=1;j*j<=i;++j)
		{
			s1[i][j]=s1[i][j-1]+sum_phi[j]*(i/j-i/(j+1));
			sqr[i]=j;
		}
		s2[i][i/(sqr[i]+1)+1]=s1[i][sqr[i]];
		for(int j=i/(sqr[i]+1);j>=1;--j)
			s2[i][j]=s2[i][j+1]+sum_phi[i/j];
	}
}
const long long inf=1e18;
inline long long c(int l,int r)
{
	if(l>r)
		return inf;
	if(r/l<=sqr[r])
		return s1[r][r/l]-sum_phi[r/l]*(l-1-r/(r/l+1));
	return s2[r][l];
}
const int max_log=16+5;
long long f[max_log][max_n];
inline void solve(int k,int l,int r,int optl,int optr)
{
	if(l>r)
		return;
	int mid=(l+r)>>1;
	long long res=inf;
	int best=optl;
	for(int i=optl;i<=optr&&i+1<=mid;++i)
	{
		long long cost=c(i+1,mid);
		if(f[k-1][i]+cost<res)
		{
			res=f[k-1][i]+cost;
			best=i;
		}
	}
	f[k][mid]=res;
	solve(k,l,mid-1,optl,best);
	solve(k,mid+1,r,best,optr);
}
int main()
{
	init();
	f[0][0]=0;
	for(int i=1;i<=R;++i)
		f[0][i]=inf;
	for(int k=1;k<=16;++k)
		solve(k,0,R,0,R);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		if(k>16)
			printf("%d\n",n);
		else
			printf("%lld\n",f[k][n]);
	}
	return 0;
}