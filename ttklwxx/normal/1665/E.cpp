#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
struct tree
{
	int l,r,minn,mpos;
}a[800004];
int qz[200005];
void build(int l,int r,int k)
{
	a[k].l=l;
	a[k].r=r;
	a[k].minn=11211131433448687LL;
	a[k].mpos=l;
	if(l==r)return;
	build(l,(l+r)>>1,k<<1);
	build(((l+r)>>1)+1,r,k<<1|1);
}
void change(int x,int k,int y)
{
	if(a[k].l==a[k].r)
	{
		a[k].minn=y;
		return;
	}
	if(x<=a[k<<1].r)change(x,k<<1,y);
	else change(x,k<<1|1,y);
	if(a[k<<1].minn<a[k<<1|1].minn)
	{
		a[k].minn=a[k<<1].minn;
		a[k].mpos=a[k<<1].mpos;
	}
	else
	{
		a[k].minn=a[k<<1|1].minn;
		a[k].mpos=a[k<<1|1].mpos;
	}
	return;
}
struct tree query(int l,int r,int k)
{
	if(a[k].l>=l&&a[k].r<=r)return a[k];
	if(r<=a[k<<1].r)return query(l,r,k<<1);
	if(l>=a[k<<1|1].l)return query(l,r,k<<1|1);
	struct tree la=query(l,r,k<<1),ra=query(l,r,k<<1|1),ans;
	if(la.minn<ra.minn)
	{
		ans.minn=la.minn;
		ans.mpos=la.mpos;
	}
	else
	{
		ans.minn=ra.minn;
		ans.mpos=ra.mpos;
	}
	return ans;
}
int pos[35],cnt;
signed main()
{
	int t,n,q,x,y,ans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)qz[i]=read();
		build(1,n,1);
		for(int i=1;i<=n;i++)
		{
			change(i,1,qz[i]);
		}
		q=read();
		for(int i=1;i<=q;i++)
		{
			x=read();
			y=read();
			cnt=0;
			ans=11211131433448687LL;
			for(int j=1;j<=min(31LL,y-x+1);j++)
			{
				pos[++cnt]=query(x,y,1).mpos;
				change(pos[cnt],1,11211131433448687LL);
			}
			//for(int j=1;j<=cnt;j++)printf("%lld ",pos[j]);
			//printf("\n");
			for(int j=1;j<=cnt;j++)
			{
				for(int k=j+1;k<=cnt;k++)
				{
					ans=min(ans,(qz[pos[j]]|qz[pos[k]])); 
				}
			}
			printf("%lld\n",ans);
			for(int j=1;j<=cnt;j++)change(pos[j],1,qz[pos[j]]);
			//for(int j=1;j<=n;j++)printf("%lld ",query(j,j,1).minn);
			//printf("\n");
		}
	}
}