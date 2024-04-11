#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
using namespace std;
#define N 1005
int a[N],tmp,n;
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y,z,w;i<=n;i++)scanf("%d%d%d%d",&x,&y,&z,&w),a[i]=x+y+z+w;tmp=a[1];
	sort(a+1,a+n+1);
	printf("%d\n",n-(upper_bound(a+1,a+n+1,tmp)-a)+2);
}