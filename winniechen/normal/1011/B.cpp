#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
using namespace std;
#define N 105
int a[N],n,m,num[N];
bool check(int mid)
{
	int ret=0;
	for(int i=1;i<=100;i++)ret+=num[i]/mid;
	if(ret>=n)return 1;return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d",&a[i]),num[a[i]]++;
	int l=1,r=101;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid;
	}printf("%d\n",l-1);
}