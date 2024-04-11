#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 300005
#define ll long long
int a[N],b[N],f[N],g[N],n,k;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
	{
		f[i]=max(0ll,a[i]-((ll)b[i]*k-f[i-1]));
		g[i]=max(0ll,b[i]-((ll)a[i]*k-g[i-1]));
		if(f[i]>k||g[i]>k)return puts("NO"),0;
	}puts("YES");
}