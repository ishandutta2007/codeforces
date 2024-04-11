#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 1000000007
#define int long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
typedef pair<int,int> pii;
#define N 4005
vector<pii> G[N];
int dis[N][N];
int n,m,q;
int a[N];
void init()
{
	memset(dis,-1,sizeof(dis)); dis[0][1]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(dis[i][j]==-1) continue;
			for(auto [v,w]:G[j])
			{
				if(dis[i+1][v]<dis[i][j]+w) dis[i+1][v]=dis[i][j]+w;
			}
		}
	}
}
struct Node
{
	int k,b,fail;
};
Node b[N];
bool cmp(Node x,Node y)
{
	if(x.k!=y.k) return x.k<y.k;
	return x.b>y.b;
}
int st[N],tp;
double cross(int x,int y)
{
	return (double)(b[x].b-b[y].b)/(double)(b[x].k-b[y].k)+1e-6;
}
int calc(int i,int x)
{
	i=st[i];
	return -x*b[i].k+b[i].b;
}
signed main()
{
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		if(w>a[u]) a[u]=w;
		if(w>a[v]) a[v]=w;
		G[u].eb(v,w),G[v].eb(u,w);
	}
	init();
	int ans=0;
	for(int i=1;i<=n&&i<=q;i++)
	{
		int maxn=0;
		for(int j=1;j<=n;j++) if(dis[i][j]>maxn) maxn=dis[i][j];
		ans+=maxn;
	}
	ans%=mod;
	if(n>=q)
	{
		cout<<ans<<endl; return 0;
	}
	// for(int i=1;i<=n;i++)
	// {
		// for(int j=1;j<=n;j++) printf("%d ",dis[i][j]); cout<<"\n";
	// }
	// cout<<ans<<endl; return 0;
	// for(int i=1;i<=n;i++) printf("%d %d\n",a[i],dis[n][i]);
	for(int i=1;i<=n;i++)
	{
		b[i].k=-a[i],b[i].b=-inf;
		for(int j=1;j<=n;j++) if(dis[j][i]!=-1) b[i].b=max(b[i].b,dis[j][i]-a[i]*j);
	}
	sort(b+1,b+n+1,cmp);
	// for(int i=1;i<=n;i++) printf("%d %d\n",b[i].k,b[i].b); cout<<"\n";
	for(int i=1;i<=n;i++)
	{
		if(b[i].k==b[i-1].k) continue;
		if(b[i].fail) continue;
		// if(b[i].b+a[i]*n==-1) continue;
		if(tp<=1) st[++tp]=i;
		else
		{
			// while(tp>1&&cross(st[tp-1],st[tp])<=cross(st[tp-1],i)) tp--;
			while(tp>1&&(b[i].b-b[st[tp]].b)*(b[st[tp]].k-b[st[tp-1]].k)>=(b[st[tp]].b-b[st[tp-1]].b)*(b[i].k-b[st[tp]].k)) tp--;
			st[++tp]=i;
		}
	}
	// cout<<"\n";
	// for(int i=1;i<=tp;i++) printf("%d %d\n",b[st[i]].k,b[st[i]].b);
	int cur=n+1;
	// for(int i=1;i<=tp;i++)
	/*
	for(int i=tp;i>=1;i--)
	{
		int r=i!=1?(cross(st[i],st[i-1])-1):q;
		if(r>q) r=q;
		if(r<cur) continue;
		// printf("%d %d\n",cur,r);
		int R=(r-cur+1)*b[st[i]].b%mod-(r-cur+1)*(cur+r)/2%mod*b[st[i]].k%mod;
		R=add(R,mod);
		ans=add(ans,R%mod);
		cur=r+1;
		if(cur>q) break;
	}
	*/
	int las=n;
	for(int i=tp;i>1;i--)
	{
		int l=las+1,r=q;
		while(l<r)
		{
			int mid=(l+r+1)/2;
			if(calc(i,mid)>=calc(i-1,mid)) l=mid;
			else r=mid-1;
		}
		if(calc(i,l)>=calc(i-1,l))
		{
			int R=calc(i,las+1)%mod*(l-las)%mod;
			int S=b[st[i]].k*((l-las)*(l-las-1)/2%mod)%mod;
			ans=(ans+R-S)%mod;
			las=l;
		}
	}
	if(las<q)
	{
		int R=calc(1,las+1)%mod*(q-las)%mod;
		int S=b[st[1]].k*((q-las)*(q-las-1)/2%mod)%mod;
		ans=(ans+R-S)%mod;
	}
	cout<<(ans+mod)%mod<<endl;
	return 0;
}