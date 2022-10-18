#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define fir first
#define sec second
#define mod 998244353
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define int long long
#define double __float128
mt19937 rnd(123456);
double abs(double x)
{
	if(x>0) return x;
	else return -x;
}
#define N 505
int n,x,c[N],d[N][N];
vector<pii> G[N];
void dfs(int rt,int u,int f,int dep)
{
	if(dep<=x) d[rt][u]=1;
	for(auto [v,w]:G[u])
	{
		if(v==f) continue;
		dfs(rt,v,u,dep+w);
	}
}
namespace N1
{
	int m,t;
	double a[N][N],b[N][N],ans[N];
	int id[N],p[N];
	const double eps=1e-9,inf=1e18;
	void pivot(int r,int c)
	{
		swap(id[r+n],id[c]);
		double t=-a[r][c]; a[r][c]=-1;
		for(int i=0;i<=n;i++) a[r][i]/=t;
		for(int i=0;i<=m;i++)
		{
			if(abs(a[i][c])>eps&&i!=r)
			{
				double t=a[i][c]; a[i][c]=0;
				for(int j=0;j<=n;j++) a[i][j]+=t*a[r][j];
			}
		}
	}
	int Main()
	{
		// cin>>n>>m>>t;
		m=n+2;
		// for(int i=1;i<=n;i++) b[0][i]=read();
		for(int i=1;i<=n;i++) b[0][i]=c[i]-1;
		int s=0; for(int i=1;i<=n;i++) s+=c[i];
		/*
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++) b[i][j]=-read();
			b[i][0]=read();
		}
		*/
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++) b[i][j]=d[i][j];
			b[i][0]=-1;
		}
		for(int i=1;i<=n;i++) b[n+1][i]=-1,b[n+2][i]=1;
		b[n+1][0]=s,b[n+2][0]=-s;
		for(int i=1;i<=m;i++) p[i]=i;
		shuffle(p+1,p+m+1,rnd);
		for(int i=0;i<=m;i++) for(int j=0;j<=n;j++) a[i][j]=b[p[i]][j];
		for(int i=1;i<=n;i++) id[i]=i;
		while(1)
		{
			int r=0,c=0; double mn=-eps;
			for(int i=1;i<=m;i++) if(a[i][0]<mn) mn=a[i][0],r=i;
			if(!r) break;
			mn=inf;
			for(int i=1;i<=n;i++) if(a[r][i]>eps&&a[r][i]<mn) mn=a[r][i],c=i;
			if(!c) return -1;
			pivot(r,c);
		}
	//	for(int i=0;i<=m;i++) for(int j=0;j<=n;j++) printf("%.2lf%c",a[i][j]," \n"[j==n]);
		while(1)
		{
			int r=0,c=0; double mx=eps;
			for(int i=1;i<=n;i++) if(a[0][i]>mx) mx=a[0][i],c=i;
			if(!c) break;
			mx=-inf;
			for(int i=1;i<=m;i++) if(a[i][c]<-eps)
			{
				double tmp=a[i][0]/a[i][c];
				if(tmp>mx) mx=tmp,r=i;
			}
			if(!r) return -1;
			pivot(r,c);
		}
#undef double
//		printf("%.8Lf\n",(long double)a[0][0]);
		return -a[0][0]+eps;
	}
};
signed main()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++) c[i]=read();
	for(int i=1;i<n;i++) 
	{
		int u=read(),v=read(),w=read();
		G[u].eb(v,w),G[v].eb(u,w);
	}
	for(int i=1;i<=n;i++) dfs(i,i,0,0);
	cout<<N1::Main()<<endl;
	return 0;
}