#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,m,tr[N<<2],tg[N<<2],ans=INT_MAX;
struct nd
{
	int l,r,w;
	bool operator<(const nd k)const
	{
		return w<k.w;
	}
}a[N];
void pd(int k)
{
	if(tg[k])
	{
		tr[k<<1]+=tg[k];
		tg[k<<1]+=tg[k];
		tr[k<<1|1]+=tg[k];
		tg[k<<1|1]+=tg[k];
		tg[k]=0;
	}
}
void add(int k,int l,int r,int a,int b,int v)
{
	if(l==a&&r==b)
	{
		tr[k]+=v;
		tg[k]+=v;
		return;
	}
	pd(k);
	int mid=l+r>>1;
	if(b<=mid) add(k<<1,l,mid,a,b,v);
	else if(a>mid) add(k<<1|1,mid+1,r,a,b,v);
	else add(k<<1,l,mid,a,mid,v),add(k<<1|1,mid+1,r,mid+1,b,v);
	tr[k]=min(tr[k<<1],tr[k<<1|1]);
}
int main()
{
	scanf("%d%d",&n,&m);
	m--;
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].w),a[i].r--;
	sort(a+1,a+n+1);
	for(int p=1,q=0;p<=n;p++)
	{
		while(!tr[1]&&q+1<=n)
			q++,add(1,1,m,a[q].l,a[q].r,1);
		if(!tr[1])
			break;
		ans=min(ans,a[q].w-a[p].w);
		add(1,1,m,a[p].l,a[p].r,-1);
	}
	printf("%d\n",ans);
	return 0;
}