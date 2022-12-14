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
int n,num[N],s[N],t[N][2];
long long ans,a[N];
int main()
{
	scanf("%d",&n);t[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		for(int k=0;k<=60;k++)if((a[i]>>k)&1)num[i]++;
		int maxx=num[i],sum=num[i];
		for(int j=i-1;j&&j>=i-120;j--)
		{
			maxx=max(num[j],maxx);
			sum+=num[j];
			if(sum&1)continue;
			ans+=(maxx*2<=sum);
		}
		s[i]=s[i-1]+num[i];
		if(i>121)ans+=t[i-122][s[i]&1];
		t[i][0]=t[i-1][0],t[i][1]=t[i-1][1];
		t[i][s[i]&1]++;
	}
	printf("%lld\n",ans);
}