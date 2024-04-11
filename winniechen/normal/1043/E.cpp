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
struct node
{
	int x,y,idx;
	bool operator < (const node &a) const {return y-x<a.y-a.x;}
}a[N],b[N];
int n,m;ll sum1[N],sum2[N],ans[N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].y),a[i].idx=i;
	for(int i=1;i<=m;i++)scanf("%d%d",&b[i].x,&b[i].y);
	for(int i=1,t;i<=m;i++)
	{
		t=min(a[b[i].x].x+a[b[i].y].y,a[b[i].x].y+a[b[i].y].x);
		ans[b[i].x]-=t,ans[b[i].y]-=t;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum1[i]=sum1[i-1]+a[i].x,sum2[i]=sum2[i-1]+a[i].y;
	for(int i=1;i<=n;i++)
	{
		ans[a[i].idx]+=(ll)a[i].x*(i-1)+sum2[i-1];
		ans[a[i].idx]+=(ll)a[i].y*(n-i)+sum1[n]-sum1[i];
	}
	for(int i=1;i<=n;i++)printf("%lld ",ans[i]);puts("");
}