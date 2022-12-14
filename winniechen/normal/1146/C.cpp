#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 105
int n,a[N],b[N],ans,sa,sb,tmp;
void solve()
{
	scanf("%d",&n);ans=0;
	for(int i=0;(1<<i)<=n&&i<9;i++)
	{
		sa=sb=0;
		for(int j=1;j<=n;j++)
			if(j>>i&1)a[++sa]=j;
			else b[++sb]=j;
		printf("%d %d ",sa,sb);
		for(int j=1;j<=sa;j++)printf("%d ",a[j]);
		for(int j=1;j<=sb;j++)printf("%d ",b[j]);
		fflush(stdout);
		scanf("%d",&tmp);ans=max(ans,tmp);
	}
	printf("-1 %d\n",ans);fflush(stdout);
}
int main(){int T;scanf("%d",&T);while(T--)solve();}