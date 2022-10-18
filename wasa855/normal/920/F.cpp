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
#define N 300005
#define M 1000005
int f[M];
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
	if(l>=L&&r<=R) return t[u].sum;
	int mid=(l+r)>>1;
	int ans=0;
	if(mid>=L) ans+=query(lson(u),l,mid,L,R);
	if(mid<R) ans+=query(rson(u),mid+1,r,L,R);
	return ans;
}
void update(int u,int l,int r,int L,int R)
{
	if(t[u].maxn<3) return ;
	if(l==r)
	{
		t[u].sum=f[t[u].sum];
		t[u].maxn=t[u].sum;
		return ;
	}
	int mid=(l+r)>>1;
	if(mid>=L) update(lson(u),l,mid,L,R);
	if(mid<R) update(rson(u),mid+1,r,L,R);
	t[u].sum=t[lson(u)].sum+t[rson(u)].sum;
	t[u].maxn=max(t[lson(u)].maxn,t[rson(u)].maxn);
}
void init()
{
	int lim=1000000;
	for(int i=1;i<=lim;i++)
	{
		for(int j=i;j<=lim;j+=i)
		{
			f[j]++;
		}
	}
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	init();
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) a[i]=read();
	build(1,1,n);
	int opt,l,r;
	for(int i=1;i<=m;i++)
	{
//		cout<<i<<endl;
		opt=read();
		if(opt==1)
		{
			l=read(),r=read();
			update(1,1,n,l,r);
		}
		if(opt==2)
		{
			l=read(),r=read();
			printf("%lld\n",query(1,1,n,l,r));
		}
	}
#ifndef ONLINE_JUDGE
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}