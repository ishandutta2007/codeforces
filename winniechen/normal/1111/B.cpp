#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 100005
#define ll long long
int a[N],n,m,k;ll s[N];long double ans;
int main()
{
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);sort(a+1,a+n+1);
	for(int i=n;i;i--)s[i]=a[i]+s[i+1];
	for(int i=1;i<=n&&i<=m+1;i++)
	{
		long double tmp=min((ll)m-i+1,(ll)k*(n-i+1));
		ans=max(ans,(tmp+s[i])/(n-i+1));
	}
	printf("%.7lf\n",(double)ans);
}