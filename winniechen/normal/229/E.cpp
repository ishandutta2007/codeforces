#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
#define N 1005
struct node
{
	int val,idx,rnk;
}a[N];
int n,m,num[N],vis[N],tot[N];
double f[N];
bool cmp(const node &a,const node &b)
{
	return a.val>b.val;
}
bool used[N];
int main()
{
	//freopen("gift.in","r",stdin);
	//freopen("gift.out","w",stdout);
	scanf("%d%d",&n,&m);
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&num[i]);
		for(int j=1;j<=num[i];j++)
		{
			scanf("%d",&a[++cnt].val);
			a[cnt].idx=i;
		}
	}
	sort(a+1,a+cnt+1,cmp);
	int r=0;
	for(int i=1;i<=cnt;i++)
	{
		if(a[i].val!=a[i-1].val)r++;
		a[i].rnk=r;
		tot[r]++;
	}
	f[0]=1;
	int o=0;
	for(int i=1;i<=n;i++)
	{
		if(i+tot[a[i].rnk]-1>n&&a[i].val!=a[i-1].val)
		{
			o=i;
			for(int j=i;j<=cnt;j++)
			{
				for(int k=n;k>=i;k--)
				{
					f[k]+=(f[k-1]*(vis[a[j].idx]+1)/(num[a[j].idx]-vis[a[j].idx]));
				}
				if(a[j].val!=a[j+1].val)break;
			}
			break;
		}
		vis[a[i].idx]++;
		f[i]=f[i-1]*vis[a[i].idx]/(num[a[i].idx]-vis[a[i].idx]+1.0);
	}
	if(!o)
	{
		printf("%.9lf\n",f[n]);
	}else
	{
		for(int i=1;i<=n-o+1;i++)
		{
			f[n]=(f[n]*i/(tot[a[o].rnk]-i+1));
		}
		printf("%.9lf\n",f[n]);
	}
	return 0;
}