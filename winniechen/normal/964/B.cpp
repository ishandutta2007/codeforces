#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
#define N 1005
int t[N],ans;
int main()
{
	int T,a,b,c,n;
	scanf("%d%d%d%d%d",&n,&a,&b,&c,&T);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t[i]);
		if(c>b)
		{
			ans+=a+(T-t[i])*(c-b);
		}else
		{
			ans+=a;
		}
	}
	printf("%d\n",ans);
	return 0;
}