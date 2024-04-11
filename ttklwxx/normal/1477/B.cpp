#include<iostream>
#include<cstdio>
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
char s[300005],f[300005];
int tl[300005],tr[300005];
struct tree
{
	int l,r,s,laz;
}a[800004];
void build(int l,int r,int k)
{
	a[k].l=l;
	a[k].r=r;
	a[k].laz=0;
	if(l==r)
	{
		a[k].s=f[l]-'0';
		return;
	}
	build(l,(l+r)>>1,k<<1);
	build(((l+r)>>1)+1,r,k<<1|1);
	a[k].s=a[k<<1].s+a[k<<1|1].s;
}
void change(int l,int r,int k,int x)
{
	if(a[k].l>r||a[k].r<l)return;
	if(a[k].l>=l&&a[k].r<=r)
	{
		if(x==0)
		{
			a[k].laz=1;
			a[k].s=0;
		}
		else
		{
			a[k].laz=2;
			a[k].s=a[k].r-a[k].l+1;
		}
		return;
	}
	change(l,r,k<<1,x);
	change(l,r,k<<1|1,x);
	a[k].s=a[k<<1].s+a[k<<1|1].s;
}
int findhe(int l,int r,int k)
{
	if(a[k].l>r||a[k].r<l)return 0;
	if(a[k].l>=l&&a[k].r<=r)return a[k].s;
	if(a[k].laz==1)
	{
		a[k<<1].s=0;
		a[k<<1|1].s=0;
		a[k<<1].laz=1;
		a[k<<1|1].laz=1;
	}
	else if(a[k].laz==2)
	{
		a[k<<1].s=a[k<<1].r-a[k<<1].l+1;
		a[k<<1|1].s=a[k<<1|1].r-a[k<<1|1].l+1;
		a[k<<1].laz=2;
		a[k<<1|1].laz=2;
	}
	a[k].laz=0;
	return findhe(l,r,k<<1)+findhe(l,r,k<<1|1);
}
int main()
{
	int t,n,q,x;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		q=read();
		scanf("%s%s",s+1,f+1);
		for(int i=1;i<=q;i++)
		{
			tl[i]=read();
			tr[i]=read();
		}
		flag=false;
		build(1,n,1);
		for(int i=q;i>=1;i--)
		{
			x=findhe(tl[i],tr[i],1);
			if((tr[i]-tl[i]+1)==2*x)
			{
				flag=true;
				break;
			}
			if(tr[i]-tl[i]+1>2*x)
			{
				change(tl[i],tr[i],1,0);
			}
			else
			{
				change(tl[i],tr[i],1,1);
			}
		}
		if(flag==true)
		{
			printf("NO\n");
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(findhe(i,i,1)!=s[i]-'0')
			{
				flag=true;
				break;
			}
		}
		if(flag==true)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}