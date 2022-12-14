#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
#define N 200005
int a[N],n,k;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);a[n+1]=1<<30;
	int cnt=1,j=1;
	for(int i=1;i<n;i++)
	{
		while(a[j]==a[i])j++;
		if(a[j]>a[i]+k)cnt++;
	}
	printf("%d\n",cnt);
}