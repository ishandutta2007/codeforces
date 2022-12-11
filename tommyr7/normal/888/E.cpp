#include <bits/stdc++.h>
#define Maxn 37
using namespace std;
int n,m,a[Maxn];
int x[300007],y[300007],cnt1=0,cnt2=0;
map<int,bool> mp1,mp2;
void dfs1(int now,int lx)
{
	if (lx>n/2)
	{
		if (!mp1[now])
		{
			mp1[now]=true;
			x[++cnt1]=now;
		}
	} else
	{
		dfs1(now,lx+1);
		dfs1((now+a[lx])%m,lx+1);
	}
}
void dfs2(int now,int lx)
{
	if (lx>n)
	{
		if (!mp2[now])
		{
			mp2[now]=true;
			y[++cnt2]=now;
		} 
	} else
	{
		dfs2(now,lx+1);
		dfs2((now+a[lx])%m,lx+1);
	}
}
int get(int x)
{
	int lx=1,rx=cnt2;
	while (rx-lx>1)
	{
		int mid=(lx+rx)/2;
		if (y[mid]>x) rx=mid; else lx=mid;
	}
	if (y[rx]<=x) return y[rx]; else return y[lx];
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	mp1.clear();mp2.clear();
	dfs1(0,1);
	dfs2(0,n/2+1);
	sort(x+1,x+cnt1+1);
	sort(y+1,y+cnt2+1);
	int ans=0;
	for (int i=1;i<=cnt1;i++)
	{
		ans=max(ans,(x[i]+get(m-1-x[i]))%m);
		ans=max(ans,(x[i]+get(2*m-1-x[i]))%m);
	}
	printf("%d\n",ans);
	return 0;
}