#include<bits/stdc++.h>
using namespace std;
const int N=100005;
char s[N],ans[N];
struct seg
{
	int tr[N<<2],tag[N<<2],sz[N<<2];
	char c;
	void pushup(int k)
	{
		tr[k]=tr[k<<1]+tr[k<<1|1];
	}
	void pushdown(int k)
	{
		if(tag[k]==-1)
			return;
		tag[k<<1]=tag[k];
		tr[k<<1]=tag[k]*sz[k<<1];
		tag[k<<1|1]=tag[k];
		tr[k<<1|1]=tag[k]*sz[k<<1|1];
		tag[k]=-1;
	}
	void build(int k,int l,int r)
	{
		sz[k]=r-l+1,tag[k]=-1;
		if(l==r)
		{
			tr[k]=s[l]==c;
			return;
		}
		int mid=l+r>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
		pushup(k);
	}
	void update(int k,int l,int r,int a,int b,int v)
	{
		if(l==a&&r==b)
		{
			tr[k]=v*sz[k];
			tag[k]=v;
			return;
		}
		int mid=l+r>>1;
		pushdown(k);
		if(b<=mid) update(k<<1,l,mid,a,b,v);
		else if(a>mid) update(k<<1|1,mid+1,r,a,b,v);
		else update(k<<1,l,mid,a,mid,v),update(k<<1|1,mid+1,r,mid+1,b,v);
		pushup(k);
	}
	int query(int k,int l,int r,int a,int b)
	{
		if(l==a&&r==b)
		{
			return tr[k];
		}
		int mid=l+r>>1;
		pushdown(k);
		if(b<=mid) return query(k<<1,l,mid,a,b);
		else if(a>mid) return query(k<<1|1,mid+1,r,a,b);
		else return query(k<<1,l,mid,a,mid)+query(k<<1|1,mid+1,r,mid+1,b);	
	}
	void out(int k,int l,int r)
	{
		if(l==r)
		{
			if(tr[k])
				ans[l]=c;
			return;
		}
		int mid=l+r>>1;
		pushdown(k);
		out(k<<1,l,mid);
		out(k<<1|1,mid+1,r);
	}
}a[30];
int t[30],n,m,l,r;
int main()
{
#ifdef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=0;i<26;i++)
	{
		a[i].c='a'+i;
		a[i].build(1,1,n);
	}
	while(m--)
	{
		scanf("%d%d",&l,&r);
		int flag=-1;
		for(int i=0;i<26;i++)
		{
			t[i]=a[i].query(1,1,n,l,r);
			if(t[i]&1)
			{
				if(flag==-1)
					flag=i;
				else
				{
					flag=30;
					break;
				}
			}
		}
		if(flag==30)
			continue;
		for(int i=0;i<26;i++)
			a[i].update(1,1,n,l,r,0);
		for(int i=0;i<26;i++)
		{
			t[i]/=2;
			if(t[i])
			{
				a[i].update(1,1,n,l,l+t[i]-1,1);
				a[i].update(1,1,n,r-t[i]+1,r,1);
				l+=t[i],r-=t[i];
			}
		}
		if(flag!=-1)
			a[flag].update(1,1,n,l,r,1);
	}
	for(int i=0;i<26;i++)
		a[i].out(1,1,n);
	printf("%s\n",ans+1);
	return 0;
}