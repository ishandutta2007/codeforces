#include <bits/stdc++.h>
#define Maxn 200007
using namespace std;
int n,m,cnt1,cnt2,v;
int a[Maxn],b[Maxn];
int q;
int get1(int x)
{
	if (a[1]>x) return 0;
	int lx=1,rx=cnt1;
	while (rx-lx>1)
	{
		int mid=(lx+rx)/2;
		if (a[mid]<=x) lx=mid; else rx=mid;
	}
	if (a[rx]<=x) return rx; else return lx;
}
int get2(int x)
{
	if (b[1]>x) return 0;
	int lx=1,rx=cnt2;
	while (rx-lx>1)
	{
		int mid=(lx+rx)/2;
		if (b[mid]<=x) lx=mid; else rx=mid;
	}
	if (b[rx]<=x) return rx; else return lx;
}
int main()
{
	scanf("%d%d%d%d%d",&n,&m,&cnt1,&cnt2,&v);
	for (int i=1;i<=cnt1;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=cnt2;i++)
		scanf("%d",&b[i]);
	scanf("%d",&q);
	while (q--)
	{
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&y1,&x1,&y2,&x2);
		if (y1==y2) printf("%d\n",abs(x1-x2));
		else
		{
			int ans=1000000000;
			int pos1=get1(x1);
			if (pos1!=0) ans=min(ans,abs(y1-y2)+abs(x1-a[pos1])+abs(x2-a[pos1]));
			if (pos1!=cnt1) ans=min(ans,abs(y1-y2)+abs(x1-a[pos1+1])+abs(x2-a[pos1+1]));
			int pos2=get2(x1);
			if (pos2!=0) ans=min(ans,((abs(y1-y2)+v-1)/v)+abs(x1-b[pos2])+abs(x2-b[pos2]));
			if (pos2!=cnt2) ans=min(ans,((abs(y1-y2)+v-1)/v)+abs(x1-b[pos2+1])+abs(x2-b[pos2+1]));
			printf("%d\n",ans);
		}
	}
	return 0;
}