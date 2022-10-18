#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define ls (u<<1)
#define rs (u<<1|1)
#define N 200005
struct Node
{
	int tag;
};
Node t[N*4];
int a[N];
void build(int u,int l,int r)
{
	if(l==r)
	{
		t[u].tag=a[l];
		return ;
	}
	int mid=(l+r)/2;
	build(ls,l,mid);
	build(rs,mid+1,r);
}
void upd1(int u,int l,int r,int p,int x)
{
	if(l==r)
	{
		t[u].tag=x;
		return ;
	}
	if(t[u].tag)
	{
		t[ls].tag=max(t[ls].tag,t[u].tag);
		t[rs].tag=max(t[rs].tag,t[u].tag);
		t[u].tag=0;
	}
	int mid=(l+r)/2;
	if(p<=mid) upd1(ls,l,mid,p,x);
	else upd1(rs,mid+1,r,p,x);
}
int query(int u,int l,int r,int p)
{
	if(l==r)
	{
		return t[u].tag;
	}
	if(t[u].tag)
	{
		t[ls].tag=max(t[ls].tag,t[u].tag);
		t[rs].tag=max(t[rs].tag,t[u].tag);
		t[u].tag=0;
	}
	int mid=(l+r)/2;
	if(p<=mid) return query(ls,l,mid,p);
	else return query(rs,mid+1,r,p);
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	build(1,1,n);
	int m=read();
	int opt,p,x;
	for(int i=1;i<=m;i++)
	{
		opt=read();
		if(opt==1)
		{
			p=read(),x=read();
			upd1(1,1,n,p,x);
		}
		else
		{
			x=read();
			t[1].tag=max(t[1].tag,x);
		}
//		for(int i=1;i<=n;i++)
//		{
//			printf("%d ",query(1,1,n,i));
//		}
//		cout<<"\n";
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",query(1,1,n,i));
	}
	cout<<"\n";
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}