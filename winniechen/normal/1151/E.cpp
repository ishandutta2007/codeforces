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
int n,a[N];long long ans;
long long calc(int x,int y)
{
	if(x>y)swap(x,y);
	return (long long)(x+n-y+1)*(y-x);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=0;i<=n;i++)ans+=calc(a[i],a[i+1]);
	printf("%lld\n",ans>>1);
}