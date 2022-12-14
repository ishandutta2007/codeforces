#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 100005
int a[N],b[N],n,num1,num2,num3,num4;long long ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%1d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%1d",&b[i]);
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0&&a[i]==0)ans+=num2,num1++;
		if(a[i]==1)
		{
			if(b[i]==0)ans+=num3,num4++;
			num2++,ans+=num1;
		}if(a[i]==0&&b[i]!=0)num3++,ans+=num4;
		// printf("%lld\n",ans);
	}printf("%lld\n",ans);
}