#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 100005
int lson(int x){return x*2;}
int rson(int x){return x*2+1;}
struct Seg
{
	int sum,maxn;
};
Seg t[N*4];
int a[N];
void build(int u,int l,int r)
{
	if(l==r)
	{
		t[u].sum=t[u].maxn=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(lson(u),l,mid);
	build(rson(u),mid+1,r);
	t[u].sum=t[lson(u)].sum+t[rson(u)].sum;
	t[u].maxn=max(t[lson(u)].maxn,t[rson(u)].maxn);
}
int query(int u,int l,int r,int L,int R)
{
//	printf("%d %d %d %d %d\n",u,l,r,L,R);
	if(l>=L&&r<=R) return t[u].sum;
	int mid=(l+r)>>1;
	int ans=0;
	if(mid>=L) ans+=query(lson(u),l,mid,L,R);
	if(mid<R) ans+=query(rson(u),mid+1,r,L,R);
	return ans;
}
void updmod(int u,int l,int r,int L,int R,int x)
{
	if(t[u].maxn<x) return ;
	if(l==r)
	{
//		cout<<l<<endl;
		t[u].sum%=x;
		t[u].maxn=t[u].sum;
		return ;
	}
	int mid=(l+r)>>1;
	if(mid>=L) updmod(lson(u),l,mid,L,R,x);
	if(mid<R) updmod(rson(u),mid+1,r,L,R,x);
	t[u].sum=t[lson(u)].sum+t[rson(u)].sum;
	t[u].maxn=max(t[lson(u)].maxn,t[rson(u)].maxn);
}
void update(int u,int l,int r,int p,int x)
{
	if(l==r)
	{
		t[u].sum=x;
		t[u].maxn=x;
		return ;
	}
	int mid=(l+r)>>1;
	if(mid>=p) update(lson(u),l,mid,p,x);
	else update(rson(u),mid+1,r,p,x);
	t[u].sum=t[lson(u)].sum+t[rson(u)].sum;
	t[u].maxn=max(t[lson(u)].maxn,t[rson(u)].maxn);
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) a[i]=read();
	build(1,1,n);
	int opt,l,r,x;
	for(int i=1;i<=m;i++)
	{
//		cout<<i<<endl;
		opt=read();
		if(opt==1)
		{
			l=read(),r=read();
			printf("%lld\n",query(1,1,n,l,r));
		}
		if(opt==2)
		{
			l=read(),r=read(),x=read();
			updmod(1,1,n,l,r,x);
		}
		if(opt==3)
		{
			l=read(),x=read();
			update(1,1,n,l,x);
		}
//		for(int j=1;j<=n;j++)
//		{
//			printf("%lld ",query(1,1,n,j,j));
//		}
//		cout<<"\n";
	}
#ifndef ONLINE_JUDGE
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}