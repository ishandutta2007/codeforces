#include<bits/stdc++.h>
using namespace std;
const int N=100005,inf=2e9,n=100000;
struct seg
{
	int fl[N<<2],m1[N<<2],m2[N<<2],sz[N<<2],tg[N<<2],c[N<<2];
	long long tr[N<<2];
	void build(int k,int l,int r)
	{
		fl[k]=0;
		m1[k]=inf;
		m2[k]=0;
		sz[k]=r-l+1;
		tr[k]=1ll*inf*sz[k];
		tg[k]=0;
		c[k]=r-l+1;
		if(l==r)
			return;
		int mid=l+r>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
	}
	void pu(int k)
	{
		if(m1[k<<1]==m1[k<<1|1])
		{
			m1[k]=m1[k<<1];
			m2[k]=max(m2[k<<1],m2[k<<1|1]);
			c[k]=c[k<<1]+c[k<<1|1];
		}
		else if(m1[k<<1]>m1[k<<1|1])
		{
			m1[k]=m1[k<<1];
			m2[k]=max(m2[k<<1],m1[k<<1|1]);
			c[k]=c[k<<1];
		}
		else
		{
			m1[k]=m1[k<<1|1];
			m2[k]=max(m1[k<<1],m2[k<<1|1]);
			c[k]=c[k<<1|1];
		}
		tr[k]=tr[k<<1]+tr[k<<1|1];
		fl[k]=(fl[k<<1]&fl[k<<1|1]);
	}
	void pd(int k)
	{
		if(tg[k])
		{
			if(m1[k<<1]==m1[k<<1|1])
			{
				m1[k<<1]+=tg[k];
				tg[k<<1]+=tg[k];
				tr[k<<1]+=1ll*tg[k]*c[k<<1];
				fl[k<<1]=1;
				m1[k<<1|1]+=tg[k];
				tg[k<<1|1]+=tg[k];
				tr[k<<1|1]+=1ll*tg[k]*c[k<<1|1];
				fl[k<<1|1]=1;
			}
			else if(m1[k<<1]>m1[k<<1|1])
			{
				m1[k<<1]+=tg[k];
				tg[k<<1]+=tg[k];
				tr[k<<1]+=1ll*tg[k]*c[k<<1];
				fl[k<<1]=1;
			}
			else
			{
				m1[k<<1|1]+=tg[k];
				tg[k<<1|1]+=tg[k];
				tr[k<<1|1]+=1ll*tg[k]*c[k<<1|1];
				fl[k<<1|1]=1;
			}
			tg[k]=0;
		}
	}
	void upd(int k,int l,int r,int a,int b,int v)
	{
		if(v>=m1[k])
			return;
		if(l==a&&r==b)
		{
			if(v>m2[k])
			{
				int d=v-m1[k];
				m1[k]+=d;
				tg[k]+=d;
				tr[k]+=1ll*d*c[k];
				fl[k]=1;
				return;
			}
			pd(k);
			int mid=l+r>>1;
			upd(k<<1,l,mid,a,mid,v);
			upd(k<<1|1,mid+1,r,mid+1,b,v);
			pu(k);
		}
		pd(k);
		int mid=l+r>>1;
		if(b<=mid) upd(k<<1,l,mid,a,b,v);
		else if(a>mid) upd(k<<1|1,mid+1,r,a,b,v);
		else upd(k<<1,l,mid,a,mid,v),upd(k<<1|1,mid+1,r,mid+1,b,v);
		pu(k);
	}
}t1,t2;
int q;
long long ask(int k,int l,int r,int a,int b)
{
	if(t1.tr[k]==1ll*inf*t1.sz[k]||t2.tr[k]==1ll*inf*t2.sz[k])
		return 0;
	if(l==a&&r==b)
	{
		if(t1.fl[k]&&t2.fl[k])
			return t1.tr[k]+t2.tr[k];
		t1.pd(k),t2.pd(k);
		int mid=l+r>>1;
		return ask(k<<1,l,mid,a,mid)+ask(k<<1|1,mid+1,r,mid+1,b);
	}
	t1.pd(k),t2.pd(k);
	int mid=l+r>>1;
	if(b<=mid) return ask(k<<1,l,mid,a,b);
	else if(a>mid) return ask(k<<1|1,mid+1,r,a,b);
	else return ask(k<<1,l,mid,a,mid)+ask(k<<1|1,mid+1,r,mid+1,b);
}
int main()
{
	t1.build(1,1,n);
	t2.build(1,1,n);
	scanf("%d",&q);
	while(q--)
	{
		int t,l,r,v;
		scanf("%d%d%d",&t,&l,&r);
		r--;
		if(t==1)
		{
			scanf("%d",&v);
			if(v>0)
				t1.upd(1,1,n,l,r,v);
			else
				t2.upd(1,1,n,l,r,-v);
		}
		else
			printf("%lld\n",ask(1,1,n,l,r));
	}
	return 0;
}