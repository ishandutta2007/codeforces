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
int n,k,m,a[N];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);int ans=a[n]-a[1]+1;
	for(int i=1;i<n;i++)a[i]=a[i+1]-a[i]-1;
	sort(a+1,a+n);
	for(int i=n-1;i>n-k;i--)ans-=a[i];
	printf("%d\n",ans);
}