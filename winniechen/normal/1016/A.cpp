#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
using namespace std;
#define N 200005
int n,a[N],m;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int last=m;
	for(int i=1;i<=n;i++)
	{
		int ans=0;
		if(a[i]>=last)
		{
			a[i]-=last,ans++;
			ans+=a[i]/m;last=m-a[i]%m;
		}else last-=a[i];
		printf("%d\n",ans);
	}
}