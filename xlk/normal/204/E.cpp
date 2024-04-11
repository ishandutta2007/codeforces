#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int p[200020],sa[200020],c[200020],h[200020],d;
int n,l,k,z[200020],len[200020];
long long ans[100020];
namespace SA
{
	int wa[200020],wb[200020],wv[200020],w[200020];
	int r[200020];
	char s[200020];
	int cmp(int *r,int a,int b,int l)
	{
		return r[a]==r[b]&&r[a+l]==r[b+l];
	}
	void da(int *r,int *sa,int n,int m)
	{
		int i,j,p,*x=wa,*y=wb,*t;
		for(i=0;i<m;i++)
			w[i]=0;
		for(i=0;i<n;i++)
			w[x[i]=r[i]]++;
		for(i=1;i<m;i++)
			w[i]+=w[i-1];
		for(i=n-1;i>=0;i--)
			sa[--w[x[i]]]=i;
		for(j=1,p=1;p<n;j*=2,m=p)
		{
			for(p=0,i=n-j;i<n;i++)
				y[p++]=i;
			for(i=0;i<n;i++)
				if(sa[i]>=j)
					y[p++]=sa[i]-j;
			for(i=0;i<n;i++)
				wv[i]=x[y[i]];
			for(i=0;i<m;i++)
				w[i]=0;
			for(i=0;i<n;i++)
				w[wv[i]]++;
			for(i=1;i<m;i++)
				w[i]+=w[i-1];
			for(i=n-1;i>=0;i--)
				sa[--w[wv[i]]]=y[i];
			for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
				x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
		}
		return;
	}
	int rk[200020];
	void cal(int *r,int *sa,int n)
	{
		int i,j,k=0;
		for(i=1;i<=n;i++)
			rk[sa[i]]=i;
		for(i=0;i<n;h[rk[i++]]=k)
			for(k?k--:0,j=sa[rk[i]-1];r[i+k]==r[j+k];)
				k++;
		return;
	}
	void input()
	{
		scanf("%d %d",&n,&k);
		for(int i=0;i<n;i++)
		{
			scanf("%s",s+l);
			int st=l;
			l+=strlen(s+l);
			for(int j=st;s[j];j++)
				r[j]=s[j],p[j]=i,len[j]=l;
			p[l]=-1;
			r[l++]=i+200;
		}
		da(r,sa,l+1,n+300);
		cal(r,sa,l);
	}
}
namespace Q
{
	int q[200020],b,f;
	void push(int x)
	{
		while(b<f&&h[x]<=h[q[f-1]])
			f--;
		q[f++]=x;
	}
	void pop(int x)
	{
		while(b<f&&q[b]<=x)
			b++;
	}
//	void print()
//	{
//		if(b==f)
//			printf("empty");
//		for(int i=b;i<f;i++)
//			printf("%d(%d) ",q[i],h[q[i]]);
//		puts("");
//	}
	int min()
	{
//		print();
		if(b<f)
			return h[q[b]];
		else
			return 1<<30;
	}
}
namespace Z
{
	int f[200020];
	struct E
	{
		int x,y,z;
	}e[400020],*ee=e;
	bool operator<(const E&a,const E&b)
	{
		return a.z>b.z;
	}
	void add(int x,int y,int z)
	{
		cerr << "ADD " << x << ' ' << y << ' ' << z << endl;
		ee->x=x;
		ee->y=y;
		ee->z=z;
		ee++;
	}
	int F(int x)
	{
		return f[x]!=x?f[x]=F(f[x]):x;
	}
	void work()
	{
		sort(e,ee);
		for(int i=1;i<=l+1;i++)
			f[i]=i;
		for(E *i=e;i!=ee;i++)
			for(int j=F(i->x);j<i->y;j=F(j))
			{
				z[j]=i->z;
				f[j]=j+1;
			}
		for(int i=1;i<=l-n;i++)
			ans[p[sa[i]]]+=min(z[i],len[sa[i]]-sa[i]);
	}
}
int main()
{
//	freopen("c.in","r",stdin);
	SA::input();
	if(k>n)
		goto end;
//	for(int i=1;i<=l;i++)
//		printf("%d ",sa[i]+1);
//	puts("");
//	for(int i=1;i<=l;i++)
//		printf("%d ",p[sa[i]]);
//	puts("");
//	for(int i=1;i<=l;i++)
//		printf("%d ",h[i]);
//	puts("");
	int bb,ff;
	bb=ff=1;
	while(d<k&&p[sa[ff]]!=-1)
	{
		if(!c[p[sa[ff]]])
			d++;
		c[p[sa[ff]]]++;
		if(ff>bb)
			Q::push(ff);
		ff++;
	}
	Z::add(bb,ff,Q::min());
	while(1)
	{
		while(c[p[sa[bb]]]<2&&d<=k&&p[sa[ff]]!=-1)
		{
			if(!c[p[sa[ff]]])
				d++;
			c[p[sa[ff]]]++;
			if(ff>bb)
				Q::push(ff);
			ff++;
			Z::add(bb,ff,Q::min());
		}
		if(c[p[sa[bb]]]<2&&d<=k)
			break;
		while(c[p[sa[bb]]]>1||d>k)
		{
			c[p[sa[bb]]]--;
			if(!c[p[sa[bb]]])
				d--;
			bb++;
			Q::pop(bb);
			Z::add(bb,ff,Q::min());
		}
	}
	Z::work();
	end:
	for(int i=0;i<n;i++)
		printf("%I64d ",ans[i]);
	return 0;
}