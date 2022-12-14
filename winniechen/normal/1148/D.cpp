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
int cnt,tot,n;
struct node{int x,y,idx;}a[N],b[N];
bool cmp(const node &a,const node &b){return a.x>b.x;}
bool cmp1(const node &a,const node &b){return a.x<b.x;}
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		if(x>y)b[++tot]=(node){y,x,i};
		else a[++cnt]=(node){x,y,i};
	}
	sort(a+1,a+cnt+1,cmp);sort(b+1,b+tot+1,cmp1);
	printf("%d\n",max(cnt,tot));
	if(cnt>=tot)for(int i=1;i<=cnt;i++)printf("%d ",a[i].idx);
	else for(int i=1;i<=tot;i++)printf("%d ",b[i].idx);
}