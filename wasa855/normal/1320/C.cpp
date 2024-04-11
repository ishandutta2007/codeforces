#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define int long long
#define INF (int)(2e9)
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int mul(int x,int y){return 1LL*x*y%mod;}
#define N 1000005
#define ls (u<<1)
#define rs (u<<1|1)
struct Th
{
	int x,y;
};
Th a[N],b[N];
bool cmp1(Th x,Th y)
{
	return x.x<y.x;
}
struct Node
{
	int x,y,z;
};
Node c[N];
bool cmp2(Node x,Node y)
{
	return x.x<y.x;
}
int n,m,p;
int d[N];
int dat[N*4],tag[N*4];
void build(int u,int l,int r)
{
	if(l==r)
	{
		if(d[l]==0) dat[u]=-INF;
		else dat[u]=-d[l];
		return ;
	}
	int mid=(l+r)/2;
	build(ls,l,mid);
	build(rs,mid+1,r);
	dat[u]=max(dat[ls],dat[rs]);
}
void pd(int u,int l,int r)
{
	dat[ls]+=tag[u],tag[ls]+=tag[u];
	dat[rs]+=tag[u],tag[rs]+=tag[u];
	tag[u]=0;
}
void update(int u,int l,int r,int L,int R,int d)
{
	if(L>R) return ;
	if(L<=l&&r<=R)
	{
		tag[u]+=d;
		dat[u]+=d;
		return ;
	}
	int mid=(l+r)/2;
	pd(u,l,r);
	if(mid>=L) update(ls,l,mid,L,R,d);
	if(mid<R) update(rs,mid+1,r,L,R,d);
	dat[u]=max(dat[ls],dat[rs]);
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	cin>>n>>m>>p;
	int mix=INF,miy=INF;
	for(int i=1;i<=n;i++)
	{
		a[i].x=read(),a[i].y=read();
		if(a[i].y<mix) mix=a[i].y;
	}
	sort(a+1,a+n+1,cmp1);
	for(int i=1;i<=m;i++)
	{
		b[i].x=read(),b[i].y=read();
		if(b[i].y<miy) miy=b[i].y;
		if(d[b[i].x]==0||b[i].y<d[b[i].x]) d[b[i].x]=b[i].y;
	}
	sort(b+1,b+m+1,cmp1);
	for(int i=1;i<=p;i++)
	{
		c[i].x=read(),c[i].y=read(),c[i].z=read();
	}
	sort(c+1,c+p+1,cmp2);
	int ans=-mix-miy,X=1e6,cur=0;
	build(1,1,X);
//	cout<<dat[1]<<endl;
	for(int i=1;i<=n;i++)
	{
		while(c[cur+1].x<a[i].x&&cur<p)
		{
			cur++;
			update(1,1,X,c[cur].y+1,X,c[cur].z);
		}
		int tmp=dat[1]-a[i].y;
		if(tmp>ans) ans=tmp;
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}