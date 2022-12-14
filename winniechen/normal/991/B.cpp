#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
using namespace std;
#define N 105
int a[N],n,sum,ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]=a[i]<<1,sum+=a[i];
	sort(a+1,a+n+1);
	for(int i=1;sum<9*n;i++){sum+=10-a[i];ans++;}
	printf("%d\n",ans);return 0;
}