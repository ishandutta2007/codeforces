#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 1000000007
#define ll long long
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
#define N 600005
#define ls (u<<1)
#define rs (u<<1|1)
int qpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=mul(ans,x);
		x=mul(x,x);
		y>>=1;
	}
	return ans;
}
int inv(int x)
{
	return qpow(x,mod-2);
}
int pw[N],ipw[N],i2=500000004;
int p[N],pos[N],val[N],n,Q,cnt;
pii v[N];
struct Node
{
	int pw,l,r,val;
};
Node merge(Node x,Node y)
{
	Node ans;
	ans.pw=mul(x.pw,y.pw);
	ans.l=add(x.l,mul(x.pw,y.l));
	ans.r=add(y.r,mul(y.pw,x.r));
	ans.val=add(add(mul(x.pw,y.val),mul(x.val,y.pw)),mul(x.l,y.r));
	return ans;
}
Node t[N*4];
int d[N];
void build(int u,int l,int r)
{
	if(l==r)
	{
		t[u].pw=1;
		return ;
	}
	int mid=(l+r)/2;
	build(ls,l,mid); build(rs,mid+1,r);
	t[u]=merge(t[ls],t[rs]);
}
void update(int u,int l,int r,int p,int opt)
{
	if(l==r)
	{
		if(opt==1) t[u]=(Node){2,d[l],d[l],0};
		else t[u]=(Node){1,0,0,0};
		return ;
	}
	int mid=(l+r)/2;
	if(p<=mid) update(ls,l,mid,p,opt);
	else update(rs,mid+1,r,p,opt);
	t[u]=merge(t[ls],t[rs]);
}
void print()
{
	printf("%d\n",mul(t[1].val,ipw[n]));
	// for(int i=1;i<=7;i++)
	// {
		// printf("%d %d %d %d\n",t[i].pw,t[i].l,t[i].r,t[i].val);
	// }
}
signed main()
{
	pw[0]=1; for(int i=1;i<N;i++) pw[i]=add(pw[i-1],pw[i-1]);
	ipw[0]=1; for(int i=1;i<N;i++) ipw[i]=mul(ipw[i-1],i2);
	cin>>n;
	for(int i=1;i<=n;i++) p[i]=read(),v[++cnt]=mp(p[i],i);
	cin>>Q;
	for(int i=1;i<=Q;i++)
	{
		pos[i]=read(),val[i]=read();
		v[++cnt]=mp(val[i],i+n);
	}
	sort(v+1,v+cnt+1);
	for(int i=1;i<=n;i++) p[i]=lower_bound(v+1,v+cnt+1,mp(p[i],i))-v;
	for(int i=1;i<=Q;i++) val[i]=lower_bound(v+1,v+cnt+1,mp(val[i],i+n))-v;
	for(int i=1;i<=cnt;i++) d[i]=v[i].fir;
	// for(int i=1;i<=n;i++) printf("%d ",p[i]);
	build(1,1,cnt);
	for(int i=1;i<=n;i++) update(1,1,cnt,p[i],1);
	print();
	for(int i=1;i<=Q;i++)
	{
		update(1,1,cnt,p[pos[i]],0);
		p[pos[i]]=val[i];
		update(1,1,cnt,p[pos[i]],1);
		print();
	}
	return 0;
}


//