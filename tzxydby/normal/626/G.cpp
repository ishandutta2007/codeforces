#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,p[N],a[N],s[N],q,t;
double ans;
struct seg1
{
	double tr[N<<2];
	int f[N<<2];
	void pushup(int k)
	{
		if(tr[k<<1]>tr[k<<1|1])
		{
			tr[k]=tr[k<<1];
			f[k]=f[k<<1];
		}
		else
		{
			tr[k]=tr[k<<1|1];
			f[k]=f[k<<1|1];
		}
	}
	void build(int k,int l,int r)
	{
		if(l==r)
		{
			tr[k]=1.0*p[l]/(s[l]+1);
			f[k]=l;
			return;
		}
		int mid=l+r>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
		pushup(k);
	}
	void upd(int k,int l,int r,int x)
	{
		if(l==r)
		{
			if(a[x]==s[x])
				tr[k]=0;
			else
				tr[k]=(1.0*(a[x]+1)/(a[x]+s[x]+1)-1.0*a[x]/(a[x]+s[x]))*p[x];
			return;
		}	
		int mid=l+r>>1;
		if(x<=mid) upd(k<<1,l,mid,x);
		else upd(k<<1|1,mid+1,r,x);
		pushup(k);
	}
}t1;
struct seg2
{
	double tr[N<<2];
	int f[N<<2];
	void pushup(int k)
	{
		if(tr[k<<1]<tr[k<<1|1])
		{
			tr[k]=tr[k<<1];
			f[k]=f[k<<1];
		}
		else
		{
			tr[k]=tr[k<<1|1];
			f[k]=f[k<<1|1];
		}
	}
	void build(int k,int l,int r)
	{
		if(l==r)
		{
			tr[k]=1e9;
			f[k]=l;
			return;
		}
		int mid=l+r>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
		pushup(k);
	}
	void upd(int k,int l,int r,int x)
	{
		if(l==r)
		{
			if(a[x]==0)
				tr[k]=1e9;
			else
				tr[k]=(1.0*a[x]/(a[x]+s[x])-1.0*(a[x]-1)/(a[x]+s[x]-1))*p[x];
			return;
		}	
		int mid=l+r>>1;
		if(x<=mid) upd(k<<1,l,mid,x);
		else upd(k<<1|1,mid+1,r,x);
		pushup(k);
	}
}t2;
int add()
{
	int x=t1.f[1];
	if(a[x]==s[x])
		return 0;
	ans+=t1.tr[1];
	a[x]++;
	t1.upd(1,1,n,x);
	t2.upd(1,1,n,x);
	t--;
	return 1;
}
void del(int x)
{
	t++;
	ans-=1.0*a[x]/(a[x]+s[x])*p[x];
	a[x]--;
	ans+=1.0*a[x]/(a[x]+s[x])*p[x];
	t1.upd(1,1,n,x);
	t2.upd(1,1,n,x);
}
int main()
{
	scanf("%d%d%d",&n,&t,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&s[i]);
	t1.build(1,1,n);
	t2.build(1,1,n);
	while(t)
		if(!add())
			break;
	while(q--)
	{
		int ty,r;
		scanf("%d%d",&ty,&r);
		if(ty==1)
		{
			ans-=1.0*a[r]/(a[r]+s[r])*p[r];
			s[r]++;
			ans+=1.0*a[r]/(a[r]+s[r])*p[r];
			t1.upd(1,1,n,r);
			t2.upd(1,1,n,r);
			if(t)
				add();
			else if(a[r])
			{
				int x=t2.f[1];
				del(x);
				add();
			}
		}
		else
		{
			ans-=1.0*a[r]/(a[r]+s[r])*p[r];
			s[r]--;
			ans+=1.0*a[r]/(a[r]+s[r])*p[r];
			t1.upd(1,1,n,r);
			t2.upd(1,1,n,r);
			if(a[r]>s[r])
			{
				del(r);
				add();
			}
			else
			{
				int x=t2.f[1];
				del(x);
				add();
			}
		}
		printf("%.9lf\n",ans);
	}
	return 0;
}