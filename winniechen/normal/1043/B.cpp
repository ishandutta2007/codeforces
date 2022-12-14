#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 1005
#define ll long long
int a[N],ans[N],n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=n;i;i--)a[i]-=a[i-1];
	for(int i=1;i<=n;i++)
	{
		int flag=1;
		for(int j=1;j<=i;j++)
			for(int k=j;k<=n;k+=i)
				if(a[k]!=a[j])flag=0;
		if(flag)ans[++ans[0]]=i;
	}
	printf("%d\n",ans[0]);
	for(int i=1;i<=ans[0];i++)printf("%d ",ans[i]);puts("");
}