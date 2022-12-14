#include <cstdio>
#include <cmath>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <bitset>
using namespace std;
#define N 300005
#define ll long long
ll x,y;int n,a[N],num;
int main()
{
	scanf("%d%lld%lld",&n,&x,&y);
	for(int i=1;i<=n;i++)scanf("%1d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		if(!a[i])
		{
			num++;
			while(!a[i])i++;
			i--;
		}
	}
	printf("%lld\n",max(min(x*num-x+y,y*num),0ll));
}