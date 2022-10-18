#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define INF 0x3fffffff
#define int long long
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
#define N 500005
#define ls (u<<1)
#define rs (u<<1|1)
int a[N],n,b[N];
int ans[N];
struct Node
{
	int sum,tag,minn;
};
Node t[N*4];
void pd(int u,int l,int r)
{
	int mid=(l+r)/2;
	if(t[u].tag)
	{
		t[ls].tag=t[u].minn=t[u].tag; t[ls].sum=t[u].tag*(mid-l+1);
		t[rs].tag=t[u].minn=t[u].tag; t[rs].sum=t[u].tag*(r-mid);
		t[u].tag=0;
	}
}
int qsum(int u,int l,int r,int L,int R)
{
	if(l>r) return 0;
	if(L<=l&&r<=R) return t[u].sum;
	pd(u,l,r);
	int mid=(l+r)/2,ans=0;
	if(mid>=L) ans+=qsum(ls,l,mid,L,R);
	if(mid<R) ans+=qsum(rs,mid+1,r,L,R);
	return ans;
}
int getpl(int u,int l,int r,int d)
{
	if(t[u].tag)
	{
		if(t[u].tag>=d) return r;
		else return l-1;
	}
	int mid=(l+r)/2;
	int x=getpl(rs,mid+1,r,d);
	if(x==mid) return getpl(ls,l,mid,d);
	return x;
}
void update(int u,int l,int r,int L,int R,int d)
{
	if(l>r) return ;
	if(L<=l&&r<=R)
	{
		t[u].tag=t[u].minn=d;
		t[u].sum=d*(r-l+1);
		return ;
	}
	pd(u,l,r);
	int mid=(l+r)/2;
	if(mid>=L) update(ls,l,mid,L,R,d);
	if(mid<R) update(rs,mid+1,r,L,R,d);
	t[u].sum=t[ls].sum+t[rs].sum;
	t[u].minn=min(t[ls].minn,t[rs].minn);
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) a[i]=read();
	update(1,1,n,1,n,INF);
	for(int i=n;i>=1;i--)
	{
		int pl=getpl(1,1,n,a[i]);
		update(1,1,n,i,pl,a[i]);
		ans[i]=qsum(1,1,n,i,n);
	}
	for(int i=1;i<=n;i++) b[i]=a[n-i+1];
	update(1,1,n,1,n,INF);
	for(int i=n;i>=1;i--)
	{
		int pl=getpl(1,1,n,b[i]);
		update(1,1,n,i,pl,b[i]);
		ans[n-i+1]+=qsum(1,1,n,i,n);
	}
	// for(int i=1;i<=n;i++) printf("%lld ",ans[i]); cout<<'\n';
	int maxn=0,maxp=0;
	for(int i=1;i<=n;i++)
	{
		if(ans[i]-a[i]>maxn)
		{
			maxn=ans[i]-a[i];
			maxp=i;
		}
	}
	int cur=INF;
	for(int i=maxp;i<=n;i++)
	{
		cur=min(cur,a[i]); ans[i]=cur;
	}
	cur=INF;
	for(int i=maxp;i>=1;i--)
	{
		cur=min(cur,a[i]); ans[i]=cur;
	}
	for(int i=1;i<=n;i++) printf("%lld ",ans[i]); cout<<'\n';
	return 0;
}