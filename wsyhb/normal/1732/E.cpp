#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
const int R=5e4;
const int max_R=5e4+5;
vector<int> Div[max_R];
inline void init()
{
	for(int i=1;i<=R;++i)
		for(int j=i;j<=R;j+=i)
			Div[j].push_back(i);
}
int mn[max_R];
const int max_n=5e4+5;
int a[max_n],b[max_n],l[max_n],r[max_n],id[max_n],tot;
const int max_tot=1000+5;
long long ans[max_tot][max_R],res[max_tot];
int tag[max_tot];
inline void upd(int k)
{
	res[k]=1e18;
	for(int i=l[k];i<=r[k];++i)
	{
		if(tag[k])
			a[i]=tag[k];
		int d=gcd(a[i],b[i]);
		res[k]=min(res[k],1ll*a[i]*b[i]/d/d);
	}
	tag[k]=0;
}
int main()
{
	init();
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	for(int i=1;i<=n;++i)
		scanf("%d",b+i);
	int B=50;
	for(int i=1;i<=n;i+=B)
	{
		l[++tot]=i,r[tot]=min(i+B-1,n);
		for(int j=l[tot];j<=r[tot];++j)
			id[j]=tot;
	}
	for(int i=1;i<=tot;++i)
	{
		int l=::l[i],r=::r[i];
		for(int j=1;j<=R;++j)
		{
			mn[j]=R+1;
			ans[i][j]=1e18;
		}
		res[i]=1e18;
		for(int j=l;j<=r;++j)
		{
			int v=b[j];
			for(int d:Div[v])
				mn[d]=min(mn[d],v/d);
			int d=gcd(a[j],b[j]);
			res[i]=min(res[i],1ll*a[j]/d*b[j]/d);
		}
		for(int d=1;d<=R;++d)
		{
			if(mn[d]>R)
				continue;
			int v=mn[d];
			for(int x=d,q=1;x<=R;x+=d,++q)
				ans[i][x]=min(ans[i][x],1ll*q*v);
		}
	}
	while(q--)
	{
		int opt,l,r,x;
		scanf("%d%d%d",&opt,&l,&r);
		if(opt==1)
		{
			scanf("%d",&x);
			int p=id[l],q=id[r];
			if(tag[p])
				upd(p);
			if(tag[q])
				upd(q);
			if(p==q)
			{
				for(int i=l;i<=r;++i)
					a[i]=x;
				upd(p);
			}
			else
			{
				for(int i=l;i<=::r[p];++i)
					a[i]=x;
				upd(p);
				for(int i=::l[q];i<=r;++i)
					a[i]=x;
				upd(q);
				for(int i=p+1;i<q;++i)
				{
					tag[i]=x;
					res[i]=ans[i][x];
				}
			}
		}
		else
		{
			int p=id[l],q=id[r];
			long long ans=1e18;
			if(p==q)
			{
				for(int i=l;i<=r;++i)
				{
					if(tag[p])
						a[i]=tag[p];
					int d=gcd(a[i],b[i]);
					ans=min(ans,1ll*a[i]*b[i]/d/d);
				}
			}
			else
			{
				for(int i=l;id[i]==p;++i)
				{
					if(tag[p])
						a[i]=tag[p];
					int d=gcd(a[i],b[i]);
					ans=min(ans,1ll*a[i]*b[i]/d/d);
				}
				for(int i=r;id[i]==q;--i)
				{
					if(tag[q])
						a[i]=tag[q];
					int d=gcd(a[i],b[i]);
					ans=min(ans,1ll*a[i]*b[i]/d/d);
				}
				for(int i=p+1;i<q;++i)
					ans=min(ans,res[i]);
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
/*
9 2
4 5 13 6 17 6 1 9 5 
13 14 9 1 11 9 18 9 20 
1 3 7 11
2 3 4
---
11
*/