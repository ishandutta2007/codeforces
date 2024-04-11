#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define ll long long
#define INF (-(int)1e8)
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
#define N 200005
struct Node
{
	int l,r,x,y;
	bool operator < (const Node &o) const
	{
		if(l!=o.l) return l<o.l;
		if(r!=o.r) return r<o.r;
		if(x!=o.x) return x<o.x;
		if(y!=o.y) return y<o.y;
	}
};
int a[N];
int n,m;
map<pair<pii,pii>,int> f;
map<pair<pii,pii>,int> vis;
int cnt=0;
int sol(int l,int r,int x,int y)
{
	pair<pii,pii> xxx=mp(mp(l,r),mp(x,y));
	if(vis[xxx]) return f[xxx];
	vis[xxx]=1;
	if(l+1==r)
	{
		int cnt=a[l]+a[r];
		if(cnt==0&&x+y==0) return f[xxx]=0;
		if(cnt==1&&x+y==1) return f[xxx]=1;
		if(cnt==2&&x+y==2) return f[xxx]=1;
		return f[xxx]=INF;
	}
	// printf("%d %d %d %d : %d\n",l,r,x,y,++cnt);
	int mid=(l+r)/2;
	int a1=sol(l,mid,0,0);
	int b1=sol(l,mid,0,1);
	int c1=sol(l,mid,1,0);
	int d1=sol(l,mid,1,1);
	int a2=sol(mid+1,r,0,0);
	int b2=sol(mid+1,r,0,1);
	int c2=sol(mid+1,r,1,0);
	int d2=sol(mid+1,r,1,1);
	if(x==0&&y==0)
	{
		int R=max(max(a1+a2,a1+b2+2),max(a1+c2+2,a1+d2+3));
		int S=max(max(b1+a2+2,b1+b2+2),max(b1+c2+3,b1+d2+INF));
		int T=max(max(c1+a2+2,c1+b2+3),max(c1+c2+INF,c1+d2+INF));
		int U=max(max(d1+a2+3,d1+b2+INF),max(d1+c2+INF,d1+d2+INF));
		return f[xxx]=max(max(R,S),max(T,U));
	}
	if(x==0&&y==1)
	{
		int R=max(max(a1+a2+INF,a1+b2+2),max(a1+c2+2,a1+d2+3));
		int S=max(max(b1+a2+2,b1+b2+2),max(b1+c2+3,b1+d2+3));
		int T=max(max(c1+a2+2,c1+b2+3),max(c1+c2+INF,c1+d2+INF));
		int U=max(max(d1+a2+3,d1+b2+3),max(d1+c2+INF,d1+d2+INF));
		return f[xxx]=max(max(R,S),max(T,U));
	}
	if(x==1&&y==0)
	{
		int R=max(max(a1+a2+INF,a1+b2+INF),max(a1+c2+1,a1+d2+3));
		int S=max(max(b1+a2+INF,b1+b2+INF),max(b1+c2+3,b1+d2+3));
		int T=max(max(c1+a2+1,c1+b2+3),max(c1+c2+2,c1+d2+3));
		int U=max(max(d1+a2+3,d1+b2+3),max(d1+c2+3,d1+d2+INF));
		return f[xxx]=max(max(R,S),max(T,U));
	}
	if(x==1&&y==1)
	{
		int R=max(max(a1+a2+INF,a1+b2+INF),max(a1+c2+INF,a1+d2+3));
		int S=max(max(b1+a2+INF,b1+b2+INF),max(b1+c2+3,b1+d2+3));
		int T=max(max(c1+a2+INF,c1+b2+3),max(c1+c2+2,c1+d2+3));
		int U=max(max(d1+a2+3,d1+b2+3),max(d1+c2+3,d1+d2+3));
		return f[xxx]=max(max(R,S),max(T,U));
	}
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		a[read()]=1;
	}
	int R=sol(1,1<<n,0,0);
	int S=sol(1,1<<n,0,1);
	int T=sol(1,1<<n,1,0);
	int U=sol(1,1<<n,1,1);
	cout<<max(max(R,S+1),max(T+1,U+1))<<endl;
	return 0;
}