#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 55
#define ll long long
ll f[N][2][2],K;int n,a[N];
ll dfs(int pos,int rev,int inv)
{
	if(pos>n-pos+1)return 1;
	if(f[pos][rev][inv]!=-1)return f[pos][rev][inv];f[pos][rev][inv]=0;
	for(int i=0;i<2;i++)if(a[pos]==i||a[pos]==-1)
		for(int j=0;j<2;j++)if(a[n-pos+1]==j||a[n-pos+1]==-1)
		{
			if((rev&(i>j))||(inv&i&j)||(pos==n-pos+1&&i!=j))continue;
			f[pos][rev][inv]+=dfs(pos+1,rev&(i==j),inv&(i!=j));
		}
	return f[pos][rev][inv];
}
int main()
{
	scanf("%d%lld",&n,&K);K++;
	memset(f,-1,sizeof(f));memset(a,-1,sizeof(a));
	if(dfs(1,1,1)<K)return puts("-1"),0;
	a[1]=0;
	for(int i=2;i<=n;i++)
	{
		a[i]=0;
		memset(f,-1,sizeof(f));
		ll tmp=dfs(1,1,1);
		if(tmp<K)K-=tmp,a[i]=1;
	}
	for(int i=1;i<=n;i++)printf("%d",a[i]);
}