#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define INF (int)(1e12)
#define ll long long
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
#define ls (u<<1)
#define rs (u<<1|1)
#define N 20005
struct Tree
{
	int t[N*4];
	void update(int u,int l,int r,int p,int v)
	{
		if(l==r)
		{
			t[u]=v;
			return ;
		}
		int mid=(l+r)/2;
		if(p<=mid) update(ls,l,mid,p,v);
		else update(rs,mid+1,r,p,v);
		t[u]=max(t[ls],t[rs]);
	}
	int query(int u,int l,int r,int L,int R)
	{
		if(L>R) return -INF;
		if(l>r) return -INF;
		if(L<=l&&r<=R) return t[u];
		int mid=(l+r)/2;
		int ans=-INF;
		if(mid>=L) ans=max(ans,query(ls,l,mid,L,R));
		if(mid<R) ans=max(ans,query(rs,mid+1,r,L,R));
		return ans;
	}
};
Tree t1,t2,t3;
int n,m,k;
int a[55][N],s[55][N];
int f[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) a[i][j]=read();
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) s[i][j]=s[i][j-1]+a[i][j];
	}
	for(int i=1;i<=m;i++)
	{
		t1.update(1,1,m,i,-INF);
		t2.update(1,1,m,i,-INF);
		t3.update(1,1,m,i,-INF);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j+k-1<=m;j++)
		{
			int R=max(t1.query(1,1,m,1,j-k),t1.query(1,1,m,j+k,m));
			int S=max(t2.query(1,1,m,j-k+1,j)+s[i][j-1],t3.query(1,1,m,j+1,j+k)-s[i][j+k-1]);
			f[j]=max(max(R,S),0LL);
		}
		for(int j=1;j+k-1<=m;j++)
		{
			f[j]+=s[i][j+k-1]-s[i][j-1]+s[i+1][j+k-1]-s[i+1][j-1];
			t1.update(1,1,m,j,f[j]);
			t2.update(1,1,m,j,f[j]-s[i+1][j+k-1]);
			t3.update(1,1,m,j,f[j]+s[i+1][j-1]);
		}
	}
	cout<<t1.query(1,1,m,1,m)<<endl;
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}