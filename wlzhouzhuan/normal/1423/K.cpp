#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#define int long long
#define N 200010
using namespace std;
inline int read()
{
	int neg=1,num=0;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')neg=-1;
	for(;isdigit(c);c=getchar())num=(num<<1)+(num<<3)+c-'0';
	return neg*num;
}
int n,pri[N],tot,po[N];
bool vis[N];
inline void sieve()
{
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])pri[++tot]=i;
		for(int j=1;j<=tot && pri[j]*i<=n;j++)
		{
			vis[i*pri[j]]=1;
			if(i%pri[j]==0)break;
		}
	}
	for(int i=1;i<=tot;i++)po[i]=pri[i]*pri[i];
}
signed main()
{
	n=1e6;sieve();
	int T=read();
	while(T--)
	{
		n=read();
		int x=upper_bound(pri+1,pri+tot+1,n)-pri-1;
		int y=upper_bound(po+1,po+tot+1,n)-po-1;
		printf("%lld\n",x-y+1);
	}
	return 0;
}