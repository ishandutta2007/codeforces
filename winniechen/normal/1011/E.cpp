#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
using namespace std;
#define N 100005
int f[N],a[N],n,k,ans[N],b[N];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]%=k,a[i]=__gcd(a[i],__gcd(a[i-1],k)),b[a[i]]=1;ans[++ans[0]]=0;
	for(int i=1;i<k;i++)
	{
		for(int j=1;j*j<=i;j++)
		{
			if(i%j==0)
			{
				if(b[j]||b[i/j]){ans[++ans[0]]=i;break;}
			}
		}
	}
	printf("%d\n",ans[0]);
	for(int i=1;i<=ans[0];i++)printf("%d ",ans[i]);puts("");return 0;
}