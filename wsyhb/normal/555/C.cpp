#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int N=12*1024*1024;
int ls[N],rs[N],v[N],lazy[N];
void putdown(int p)
{
	v[ls[p]]=max(v[ls[p]],lazy[p]);
	lazy[ls[p]]=max(lazy[ls[p]],lazy[p]);
	v[rs[p]]=max(v[rs[p]],lazy[p]);
	lazy[rs[p]]=max(lazy[rs[p]],lazy[p]);
	lazy[p]=0;
}
int tot=2;
void modify(int p,int x,int y,int l,int r,int s)
{
	if(l<=x&&y<=r)
	{
		v[p]=max(v[p],s);
		lazy[p]=max(lazy[p],s);
		return;
	}
	if(lazy[p])
	{
		if(!ls[p]) ls[p]=++tot;
		if(!rs[p]) rs[p]=++tot;
		putdown(p);
	}
	int mid=(x+y)>>1;
	if(l<=mid&&r>0)
	{
		if(!ls[p]) ls[p]=++tot;
		modify(ls[p],x,mid,l,r,s);
	}
	if(r>mid)
	{
		if(!rs[p]) rs[p]=++tot;
		modify(rs[p],mid+1,y,l,r,s);
	}
}
int getmax(int p,int x,int y,int k)
{
	if(x==y) return v[p];
	int ans=0,mid=(x+y)>>1;
	if(lazy[p])
	{
		if(!ls[p]) ls[p]=++tot;
		if(!rs[p]) rs[p]=++tot;
		putdown(p);
	}
	if(k<=mid)
	{
		if(!ls[p]) ls[p]=++tot;
		ans=max(ans,getmax(ls[p],x,mid,k));
	}
	else
	{
		if(!rs[p]) rs[p]=++tot;
		ans=max(ans,getmax(rs[p],mid+1,y,k));
	}
	
	return ans;
}
typedef pair<int,int> P;
map<P,bool> M;
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<12*1024*1024;i++) v[i]=1;
	while(q--)
	{
		char s[2];
		int x,y;
		scanf("%d%d%s",&y,&x,s);
		if(M[P(x,y)])
		{
			printf("0\n");
			continue;
		}
		M[P(x,y)]=true;
		//p=1:L p=2:U
		if(s[0]=='L')
		{
			int q=getmax(1,1,n,x);
			modify(2,1,n,q,y-1,x+1);
			printf("%d\n",y-q+1);
		}
		else
		{
			int q=getmax(2,1,n,y);
			modify(1,1,n,q,x-1,y+1);
			printf("%d\n",x-q+1);
		}
	}
	return 0;
}