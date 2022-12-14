#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
using namespace std;
#define N 105
int n,a[N],cnt;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%1d",&a[i]);
	}
	if(n==1&&(!a[1]))
	{
		puts("0");
		return 0;
	}
	for(int i=2;i<=n;i++)
	{
		if(a[i])
		{
			cnt++;
		}
	}
	printf("1");
	for(int i=2;i<=n-cnt;i++)printf("0");
	puts("");
	return 0;
}