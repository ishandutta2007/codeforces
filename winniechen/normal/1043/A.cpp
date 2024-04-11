#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 105
#define ll long long
int n,a[N],ans,s;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),ans=max(ans,a[i]),s+=a[i];
	for(;ans<=200;ans++)
	{
		int sum=0;
		for(int i=1;i<=n;i++)sum+=ans-a[i];
		if(sum>s)break;
	}
	printf("%d\n",ans);
}