#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <cstdlib>
#include <bitset>
using namespace std;
#define N 1000005
int a[N],b[N],n,ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%1d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%1d",&b[i]);
	for(int i=1;i<=n;i++)
	{
		if(a[i]==b[i])continue;
		if(a[i]!=b[i])
		{
			ans++;
			if(a[i+1]!=b[i+1]&&a[i+1]!=a[i])i++;
		}
	}printf("%d\n",ans);
}