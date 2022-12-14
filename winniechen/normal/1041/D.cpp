#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
#define N 200005
struct node{int l,r;}a[N];
int h,n,H,sum,ans;
bool cmp(const node &a,const node &b){return a.l<b.l;}
int main()
{
	scanf("%d%d",&n,&H);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].l,&a[i].r);sort(a+1,a+n+1,cmp);h=1;ans=a[1].r-a[1].l+H;
	for(int i=2;i<=n;i++)
	{
		sum+=max(a[i].l-a[i-1].r,0);
		while(h<i&&sum>=H)sum-=max(a[h+1].l-a[h].r,0),h++;
		// printf("%d %d %d\n",sum,a[i].r,a[h].l);
		ans=max(ans,a[i].r-a[h].l+H-sum);
	}printf("%d\n",ans);
}