#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
using namespace std;
#define ll long long
#define N 300050
struct node
{
	int l,r,idx;
}a[N];
int n;
bool cmp(const node &x,const node &y)
{
	if(x.l==y.l) return x.r>y.r;
	return x.l<y.l;
}
int main()
{
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].l,&a[i].r);
		a[i].idx=i;
	}
	sort(a+1,a+n+1,cmp);
	int maxx=1;
	for(i=2;i<=n;i++)
	{
		if(a[i].r<=a[maxx].r)
		{
			printf("%d %d\n",a[i].idx,a[maxx].idx);
			return 0;
		}
		if(a[i].r>a[maxx].r) maxx=i;
	}
	puts("-1 -1");
	return 0;
}