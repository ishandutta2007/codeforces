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
#define mod 998244353
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
typedef pair<int,int> pii;
#define N 5005
int t[N],x[N],f[N],g[N],h[N],n;
bool can[N][N];
bool cango(int a,int b) {return abs(x[a]-x[b])<=abs(t[a]-t[b]);}
int getdis(int a,int b) {return abs(x[a]-x[b]);}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) t[i]=read(),x[i]=read();
	for(int i=1;i<=n;i++)
	{
		can[i][i]=1;
		for(int j=i+1;j<=n;j++) can[i][j]=can[i][j-1]&&cango(j-1,j);
	}
	memset(g,-1,sizeof(g));
	memset(h,-1,sizeof(h));
	f[0]=1;
	for(int i=0;i<n;i++)
	{
		if(f[i])
		{
			if(cango(i,i+1))
			{
				f[i+1]=1;
				if(g[i+1]==-1) g[i+1]=t[i]+getdis(i,i+1);
				else g[i+1]=min(g[i+1],t[i]+getdis(i,i+1));
			}
			for(int j=i+2;j<=n;j++)
			{
				if(getdis(i,j)+getdis(j,i+1)<=t[i+1]-t[i])
				{
					if(can[i+1][j-1]) h[j]=1;
				}
			}
		}
		if(g[i]!=-1)
		{
			if(t[i+1]-g[i]>=getdis(i,i+1))
			{
				f[i+1]=1;
				if(g[i+1]==-1) g[i+1]=max(t[i],g[i]+getdis(i,i+1));
				else g[i+1]=min(g[i+1],max(t[i],g[i]+getdis(i,i+1)));
			}
			for(int j=i+2;j<=n;j++)
			{
				int T=max(t[i],g[i]+getdis(i,j));
				if(T+getdis(j,i+1)<=t[i+1])
				{
					if(can[i+1][j-1]) h[j]=1;
				}
			}
		}
		if(h[i]!=-1)
		{
			if(t[i+1]-t[i-1]>=getdis(i-1,i+1))
			{
				f[i+1]=1;
				if(g[i+1]==-1) g[i+1]=max(t[i],t[i-1]+getdis(i-1,i+1));
				else g[i+1]=min(g[i+1],max(t[i],t[i-1]+getdis(i-1,i+1)));
			}
			for(int j=i+2;j<=n;j++)
			{
				int T=max(t[i],t[i-1]+getdis(i-1,j));
				if(T+getdis(j,i+1)<=t[i+1])
				{
					if(can[i+1][j-1]) h[j]=1;
				}
			}
		}
	}
	// for(int i=1;i<=n;i++) printf("%d%c",f[i]," \n"[i==n]);
	// for(int i=1;i<=n;i++) printf("%d%c",g[i]," \n"[i==n]);
	// for(int i=1;i<=n;i++) printf("%d%c",h[i]," \n"[i==n]);
	if(f[n]||g[n]!=-1||h[n]!=-1) cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}