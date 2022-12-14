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
int n,a[N],ans,tmp;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	a[0]=0,a[n+1]=1001;//bool flag=0;
	for(int i=1;i<=n;i++)if(a[i]==a[i-1]+1&&a[i]==a[i+1]-1)tmp++;else ans=max(ans,tmp),tmp=0;
	ans=max(ans,tmp);
	printf("%d\n",ans);
}