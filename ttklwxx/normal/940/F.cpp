#include <iostream>
#include <cstdio>
#include <algorithm>
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
const int B=2154;
 
struct Query
{
	int l,r,t,id;
	bool operator<(Query& y)
	{
		return l/B==y.l/B?(r/B==y.r/B?t<y.t:r<y.r):l<y.l;
	}
} q[100010];
 
struct Change
{
	int p,x;
} c[100010];
 
void add(int x);
void del(int x);
void modify(int ti,int qu);
 
int n,m,a[100010],b[200010],cnt[200010],tot[100010],qcnt,ccnt,qaq,now,ans[100010];
 
int main()
{
	int i,j,l=1,r=0,type;
	
	n=read();
	m=read();
	
	for (i=1;i<=n;++i)
	{
		b[qaq++]=a[i]=read();
	}
	
	for (i=0;i<m;++i)
	{
		type=read();
		if (type==1)
		{
			q[++qcnt].l=read();
			q[qcnt].r=read();
			q[qcnt].t=ccnt;
			q[qcnt].id=qcnt;
		}
		else
		{
			c[++ccnt].p=read();
			b[qaq++]=c[ccnt].x=read();
		}
	}
	
	sort(b,b+qaq);
	qaq=unique(b,b+qaq)-b;
	
	for (i=1;i<=n;++i)
	{
		a[i]=lower_bound(b,b+qaq,a[i])-b;
	}
	
	for (i=1;i<=ccnt;++i)
	{
		c[i].x=lower_bound(b,b+qaq,c[i].x)-b;
	}
	
	sort(q+1,q+qcnt+1);
	
	for (i=1;i<=qcnt;++i)
	{
		while (l>q[i].l)
		{
			add(a[--l]);
		}
		while (r<q[i].r)
		{
			add(a[++r]);
		}
		while (l<q[i].l)
		{
			del(a[l++]);
		}
		while (r>q[i].r)
		{
			del(a[r--]);
		}
		while (now<q[i].t)
		{
			modify(++now,i);
		}
		while (now>q[i].t)
		{
			modify(now--,i);
		}
		for (ans[q[i].id]=1;tot[ans[q[i].id]]>0;++ans[q[i].id]);
	}
	
	for (i=1;i<=qcnt;++i)
	{
		printf("%d\n",ans[i]);
		putchar('\n');
	}
	
	return 0;
}
 
void add(int x)
{
	--tot[cnt[x]];
	++tot[++cnt[x]];
}
 
void del(int x)
{
	--tot[cnt[x]];
	++tot[--cnt[x]];
}
 
void modify(int ti,int qu)
{
	if (c[ti].p>=q[qu].l&&c[ti].p<=q[qu].r)
	{
		del(a[c[ti].p]);
		add(c[ti].x);
	}
	swap(c[ti].x,a[c[ti].p]);
}