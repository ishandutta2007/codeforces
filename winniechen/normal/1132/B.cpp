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
int a[N],n;
ll sum=0;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i];
	sort(a+1,a+n+1);reverse(a+1,a+n+1);
	int Q;scanf("%d",&Q);
	while(Q--)
	{
		int x;scanf("%d",&x);
		printf("%lld\n",sum-a[x]);
	}
}