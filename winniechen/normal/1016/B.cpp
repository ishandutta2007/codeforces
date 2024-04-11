#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
using namespace std;
#define N 2005
char s[N],str[N];
int sum[N],n,m,Q;
bool check(int x)
{
	for(int i=1;i<=m;i++)if(s[i]!=str[x-m+i])return 0;
	return 1;
}
int main()
{
	scanf("%d%d%d",&n,&m,&Q);
	scanf("%s%s",str+1,s+1);
	for(int i=m;i<=n;i++)if(check(i))sum[i]++;
	for(int i=m;i<=n;i++)sum[i]+=sum[i-1];
	while(Q--)
	{
		int l,r;scanf("%d%d",&l,&r);
		printf("%d\n",max(sum[r]-sum[min(l+m-2,n)],0));
	}return 0;
}