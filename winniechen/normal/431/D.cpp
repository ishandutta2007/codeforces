#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 65
#define M 1000000
#define ll long long
ll C[N][N],m;
int k,now;ll ans=1;
int s[M+10];
int get(int x){int num=0;for(;x;x-=x&-x)num++;return num;}
int main()
{
	// freopen("number.in","r",stdin);
	// freopen("number.out","w",stdout);
	scanf("%lld%d",&m,&k);
	for(int i=1;i<=M;i++)s[i]=s[i-1]+(get(i)==k);
	for(int i=1;i*2<=M;i++)
		if(s[i<<1]-s[i]==m)return printf("%d\n",i),0;
	for(int i=0;i<=64;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)C[i][j]=C[i-1][j]+C[i-1][j-1];
	}
	now=k;
	for(int i=60;~i;i--)
		if(C[i+1][now]-C[i][now]+1<=m)m-=C[i+1][now]-C[i][now],now--,ans+=1ll<<i;
	printf("%lld\n",ans);
}