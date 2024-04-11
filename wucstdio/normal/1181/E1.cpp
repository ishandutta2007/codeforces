#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
struct Castle
{
	int l1,r1;
	int l2,r2;
}a[1005];
int n;
bool cmpx(Castle a,Castle b)
{
	return a.l1<b.l1||(a.l1==b.l1&&a.r1<b.r1);
}
bool cmpy(Castle a,Castle b)
{
	return a.l2<b.l2||(a.l2==b.l2&&a.r2<b.r2);
}
bool solve(int l,int r,bool flag)
{
	if(l==r)return 1;
	if(flag)
	{
		sort(a+l,a+r+1,cmpx);
		int maxr=0,nowl=l;
		for(int i=l;i<=r;i++)
		{
			if(i!=l&&maxr<=a[i].l1)
			{
				if(!solve(nowl,i-1,flag^1))return 0;
				nowl=i;
			}
			maxr=max(maxr,a[i].r1);
		}
		if(nowl==l)return 0;
		if(!solve(nowl,r,flag^1))return 0;
		return 1;
	}
	else
	{
		sort(a+l,a+r+1,cmpy);
		int maxr=0,nowl=l;
		for(int i=l;i<=r;i++)
		{
			if(i!=l&&maxr<=a[i].l2)
			{
				if(!solve(nowl,i-1,flag^1))return 0;
				nowl=i;
			}
			maxr=max(maxr,a[i].r2);
		}
		if(nowl==l)return 0;
		if(!solve(nowl,r,flag^1))return 0;
		return 1;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d%d",&a[i].l1,&a[i].l2,&a[i].r1,&a[i].r2);
	if(solve(1,n,1))printf("YES\n");
	else if(solve(1,n,0))printf("YES\n");
	else printf("NO\n");
	return 0;
}