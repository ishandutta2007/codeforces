#include<bits/stdc++.h>
using namespace std;
int cmax,dmax;
int n,cc,dd,b,p;
string type;
int val[3][2000001],l[3][2000001],r[3][2000001],ans;
void mak(int ty,int ll,int rr,int no)
{
	int mid=(ll+rr)/2;
	l[ty][no]=ll;r[ty][no]=rr;if(ll==rr) return;
	mak(ty,ll,mid,no*2);mak(ty,mid+1,rr,no*2+1);
}
void init()
{
	scanf("%d%d%d",&n,&cc,&dd);
	mak(1,1,100000,1);mak(2,1,100000,1);
}
int get(int ty,int ll,int rr,int no)
{
	int mid=(l[ty][no]+r[ty][no])/2;
	if(ll==l[ty][no]&&rr==r[ty][no]) return val[ty][no];
	if(rr<=mid) return get(ty,ll,rr,no*2);
	if(ll>mid) return get(ty,ll,rr,no*2+1);
	return max(get(ty,ll,mid,no*2),get(ty,mid+1,rr,no*2+1));
}
void add(int ty,int b,int p,int no)
{
	val[ty][no]=max(val[ty][no],b);
	if(l[ty][no]==r[ty][no]) return;
	int mid=(l[ty][no]+r[ty][no])/2;
	if(mid>=p) add(ty,b,p,no*2);
	else add(ty,b,p,no*2+1);
}
int  main()
{
	init();
	int lol;
	for(int i=1;i<=n;i++)
	{
		cin>>b>>p>>type;lol=0;
		if(type=="C")
		{
			if(p>cc) continue;cmax=max(b,cmax);if(p==cc)continue;
			int lol=get(1,1,cc-p,1);
			if(lol) ans=max(ans,lol+b);
			add(1,b,p,1);
		}
		else
		{
			lol=0;
			if(p>dd) continue;dmax=max(b,dmax);if(p==dd)continue;
			int lol=get(2,1,dd-p,1);
			if(lol) ans=max(ans,lol+b);
			add(2,b,p,1);
		}
	}
	if(dmax&&cmax) ans=max(ans,dmax+cmax);
	printf("%d",ans);
}