using namespace std;
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#define forw(i,x) for(long long i=fir[x];i;i=ne[i])
#define N 2000001
long long root1,n,m,root2;
long long ty,x,u,v,l,r,w;
long long ne[N],dis[N],fir[N],to[N],C[N],cnt,tot;
bool inq[N];
long long s;
void add(long long x,long long y,long long z)
{
	ne[++cnt]=fir[x];fir[x]=cnt;to[cnt]=y;C[cnt]=z;
}
long long L[N],R[N];
long long lc[N],rc[N],sz;
queue<long long>q;
long long build1(long long l,long long r)
{
	if(l==r) {L[l]=l;R[l]=r;return l;}
	++sz;
	long long mid=(l+r)>>1;
	long long no=sz;
	add(no,lc[no]=build1(l,mid),0);add(no,rc[no]=build1(mid+1,r),0);
	L[no]=l;R[no]=r;
	return no;
}
long long build2(long long l,long long r)
{
	if(l==r) {L[l]=l;R[l]=r;return l;}
	++sz;long long mid=(l+r)>>1;
	long long no=sz;
	add(lc[no]=build2(l,mid),no,0);add(rc[no]=build2(mid+1,r),no,0);
	L[no]=l;R[no]=r;
	return no;
}
void ADD1(long long no,long long u,long long l,long long r,long long w)
{
	if(L[no]==l&&R[no]==r) {add(u,no,w);return;}
	long long mid=(L[no]+R[no])>>1;
	if(l>mid)
	ADD1(rc[no],u,l,r,w);else
	if(r<=mid)
	ADD1(lc[no],u,l,r,w);else
	{
		ADD1(lc[no],u,l,mid,w);
		ADD1(rc[no],u,mid+1,r,w);
		return;
	}
}
void ADD2(long long no,long long u,long long l,long long r,long long w)
{
	if(L[no]==l&&R[no]==r) {add(no,u,w);return;}
	long long mid=(L[no]+R[no])>>1;
	if(l>mid)
	ADD2(rc[no],u,l,r,w);else
	if(r<=mid)
	ADD2(lc[no],u,l,r,w);else
	{
		ADD2(lc[no],u,l,mid,w);
		ADD2(rc[no],u,mid+1,r,w);
		return;
	}
}
void SPFA(long long s)
{
	q.push(s);inq[s]=1;dis[s]=0;
	while(!q.empty())
	{
		long long ind=q.front();q.pop();inq[ind]=0;
		forw(i,ind)
		{
			long long V=to[i];
			if(dis[V]>dis[ind]+C[i])
			{
				dis[V]=dis[ind]+C[i];
				if(!inq[V])
				{
					inq[V]=1;
					q.push(V);
				}
			}
		}
	}
}
main()
{
	cin>>n>>m>>s;sz=n;
	root1=build1(1,n);
	root2=build2(1,n);
	for(long long i=1;i<=m;i++)
	{
		cin>>ty;
		if(ty==1) 
		{
			cin>>u>>v>>w;add(u,v,w);
		}
		if(ty==2) 
		{
			cin>>v>>l>>r>>w;
			ADD1(root1,v,l,r,w);
		}
		if(ty==3)
		{
			cin>>v>>l>>r>>w;
			ADD2(root2,v,l,r,w);
		}
	}
	for(long long i=1;i<=2000000;i++) dis[i]=1e18;
	SPFA(s);
	for(long long i=1;i<=n;i++)
	{
		if(dis[i]<1e18) cout<<dis[i]<<' ';else cout<<"-1 ";
	}
}