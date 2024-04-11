#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 300005
#define ll long long
ll sum1[N],sum2[N];int n,m,a[N],b[N],ans;
int main()
{
	scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum1[i]=sum1[i-1]+a[i];
	scanf("%d",&m);for(int i=1;i<=m;i++)scanf("%d",&b[i]),sum2[i]=sum2[i-1]+b[i];
	if(sum1[n]!=sum2[m])return puts("-1"),0;
	for(int i=1,j=1;i<=n;i++)
	{
		while(sum2[j]<sum1[i]&&j<=m)j++;
		if(sum1[i]==sum2[j])ans++;
	}printf("%d\n",ans);return 0;
}