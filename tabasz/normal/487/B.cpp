#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<iostream>
#include<ctime>
#include<queue>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define LL long long
#define PB push_back
const int M=131072;

pair<int, int> D[2*M];
int dp[2*M];
int n, m, l;

void add(int v, int w)
{
	v+=M;
	D[v]=MP(w, w);
	while(v>1)
	{
		v/=2;
		D[v].F=min(D[2*v].F, D[2*v+1].F);
		D[v].S=max(D[2*v].S, D[2*v+1].S);
	}
}

void add2(int v, int w)
{
	v+=M;
	dp[v]=w;
	while(v>1)
	{
		v/=2;
		dp[v]=max(dp[2*v], dp[2*v+1]);
	}
}

int maxi(int p, int k)
{
	if(p>k) return -1;
	p+=M;
	k+=M;
	int res=max(D[p].S, D[k].S);
	while(p/2!=k/2)
	{
		if(p%2==0) res=max(res, D[p+1].S);
		if(k%2==1) res=max(res, D[k-1].S);
		p/=2;
		k/=2;
	}
	return res;
}

int mini(int p, int k)
{
	if(p>k) return 1000000000;
	p+=M;
	k+=M;
	int res=min(D[p].F, D[k].F);
	while(p/2!=k/2)
	{
		if(p%2==0) res=min(res, D[p+1].F);
		if(k%2==1) res=min(res, D[k-1].F);
		p/=2;
		k/=2;
	}
	return res;
}

int mini2(int p, int k)
{
	if(p>k) return 2000000001;
	p+=M;
	k+=M;
	int res=min(dp[p], dp[k]);
	while(p/2!=k/2)
	{
		if(p%2==0) res=min(res, dp[p+1]);
		if(k%2==1) res=min(res, dp[k-1]);
		p/=2;
		k/=2;
	}
	return res;
}

int main()
{
	scanf("%d%d%d", &n, &m, &l);
	for(int i=1; i<=n; i++)
	{
		int a;
		scanf("%d", &a);
		add(i, a);
	}
	for(int i=1; i<l; i++) add2(i, 2000000001);
	for(int i=l; i<=n; i++)
	{
		int p=0, k=i-l, mid=(p+k)/2, bestend=i-l+1;
		while(p<=k)
		{
			if(maxi(mid+1, i)-mini(mid+1, i)<=m)
			{
				bestend=min(bestend, mid);
				k=mid-1;
			}
			else p=mid+1;
			mid=(p+k)/2;
		}
		int tmp=mini2(bestend, i-l);
		if(tmp==2000000001) add2(i, 2000000001);
		else add2(i, tmp+1);
	}
	if(dp[n+M]==2000000001) printf("-1\n");
	else printf("%d\n", dp[M+n]);
	return 0;
}